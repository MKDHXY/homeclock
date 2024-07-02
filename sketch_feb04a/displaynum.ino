void displayclean()
{
  disp0=16;
  disp1=16;
  disp2=16;
  disp3=16;
  disp4=16;
  disp5=16;
  disp6=16;
  disp7=16;
  displaynum(disp0,disp1,disp2,disp3,disp4,disp5,disp6,disp7);
  delay(400);
  }

void displaynum(int disp0,int disp1,int disp2,int disp3,int disp4,int disp5,int disp6,int disp7)
  {
  Write_DATA(0,tab[disp0]);                 //初始化寄存器 
    Write_DATA(2,tab[disp1]);                 //初始化寄存器 
      Write_DATA(4,tab[disp2]);                 //初始化寄存器 
        Write_DATA(6,tab[disp3]);                 //初始化寄存器 
          Write_DATA(8,tab[disp4]);                 //初始化寄存器 
           Write_DATA(10,tab[disp5]);                 //初始化寄存器 
             Write_DATA(12,tab[disp6]);                 //初始化寄存器 
               Write_DATA(14,tab[disp7]);                 //初始化寄存器 


  }


void displaypressure()
{
  //displayclean();
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
  disp0=pressure/100000;
  disp1=(pressure/10000)-10*disp0;
  disp2=(pressure/1000)-100*disp0-10*disp1;
  disp3=(pressure/100)-1000*disp0-100*disp1-10*disp2;
  disp4=(pressure/10)-10000*disp0-1000*disp1-100*disp2-10*disp3;
  disp5=(pressure/1)-100000*disp0-10000*disp1-1000*disp2-100*disp3-10*disp4;
  disp6=30;
  disp7=10;
  Serial.print("Standard Atmosphere: ");
  Serial.println(atm, 4); //display 4 decimal places

  Serial.print("Altitude: ");
  Serial.print(altitude, 2); //display 2 decimal places
  Serial.println(" M");

  Serial.println();//line break

  displaynum(disp0,disp1,disp2,disp3,disp4,disp5,disp6,disp7);
  

  
    if(pressure>95000){       Write_DATA(2*0+1,1);}
  if(pressure>97000){Write_DATA(2*1+1,1);}
  if(pressure>98000){Write_DATA(2*2+1,1);}
  if(pressure>100000){Write_DATA(2*3+1,1);}
  if(pressure>102000){Write_DATA(2*4+1,1);}
  if(pressure>103000){Write_DATA(2*5+1,1);}
  if(pressure>104000){Write_DATA(2*6+1,1);}
  if(pressure>105000){Write_DATA(2*7+1,1);}
  delay(2000); //wait a second and get values again.
    for(i=0;i<8;i++)
  {
        Write_DATA(2*i+1,0);
        }
  

}




void displaytem()
{
 // displayclean();
  float temperature = bmp085GetTemperature(bmp085ReadUT()); //MUST be called first
  float pressure = bmp085GetPressure(bmp085ReadUP());
  float atm = pressure / 101325; // "standard atmosphere"
  float altitude = calcAltitude(pressure); //Uncompensated caculation - in Meters 
  temg=temperature*100;
  Serial.print("Temperature: ");
  Serial.print(temperature, 2); //display 2 decimal places
  Serial.println("deg C");

  Serial.print("Pressure: ");
  Serial.print(pressure, 0); //whole number only.
  Serial.println(" Pa");
  disp0=16;
  disp1=16;
  disp2=temperature/10;
  disp3=temperature/1-disp2*10+20;
  disp4=temg/10-(disp3-20)*10-disp2*100;
  disp5=0;
  disp6=17;
  disp7=18;
  Serial.print("Standard Atmosphere: ");
  Serial.println(atm, 4); //display 4 decimal places

  Serial.print("Altitude: ");
  Serial.print(altitude, 2); //display 2 decimal places
  Serial.println(" M");

  Serial.println();//line break
  
  displaynum(disp0,disp1,disp2,disp3,disp4,disp5,disp6,disp7);
  if(temperature>10){       Write_DATA(2*0+1,1);}
  if(temperature>15){Write_DATA(2*1+1,1);}
  if(temperature>18){Write_DATA(2*2+1,1);}
  if(temperature>20){Write_DATA(2*3+1,1);}
  if(temperature>22){Write_DATA(2*4+1,1);}
  if(temperature>25){Write_DATA(2*5+1,1);}
  if(temperature>30){Write_DATA(2*6+1,1);}
  if(temperature>35){Write_DATA(2*7+1,1);}
  delay(2000); //wait a second and get values again.
    for(i=0;i<8;i++)
  {
        Write_DATA(2*i+1,0);
        }
  
  
  

}
