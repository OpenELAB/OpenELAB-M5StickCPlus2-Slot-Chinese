&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;__Hi👋__，欢迎来到这个关于使用 M5StickC Plus2 实现超酷老虎机🎰项目的教程！这次的项目系列将分为三个部分，而今天你将进入第一个部分，重点介绍如何搭建项目、运行代码以及实现核心功能。  
  接下来，将通过以下几个步骤📜，带你深入源码，轻松上手这个项目！准备好了吗？让我们开始吧🚀！  
- 📝 项目简介
- ✨ 功能特点
- 🏗 项目结构
- 🚀 安装与运行
- 🔧 使用说明
- 🔮 下期预告
  
[演示视频📺]()
# M5StickCPlus2_Slot 项目
## 项目简介:
这个项目通过使用 M5StickC Plus2 打造了一个迷你版的老虎机🎰，玩家只需轻按按钮即可启动转盘，并逐列停止，享受刺激的游戏体验！项目采用了 1.14 英寸的TFT显示屏，展现了五列炫酷的转盘，每列包含 10 个不同的图标，转盘旋转时充满动感🎡。  
  通过 M5StickC Plus2 的按钮交互，玩家可以轻松控制游戏的启动与停止，仿佛置身于真实的老虎机🎮。这个项目不仅展示了 M5StickC Plus2 在图形显示和硬件控制方面的强大能力，还为玩家提供了乐趣满满的互动体验，是硬件开发和游戏开发爱好者绝佳的学习和参考项目💡！

## 功能特点
- 📏 体积小巧：轻便的设计，适合随身携带，轻松搭建。
- 🎉 趣味十足：互动性强，仿佛置身于真实的老虎机游戏世界。
- 🔋 功耗低：高效能低功耗，延长设备使用时间
## 项目结构
``` 
│──  README.md                # 项目说明文件
│──  M5StickCPlus2_slot       # 源代码文件夹
  │──  M5StickCPlus2_slot.ino   # 源代码文件
  │──  Slot.cpp                 # Slot功能实现文件
  │──  SLot.h                   # Slot功能定义文件
  │──  image                    # 图片素材文件夹
    │──  slot_bar.h               # esp32图标
    │──  slot_cherry.h            # 樱桃图标
    │──  slot_lemon.h             # 柠檬图标 
    │──  slot_openelab.h          # OpenELAB logo
    │──  slot-orange.h            # 橘子图标
    │──  slot_seven.h             # 数字7图标
    │──  slot_symbols.h           # 图标数据
```
## 安装与运行

