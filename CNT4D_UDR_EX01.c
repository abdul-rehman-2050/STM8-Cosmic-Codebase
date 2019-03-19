
 
#include <iostm8s103.h>
	
	
	#define CLR_BIT(p,n) ((p) &= ~((1) << (n)))
	#define SET_BIT(p,n) ((p) |= (1 << (n)))
	
	
	#define CLR_SEG1	CLR_BIT(PB_ODR,4)
	#define CLR_SEG2  CLR_BIT(PC_ODR,3)
	#define CLR_SEG3  CLR_BIT(PC_ODR,4)
	#define CLR_SEG4  CLR_BIT(PC_ODR,5)
	
	
	
	#define SET_SEG1	SET_BIT(PB_ODR,4)
	#define SET_SEG2  SET_BIT(PC_ODR,3)
	#define SET_SEG3  SET_BIT(PC_ODR,4)
	#define SET_SEG4  SET_BIT(PC_ODR,5)
	
	
	
	#define CLR_SEGA  CLR_BIT(PD_ODR,6)
	#define CLR_SEGB  CLR_BIT(PD_ODR,5)
	#define CLR_SEGC  CLR_BIT(PD_ODR,4)
	#define CLR_SEGD  CLR_BIT(PD_ODR,3)
	#define CLR_SEGE  CLR_BIT(PD_ODR,2)
	#define CLR_SEGF  CLR_BIT(PC_ODR,7)
	#define CLR_SEGG  CLR_BIT(PC_ODR,6)
	
	#define SET_SEGA  SET_BIT(PD_ODR,6)
	#define SET_SEGB  SET_BIT(PD_ODR,5)
	#define SET_SEGC  SET_BIT(PD_ODR,4)
	#define SET_SEGD  SET_BIT(PD_ODR,3)
	#define SET_SEGE  SET_BIT(PD_ODR,2)
	#define SET_SEGF  SET_BIT(PC_ODR,7)
	#define SET_SEGG  SET_BIT(PC_ODR,6)
	
	
	
	#define SW1	1
	#define SW2  2
	#define SW3  3
	#define SW_DDR PA_DDR
	#define SW_CR1 PA_CR1
	#define SW_CR2 PA_CR2
	#define SW_IDR PA_IDR
	
	#define SW1_HIGH ((SW_IDR)&(1<<SW1))
	#define SW2_HIGH ((SW_IDR)&(1<<SW2))
	#define SW3_HIGH ((SW_IDR)&(1<<SW3))
	
	#define LED_HIGH	PB_ODR |= (1<<5)
	#define LED_LOW		PB_ODR &= ~(1<<5)
	
void display_num(char num);
void mux4(void);	
void delay(long x);
void mdelay(long x);
void cnt2digits(int val);	
	
unsigned char digits[4]={1,2,3,4};
	

int counter_value = 0;
	
	
main()
{
	unsigned int d;
	
	CLR_BIT(SW_DDR,SW1);	//SET SW1 AS INPUT
	CLR_BIT(SW_DDR,SW2);	//SET SW2 AS	INPUT
	CLR_BIT(SW_DDR,SW3);	//SET SW3 AS INPUT
	SET_BIT(SW_CR1,SW1);	//input pullup without interrupt
	SET_BIT(SW_CR1,SW2);	//input pullup without interrupt
	SET_BIT(SW_CR1,SW3);	//input pullup without interrupt
	
	
	 PB_DDR = 255;		//PORTB AS OUTPUT
	 PC_DDR = 255;		//PORTC AS OUTPUT
	 PD_DDR = 255;
	 
	 //PB_DDR = (1<<5);
	 PB_CR1 = 255;
	 PD_CR1 = 255;
	 PC_CR1 = 255;
	 
	 CLR_SEG1;
	 CLR_SEG2;
	 CLR_SEG3;
	 CLR_SEG4;
	 
	
	counter_value=0;	//initial reset value
	cnt2digits(counter_value);
	 
	 
	while (1){
		int cnt = 0;
		if(!SW1_HIGH){
			LED_HIGH;
			if(counter_value<9999){
				counter_value++;
				cnt2digits(counter_value);
			}
			do{
				mdelay(10);
			}while(!SW1_HIGH);
			LED_LOW;
			
		}
		else if(!SW2_HIGH){
			if(counter_value>0){
				counter_value--;
				cnt2digits(counter_value);
			}
			do{
				mdelay(10);
			}while(!SW2_HIGH);
			
		}
		
		else if(!SW3_HIGH){
			counter_value=0;
			cnt2digits(counter_value);
		}
		mdelay(100);
			
	}
}

