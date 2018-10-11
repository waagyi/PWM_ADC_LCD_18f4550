
  // pwm with lcd
  //working
  // Be sure RW pin to connect to ground

unsigned long  i,j,Adc_Res,pwm;
unsigned char op[12],lcd[12];
char *text = "PWM AT 5kHZ";
char *text1= "DUTY =";
char *text2="%";

void main()
     {

     k=234;
     TRISB=0;
     ADCON1=0x0E;
     PORTB=0;
     TRISA.f0=1;
     TrISC.f2=0;

     PWM1_Init(5000);
     PWM1_Start();

      Lcd_Init(&PORTB);
      Lcd_Cmd(Lcd_CLEAR);
      LCD_CURSOR_OFF;
      Lcd_Out(1, 3,text);
      Lcd_Out(2,1,text1);
      Lcd_Out(2,12,text2);

      PWM1_Init(5000);
      PWM1_Start();

     for(;;)
      {
       Adc_Res=Adc_Read(0);

      Adc_Res=(Adc_Res*25)/100;
       pwm=Adc_Res;

        
       Pwm1_Change_Duty(pwm);

      LongToStr(Adc_Res,op); // Convert to string in "op"

       j=0;

       for(i=0;i<=11;i++)
       {


       if(op[i] != ' ') // If a blank
         {
         lcd[j]=op[i];
         j++;
         }
          if(pwm<10)
         {
         lcd[1]=' ';
         lcd[2]=' ';
         }
          if(pwm>10&&pwm<100)
         {
         lcd[2]=' ';
         }


       Lcd_Out(2,8,lcd);


      }

      }

     }

