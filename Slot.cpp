//
// Slot.cpp
//

#include "Slot.h"
#include "images/slot_symbols.h"

#ifndef _countof
#define _countof(a) (sizeof(a) / sizeof(a[0]))
#endif

const int *Slot::symbolIndices;
int Slot::reelLength;
int Slot::reelHeight;
int Slot::shadowHeight;
uint8_t *Slot::shadowBrigtness;
uint16_t *Slot::buffer;

#define PAD_X 2//列间隔
#define PAD_Y 0//图标间隔

void Slot::init(int unit, int _index) {
	index = _index;
	posX = (M5.Lcd.width() - (SYM_WIDTH * SLOT_COUNT + PAD_X * (SLOT_COUNT - 1))) / 2 + unit * (SYM_WIDTH + PAD_X);
	height = M5.Lcd.height() - PAD_Y * 2;
	degree = (float)(index * 360 / reelLength);
	vel = acc = 0;
	state = SLOT_INIT;
}

void Slot::setReel(const int *_symbolIndices, int _reelLength) {//设置老虎机的滚动
	symbolIndices = _symbolIndices;
	reelLength = _reelLength;
	reelHeight = SYM_HEIGHT * reelLength;
}

void Slot::draw() {//关键函数，对老虎机图标进行绘制
	int offset = (int)roundf(degree * reelHeight / 360.f);
	offset = offset + SYM_HEIGHT / 2 - height / 2;
	int x = posX;
	int y = 0;
	int shadowY = 0;
	while (y < height) {
		if (offset < 0) {
			offset += reelHeight;
		} else if (offset >= reelHeight) {
			offset -= reelHeight;
		}
		int symbolIndex = offset / SYM_HEIGHT;
		int symbolY = offset % SYM_HEIGHT;
		int h = SYM_HEIGHT - symbolY;
		if (y + h >= height) {
			h = height - y;
		}
		if (y < height - shadowHeight && y + h > height - shadowHeight) {
			h = height - shadowHeight - y;
		}
		const uint16_t* data = slot_symbols[symbolIndices[symbolIndex]] + symbolY * SYM_WIDTH;//从image文件中读取图片数据到data
		if (y < shadowHeight || y >= height - shadowHeight) {
			int sh = shadowHeight - shadowY;
			if (sh > h) {
				sh = h;
			}
			uint16_t *q = buffer;
			for (int i = 0; i < SYM_WIDTH * sh; i++) {
				int sy = i / SYM_WIDTH;
				*q++ = darker(*data++, shadowBrigtness[(y < shadowHeight) ? sy + shadowY : shadowHeight - sy - shadowY - 1]);
			}
			M5.Lcd.pushImage(x, y + PAD_Y, SYM_WIDTH, sh, buffer);
			shadowY += sh;
			h = sh;
		} else {
			shadowY = 0;
			M5.Lcd.pushImage(x, y + PAD_Y, SYM_WIDTH, h, data);//绘制图像
		}
		offset += h;
		y += h;
	}
}

void Slot::flush(uint16_t bgColor) {
	int x = posX;
	int y = (M5.Lcd.height() - SYM_HEIGHT) / 2;
	Serial.print("flush:");Serial.println(index);
	const uint16_t* data = slot_symbols[symbolIndices[index]];
	if (bgColor == TFT_WHITE) {
		M5.Lcd.pushImage(x, y, SYM_WIDTH, SYM_HEIGHT, data);
	} else {
		M5.Lcd.fillRect(x, y, SYM_WIDTH, SYM_HEIGHT, bgColor);
		M5.Lcd.pushImage(x, y, SYM_WIDTH, SYM_HEIGHT, data, TFT_WHITE);
	}
}

void Slot::start(int _acc, int _maxVel) {//启动老虎机
	acc = _acc;
	maxVel = _maxVel;
	tick = millis();
	state = SLOT_START;//设置老虎机状态
	index = -1;
}

void Slot::stop(int _acc, int _minVel) {//停止某一列老虎机
	acc = _acc;
	minVel = _minVel;
	state = SLOT_STOP;
}

bool Slot::update() {//更新老虎机当前显示
	if (state == SLOT_INIT) return false;
	vel += acc;
	if (vel > maxVel) {
		vel = maxVel;
	} else if (state == SLOT_STOP) {
		if (vel <= minVel) {
			state = SLOT_DRIFT;
			vel = minVel;
			acc = 0;
		}
	}
	unsigned long t = millis();
	if (vel != 0) {
		int ms = (int)(t - tick);
		degree -= (float)vel * ms / 1000.f;
		if (degree < 0.0f) {
			degree += 360.f;
		} else if (degree > 360.f) {
			degree -= 360.f;
		}
		if (state == SLOT_DRIFT) {
			int fin = 360 / reelLength;
			int d = (int)roundf(degree) % fin;
			if (d <= 2 || d >= fin - 2) {
				index = (int)roundf(degree / fin);
				if (index >= reelLength) {
					index = 0;
				}
				degree = (float)(index * fin);
				vel = 0;
				state = SLOT_INIT;
			}
		}
	}
	tick = t;
	return true;
}

//
// edge shadow
//
void Slot::initShadow(int _shadowHeight) {//初始化阴影
	shadowHeight = _shadowHeight;
	shadowBrigtness = (uint8_t*)malloc(shadowHeight);
	buffer = (uint16_t*)malloc(SYM_WIDTH * shadowHeight * sizeof(uint16_t));
	for (int i = 0; i < shadowHeight; i++) {
		uint8_t b =  calcBrightness((float)i / shadowHeight);
		shadowBrigtness[i] = b;
		Serial.println(b);
	}
}

uint16_t Slot::darker(uint16_t rgb, uint8_t brightness) {//获取颜色参数
	uint16_t r = ((rgb & 0xF800) >> 8) * brightness / 255;
	uint16_t g = ((rgb & 0x07E0) >> 3) * brightness / 255;
	uint16_t b = ((rgb & 0x001F) << 3) * brightness / 255;
	return ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3);
}

uint8_t Slot::calcBrightness(float step) {
	return (uint8_t)(sigmoid(step) / sigmoid(1.0f) * 255.f);
}

// https://blog.eyewire.org/ease-out-the-half-sigmoid-xpost/
float Slot::sigmoid(float t) {
	const float k = 4.0f;
	return (1.0f / (1.0f + exp(-k * t))) - 0.5f;
}