void display_num(char num){
	switch(num){
		
		case 0:
		CLR_SEGA;CLR_SEGB;CLR_SEGC;CLR_SEGD;CLR_SEGE;CLR_SEGF;SET_SEGG;
		break;
		
		case 1:
		SET_SEGA;CLR_SEGB;CLR_SEGC;SET_SEGD;SET_SEGE;SET_SEGF;SET_SEGG;
		break;
		
		case 2:
		CLR_SEGA;CLR_SEGB;SET_SEGC;CLR_SEGD;CLR_SEGE;SET_SEGF;CLR_SEGG;
		break;
		
		case 3:
			CLR_SEGA;CLR_SEGB;CLR_SEGC;CLR_SEGD;SET_SEGE;SET_SEGF;CLR_SEGG;
		break;
		
		case 4:
			SET_SEGA;CLR_SEGB;CLR_SEGC;SET_SEGD;SET_SEGE;CLR_SEGF;CLR_SEGG;
		break;
		
		case 5:
			CLR_SEGA;SET_SEGB;CLR_SEGC;CLR_SEGD;SET_SEGE;CLR_SEGF;CLR_SEGG;
		break;
		
		case 6:
			CLR_SEGA;SET_SEGB;CLR_SEGC;CLR_SEGD;CLR_SEGE;CLR_SEGF;CLR_SEGG;
		break;
		
		case 7:
			CLR_SEGA;CLR_SEGB;CLR_SEGC;SET_SEGD;SET_SEGE;SET_SEGF;SET_SEGG;
		break;
		
		case 8:
			CLR_SEGA;CLR_SEGB;CLR_SEGC;CLR_SEGD;CLR_SEGE;CLR_SEGF;CLR_SEGG;
		break;
		
		case 9:
			CLR_SEGA;CLR_SEGB;CLR_SEGC;CLR_SEGD;SET_SEGE;CLR_SEGF;CLR_SEGG;
		break;
		
		default:
			SET_SEGA;SET_SEGB;SET_SEGC;SET_SEGD;SET_SEGE;SET_SEGF;SET_SEGG;
		break;
		
		
	}
	
}


void mux4(){
	
	SET_SEG1;SET_SEG2;SET_SEG3;SET_SEG4;
	
	display_num(digits[0]);
	CLR_SEG1;
	delay(1);
	SET_SEG1;
	
	
	delay(1);
	
	display_num(digits[1]);
	CLR_SEG2;
	delay(1);
	SET_SEG2;
	
	
	delay(1);
	
	display_num(digits[2]);
	CLR_SEG3;
	delay(1);
	SET_SEG3;
	
	
	delay(1);
	
	display_num(digits[3]);
	CLR_SEG4;
	delay(1);
	SET_SEG4;
	
	delay(1);
	
}


void delay(long x){
	char d=0;
	for(;x>0;x--)
		for (d = 0; d < 10; d++); //Delay ~ 1 second
	
}

void mdelay(long x){
	long i=0;
	for(i=0;i<x;i++){
			mux4();
	}
}

void cnt2digits(int val){
	digits[3]=val%10;
	digits[2]=(val/10)%10;
	digits[1]=(val/100)%10;
	digits[0]=(val/1000)%10;
	
	
}
