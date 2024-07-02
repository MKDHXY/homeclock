


void TM1638_Write(unsigned char DATA)     //写数据函数
{
  unsigned char i;
        pinMode(DIO,OUTPUT);
  for(i=0;i<8;i++)
  {
            digitalWrite(CLK,LOW);
      if(DATA&0X01)
               digitalWrite(DIO,HIGH);
      else
               digitalWrite(DIO,LOW);
      DATA>>=1;
            digitalWrite(CLK,HIGH);
  }
}
unsigned char TM1638_Read(void)         //读数据函数
{
  unsigned char i;
  unsigned char temp=0;;  
        pinMode(DIO,INPUT);//设置为输入
  for(i=0;i<8;i++)
  {
        temp>>=1;
            digitalWrite(CLK,LOW);
        if(digitalRead(DIO)==HIGH)
          temp|=0x80;
            digitalWrite(CLK,HIGH);
               
  }
  return temp;
}
void Write_COM(unsigned char cmd)   //发送命令字
{
        digitalWrite(STB,LOW);
  TM1638_Write(cmd);
        digitalWrite(STB,HIGH);
}
unsigned char Read_key(void)
{
  unsigned char c[4],i,key_value=0;
        digitalWrite(STB,LOW);
  TM1638_Write(0x42);              //读键扫数据 命令
  for(i=0;i<4;i++)    
    {
            c[i]=TM1638_Read();
        }
        digitalWrite(STB,HIGH);                    //4个字节数据合成一个字节
  for(i=0;i<4;i++)
  {
            key_value|=c[i]<<i;
        } 
        for(i=0;i<8;i++)
        {
            if((0x01<<i)==key_value)
            break;
        }
  return i;
}
void Write_DATA(unsigned char add,unsigned char DATA)   //指定地址写入数据
{
  Write_COM(0x44);
        digitalWrite(STB,LOW);
  TM1638_Write(0xc0|add);
  TM1638_Write(DATA);
        digitalWrite(STB,HIGH);
}
void Write_allLED(unsigned char LED_flag)         //控制全部LED函数，LED_flag表示各个LED状态
{
  unsigned char i;
  for(i=0;i<8;i++)
  {
      if(LED_flag&(1<<i))
        Write_DATA(2*i+1,1);
      else
        Write_DATA(2*i+1,0);
        }
}

//TM1638初始化函数
void init_TM1638(void)
{
  unsigned char i;
  Write_COM(0x88);       //亮度 (0x88-0x8f)8级亮度可调
  Write_COM(0x40);       //采用地址自动加1
        digitalWrite(STB,LOW);               //
  TM1638_Write(0xc0);    //设置起始地址
  for(i=0;i<16;i++)    //传送16个字节的数据
    TM1638_Write(0x00); 

        digitalWrite(STB,HIGH);
}
