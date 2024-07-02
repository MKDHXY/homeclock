//©MKDHXY  WWW.SpaceAero.space






#include <MyRealTimeClock.h> //导入DS1302驱动库
MyRealTimeClock myRTC(6, 7, 8); // 分配数字引脚
#define  DATA_COMMAND  0X40
#define DISP_COMMAND  0x80
#define ADDR_COMMAND  0XC0
int timeg=0;
int temg=0;
//TM1638模块引脚定义
int DIO = 2;
int CLK = 3;
int STB = 4; //这里定义了那三个脚
int MQ7 = 5;
int i=0;
//共阴数码管显示代码
unsigned char tab[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,
                           0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71,0x00,0x63,57,0x08,0xbf,0x86,0xdb,0xcf,0xe6,1005,1021,0x87,1023,1007,0x73};

int disp0,disp1,disp2,disp3,disp4,disp5,disp6,disp7=16;
