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
/*

unsigned char tab[]={0x3F 0 ,0x06 1 ,0x5B 2 ,0x4F 3 ,0x66 4 ,0x6D 5 ,0x7D 6 ,0x07 7 ,
                           0x7F 8 ,0x6F 9 ,0x77 a（10） ,0x7C b（11） ,0x39 c（12） ,0x5E d（13） ,0x79 e（14） ,0x71 f（15） ,0x00 空（16）,0x63 C（17）, 57°（18） ,0x08 _(19),0xbd0.(20),0x86 1.(21),  0x73 p (30);


*/




                           
unsigned char taa[]={1023,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,
                           0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71,0x00,0x63,58};

unsigned char num[8];   //各个数码管显示的值  




#include <Wire.h>

#define BMP085_ADDRESS 0x77  // I2C address of BMP085

const unsigned char OSS = 0;  // Oversampling Setting

// Calibration values
int ac1;
int ac2;
int ac3;
unsigned int ac4;
unsigned int ac5;
unsigned int ac6;
int b1;
int b2;
int mb;
int mc;
int md;

// b5 is calculated in bmp085GetTemperature(...), this variable is also used in bmp085GetPressure(...)
// so ...Temperature(...) must be called before ...Pressure(...).
long b5; 













                   
 void setup ()
{
  pinMode(STB,OUTPUT);
  pinMode(CLK,OUTPUT);
  pinMode(DIO,OUTPUT); //让三个脚都是输出状态
  Serial.begin(9600);
  pinMode(MQ7,OUTPUT);



  Wire.begin();

 bmp085Calibration();
  
}


 void loop()
    {
  unsigned char i;
  init_TM1638();                             //初始化TM1638
  for(i=0;i<8;i++)
  Write_DATA(i<<1,tab[0]);                 //初始化寄存器 
  while(1)
  {

 /*
  Write_DATA(0,tab[28]);                 //初始化寄存器 
    Write_DATA(2,tab[29]);                 //初始化寄存器 
      Write_DATA(4,tab[22]);                 //初始化寄存器 
        Write_DATA(6,tab[23]);                 //初始化寄存器 
          Write_DATA(8,tab[24]);                 //初始化寄存器 
           Write_DATA(10,tab[25]);                 //初始化寄存器 
             Write_DATA(12,tab[26]);                 //初始化寄存器 
               Write_DATA(14,tab[30]);                 //初始化寄存器 
               Serial.println(tab[g],HEX);
               g++;
delay(1000);*/

displayday();
delay(1000);
displaytimeall();
delay(500);
displaypressure();
delay(500);
displaytem();
delay(500);




/*
displaynum(20,21,22,23,24,25,26,27);


/*

float temperature = bmp085GetTemperature(bmp085ReadUT()); //MUST be called first
  float pressure = bmp085GetPressure(bmp085ReadUP());
  float atm = pressure / 101325; // "standard atmosphere"
  float altitude = calcAltitude(pressure); //Uncompensated caculation - in Meters 

  Serial.print("Temperature: ");
  Serial.print(temperature, 2); //display 2 decimal places
  Serial.println("deg C");

  Serial.print("Pressure: ");
  Serial.print(pressure, 0); //whole number only.
  Serial.println(" Pa");

  Serial.print("Standard Atmosphere: ");
  Serial.println(atm, 4); //display 4 decimal places

  Serial.print("Altitude: ");
  Serial.print(altitude, 2); //display 2 decimal places
  Serial.println(" M");

  Serial.println();//line break

  delay(1000); //wait a second and get values again.


*/



































  }

 
}