### 先决条件
软件依赖：__Arduino IDE__、__VScode__ or __text__ 等   
硬件要求：__USB-C数据线__、__M5StickCPlus2__ 等  
依赖要求：__M5StickCPlus2库__、__Arduino库__
### Arduino IDE 安装步骤
```
链接：稍后上传
```
### 安装依赖
1、安装好Arduino IDE后，打开Arduino设置，复制M5开发板链接到图示箭头处后点击OK保存
```
https://static-cdn.m5stack.com/resource/arduino/package_m5stack_index.json
```
![QQ_1726105473838](https://github.com/user-attachments/assets/367bd060-13ab-4eda-9a43-13fbc0250580)  
  
2、打开Tools->Board->Boards Manager  

![QQ_1726105693629](https://github.com/user-attachments/assets/e70b4f19-c21a-4ea5-80e2-4d150b54a35f)  
  
3、搜索M5Stack，并选择安装，本主机已经安装所以不再重复安装  

![QQ_1726105854495](https://github.com/user-attachments/assets/11b18b6c-c8db-4ea4-b209-d22dd26eebbe) 

4、选择开发版，Tools->Board->M5Stack Arduino->M5StickCPlus2  

![QQ_1726106317846](https://github.com/user-attachments/assets/203d874b-f316-4ae7-827b-2e01493ce08d)


5、接下来安装M5StickCPlus2库，选择Tools->Manage Libraries，搜索M5StickCPlus2，再选择安装，此处已经安装就不再重复安装。

![QQ_1726106703496](https://github.com/user-attachments/assets/312bc9e1-521c-479e-831a-a3c22e45a6ec)  

### 编译运行
1、完成安装依赖后，打开好下载的压缩包  

![QQ_1726107516108](https://github.com/user-attachments/assets/cb2362f7-1871-418e-94dd-92ddfe7284b7)  

2、使用USB-C将Plus2连接至电脑，选择Tools->Port选择自己的端口  

![QQ_1726107673971](https://github.com/user-attachments/assets/17f0392a-b753-4aba-946c-ede75ba9092f)  

3、点击编译，待编译完成后再点击上传  

![QQ_1726107957719](https://github.com/user-attachments/assets/c1f953ad-5355-44e8-af0c-ac5da7542aa6)  

## 使用说明
- ### 图片顺序、个数
老虎机共五列，每一列都可以放置 10 个图标，而且你可以随意调整它们的顺序！💡目前，我们已经准备了 6 个 48x48 像素的素材图标，它们的 RGB565 十六进制数据已经在代码里了，分别对应 slot_symbols 数组中的 0 到 5 号元素。如果你想调整每列的图标顺序和数量，只需要轻松修改 symbolIndices 数组中的数字，就能改变每一列的图标显示效果！🔧🎨  

![QQ_1726108827608](https://github.com/user-attachments/assets/45b5878d-3624-47b5-a671-fc40937d1898)

- ### 列与列、图与图的间隔
通过更改PAD_X以及PAD_Y可以更改列与列、图与图的间隔，通常默认是2，0  

![QQ_1726109192019](https://github.com/user-attachments/assets/3e14c412-8342-486d-ba00-b6a0f4d357ac)

- ### 转盘转动速度、停止减小速度
```
#define Speed_MAX 800//老虎机旋转的最高速度
#define Speed_MIN 50//老虎机旋转最低速
#define Acceleration_MAX 12 //老虎机加速时的加速度
#define Acceleration_MIN -20//老虎机减速时的加速度
```
  ![QQ_1726109492610](https://github.com/user-attachments/assets/aaa6b4a0-79b1-491a-8dbd-ca76cc8c1eee)

## 下期预告
下期将详细介绍怎么更改老虎机的图片，我们会通过对图片取模获得图片的十六进制参数，并调整成我们想要的格式，然后在老虎机上呈现出我们所需要的图片 __敬请期待!!!__  

![QQ_1726122393803](https://github.com/user-attachments/assets/71507de5-dad0-4688-84bf-56cc25878e35)

## 如何联系维护者或开发者
__OpenELAB:__   
[![OpenELAB](https://private-user-images.githubusercontent.com/180402004/366379735-e03723c2-c213-421f-a517-e482f67f3660.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MjYwNDU2NTIsIm5iZiI6MTcyNjA0NTM1MiwicGF0aCI6Ii8xODA0MDIwMDQvMzY2Mzc5NzM1LWUwMzcyM2MyLWMyMTMtNDIxZi1hNTE3LWU0ODJmNjdmMzY2MC5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQwOTExJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MDkxMVQwOTAyMzJaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT1mOWE1NGE1ZDhhOTNhMjJmNTRmZmMxYTk1YzA3MDNmNTY5MzQ1NGZkNDEzMDk4OTM4MTdjM2I1ZGNmMDYzODY2JlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.qnnW0ggDBwf9vP7yfAQU-oMGHnGr0-FJKsb38NDInco)](https://openelab.io)  
__YouTube:__  
[![youtube_logo_200x150](https://private-user-images.githubusercontent.com/180402004/366385591-b212d544-4584-49ac-970d-811a87f367bc.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MjYwNDY1MzAsIm5iZiI6MTcyNjA0NjIzMCwicGF0aCI6Ii8xODA0MDIwMDQvMzY2Mzg1NTkxLWIyMTJkNTQ0LTQ1ODQtNDlhYy05NzBkLTgxMWE4N2YzNjdiYy5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQwOTExJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MDkxMVQwOTE3MTBaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT0yNDA0OTllOWFiZTk3ZGM4YjUxMGYxOGFkNmViODYxMTk1YWQ1Nzc0MTdlZDRiNWZjZmI0NjU5ZDg1NmIwMzcxJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.A9yqUAA24OPl3lSMY1O71Oa8Jn33ICzTJqlOhf4altc)](https://www.youtube.com/@OpenELAB)  
__X :__  
[ ![X_logo_150x150](https://private-user-images.githubusercontent.com/180402004/366386947-f22637e9-361e-4889-99c5-a940dae19ca8.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MjYwNDY3MDcsIm5iZiI6MTcyNjA0NjQwNywicGF0aCI6Ii8xODA0MDIwMDQvMzY2Mzg2OTQ3LWYyMjYzN2U5LTM2MWUtNDg4OS05OWM1LWE5NDBkYWUxOWNhOC5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQwOTExJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MDkxMVQwOTIwMDdaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT1hNjgzMjVjZmQwOTk2ZTA5ZWJmYmUzOWNjZjQwODUzYmI2YzUzMDk0ZDljMjlmOWE2ZmUyYTczMmM5MWNiMjNlJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.Xl_OOo_alC9lAL1wOYwLariKbjmPQba5MO6agG-ECmQ)
](https://twitter.com/openelabio)  
__FaceBook:__  
[![facebook_logo_cropped_150x150](https://private-user-images.githubusercontent.com/180402004/366389274-b03aa857-c5d9-4bed-b65c-ddbd0e674111.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MjYwNDcwMjgsIm5iZiI6MTcyNjA0NjcyOCwicGF0aCI6Ii8xODA0MDIwMDQvMzY2Mzg5Mjc0LWIwM2FhODU3LWM1ZDktNGJlZC1iNjVjLWRkYmQwZTY3NDExMS5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQwOTExJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MDkxMVQwOTI1MjhaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT1lOWUyMDA4ZThlMmU3N2Y5NzE5NDVlOGMwNTRlNTcwODA0NmZjZGU4M2ZhYmNhYWQ0ZTA1NTVkNTE4Yjk0YzQwJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.magjk7X-wGsifZ7FlRZfq5J4-EoMdjJZsNK5e0g4CXQ)](https://www.facebook.com/profile.php?id=61559154729457)  

__源码改自于__
[M5StickCPlus](https://github.com/Sarah-C/M5StickC_Plus_Slot_Machine)

