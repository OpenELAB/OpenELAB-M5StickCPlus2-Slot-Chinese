#include <M5StickCPlus2.h>
#include "Slot.h"

#ifndef _countof
#define _countof(a) (sizeof(a) / sizeof(a[0]))
#endif

#define LOOP_WAIT 30
#define FLUSH_DELAY 100
#define FLUSH_COUNT 3

Slot slots[SLOT_COUNT];
const int symbolIndices[] = { 2, 4, 5, 0, 3, 4, 2, 5, 3, 1, 0};//列图标显示顺序  每一列显示的图标相同

enum SlotsState { SLOTS_INIT, SLOTS_START, SLOTS_STOP = SLOT_COUNT + 1, SLOTS_FLUSH };
int state = SLOTS_INIT;//老虎机状态值     设置为初始状态

//
// setup()//初始化函数
//

void setup() {
   M5.begin();
  M5.Lcd.setRotation(3);
  M5.Lcd.fillScreen(TFT_BLACK);//设置屏幕背景色为黑色
  M5.Lcd.setSwapBytes(true);

  Slot::initShadow();//初始化阴影
  Slot::setReel(symbolIndices, _countof(symbolIndices));//设置初始转盘
  for (int i = 0; i < SLOT_COUNT; i++) {
    slots[i].init(i, i * SLOT_COUNT);
    slots[i].draw();
  }
}

//
// loop()//主函数，该函数中由于需要时刻刷新老虎机LCD所以不能出现类似于delay_ms的延时
//

void loop() {
  unsigned long tick = millis();//获得当前心跳值
  static unsigned long flushTick;
  static int flushCount;

  M5.update();
  if (M5.BtnA.wasPressed()) {//按键触发
    if (state == SLOTS_INIT) {//若处于初始状态 开始转动老虎机
      for (int i = 0; i < SLOT_COUNT; i++) {
        slots[i].start();
      }
      state++;
    } else if (state < SLOTS_STOP) {//处于开启状态且不处于暂停状态，停止一列
      slots[state - 1].stop();
      state++;//递增到第二列
    }
  }
  if (state == SLOTS_STOP) {//老虎机处于停止状态，初始化相关数据，使得老虎机回到初始状态
    int symbol = -1;
    bool stopAll = true;
    for (int i = 0; i < SLOT_COUNT; i++) {
      int n = slots[i].getSymbol();
      if (n == -1) {
        stopAll = false;
      } else {
        symbol = (n == symbol || symbol == -1) ? n : -2;
      }
    }
    if (stopAll) {
      if (symbol >= 0) {
        flushTick = tick;
        flushCount = 0;
        state = SLOTS_FLUSH;
      } else {
        state = SLOTS_INIT;
      }
    }
  }
 
  if (state == SLOTS_FLUSH) {//当所有列全部停止
    if (tick >= flushTick + FLUSH_DELAY) {
      flushTick = tick;
      for (int i = 0; i < SLOT_COUNT; i++) {
        slots[i].flush((flushCount & 1) ? TFT_WHITE : TFT_BLUE);//若所有列出现图标相同，背景显示蓝色否则不变
      }
      if (++flushCount >= FLUSH_COUNT * 2) {
        state = SLOTS_INIT;
      }
    }
  }

  for (int i = 0; i < SLOT_COUNT; i++) {//刷新LCD当前画面显示
    if (slots[i].update()) {
      slots[i].draw();
    }
  }

  int ms = millis() - tick;
  if (ms < LOOP_WAIT) {
    delay(LOOP_WAIT - ms);
  }
}
