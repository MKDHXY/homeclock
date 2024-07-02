/*
  【Arduino】168种传感器模块系列实验（资料代码+仿真编程+图形编程）
  程序一：Arduino 上的 DS1302 实时时钟
  下载驱动库：https://playground.arduino.cc/Main/DS1302/
  或：https://www.14core.com/the-ds1302-real-time-clock-on-arduino/
  实验接线：
  DS1302  uno
  VCC    →+5V/3.3V
  GND    →GND
  CLK    →6
  DAT    →7
  RST    →8
*/




  /* 以特定格式设置当前时间和日期
    |第00秒| 第30分钟|11小时|12或24格式|第28天|第03月|2022年|
    时钟以 24 小时或 12 小时格式运行
  */
 // myRTC.setDS1302Time(30, 41, 00, 24 , 04, 02, 2024);


void displaytime() {
 // displayclean();
  // 允许更新时间变量/访问单个元素。
  myRTC.updateTime();

  Serial.print("当前日期/时间：");
  Serial.print(myRTC.dayofmonth); // 元素 1
  Serial.print("/");
  Serial.print(myRTC.month); // 元素 2
  Serial.print("/");
  Serial.print(myRTC.year); // 元素 3
  Serial.print(" ");
  Serial.print(myRTC.hours); // 元素 4
  Serial.print(":");
  Serial.print(myRTC.minutes); // 元素 5
  Serial.print(":");
  Serial.println(myRTC.seconds); // 元素 6


  disp0=myRTC.hours/10;
  disp1=myRTC.hours-10*disp0;
  disp2=16;
  disp3=myRTC.minutes/10;
  disp4=myRTC.minutes-10*disp3;
  disp5=16;
  disp6=myRTC.seconds/10;
  disp7=myRTC.seconds-10*disp6;


  displaynum(disp0,disp1,disp2,disp3,disp4,disp5,disp6,disp7);
/*
 if(disp7+1<10)
  {
    timeg+1;
    Write_DATA(14,tab[disp7]);                 //初始化寄存器 
    delay(1000);
  }else{delay(4000);}
  if(disp7+1<10)
  {
    timeg+1;
    Write_DATA(14,tab[disp7]);                 //初始化寄存器 
    delay(1000);
    }else{delay(500);}
  if(disp7+1<10)
  {
    timeg+1;
    Write_DATA(14,tab[disp7]);                 //初始化寄存器 
    delay(1000);
    }else{delay(500);}
  if(disp7+1<10)
  {
    timeg+1;
    Write_DATA(14,tab[disp7]);                 //初始化寄存器 
    delay(1000);
    }else{delay(500);}*/
  


}


void displaytimeall(){
  displaytime();
  delay(990);
  displaytime();
    delay(990);
  displaytime();
  delay(990);  
   displaytime();
  delay(990);
  displaytime();
    delay(990); 
  
  
  }





  void displayday(){
    
    
      myRTC.updateTime();

  Serial.print("当前日期/时间：");
  Serial.print(myRTC.dayofmonth); // 元素 1
  Serial.print("/");
  Serial.print(myRTC.month); // 元素 2
  Serial.print("/");
  Serial.print(myRTC.year); // 元素 3
  Serial.print(" ");
  Serial.print(myRTC.hours); // 元素 4
  Serial.print(":");
  Serial.print(myRTC.minutes); // 元素 5
  Serial.print(":");
  Serial.println(myRTC.seconds); // 元素 6


  disp0=myRTC.year/10-200;
  disp1=myRTC.year-2020;
  disp2=19;
  disp3=myRTC.month/10;
  disp4=myRTC.month-10*disp3;
  disp5=19;
  disp6=myRTC.dayofmonth/10;
  disp7=myRTC.dayofmonth-10*disp6;


  displaynum(disp0,disp1,disp2,disp3,disp4,disp5,disp6,disp7);
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    }
