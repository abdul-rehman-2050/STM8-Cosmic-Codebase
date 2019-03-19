#include <iostm8s103.h>

  #define SW1	1
	#define SW_DDR PA_DDR
	#define SW_CR1 PA_CR1
	#define SW_CR2 PA_CR2
	#define SW_IDR PA_IDR
  
  
  #define SW1_HIGH ((SW_IDR)&(1<<SW1))
  
  
  #define LED_HIGH	PB_ODR |= (1<<5)    //ON BOARD LED 
	#define LED_LOW		PB_ODR &= ~(1<<5)
	
  
  void delay(long x);
  
main()
{
	unsigned int d;
	
	CLR_BIT(SW_DDR,SW1);	//SET SW1 AS INPUT
	SET_BIT(SW_CR1,SW1);	//input pullup without interrupt
  PB_DDR = 255;		//PORTB AS OUTPUT
  PB_CR1 = 255;
  while (1){
		int cnt = 0;
		if(!SW1_HIGH){
			LED_HIGH;   //LED OFF
			do{
				delay(10);
			}while(!SW1_HIGH);
			LED_LOW;  //LED ON 
		}
		delay(100);
	}
   
}
  
  
  void delay(long x){
	char d=0;
	for(;x>0;x--)
		for (d = 0; d < 10; d++); //Delay ~ 1 second
	
}
