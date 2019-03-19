 
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
	
	
void display_num(char num);
void mux4(void);	
void delay(long x);
void mdelay(long x);
	
	
unsigned char digits[4]={1,2,3,4};
	
main()
{
	unsigned int d;
	
	CLR_BIT(SW_DDR,SW1);	//SET SW1 AS INPUT
	CLR_BIT(SW_DDR,SW2);	//SET SW2 AS	INPUT
	CLR_BIT(SW_DDR,SW3);	//SET SW3 AS INPUT
	
	
	
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
	 
	
	 
	 
	 
	while (1){
		int cnt = 0;
		PB_ODR |= (1<<5);
		mdelay(300);
		PB_ODR &= ~(1<<5);
		mdelay(300);
		
			
	}
	//	mux4();
		/*for(cnt=0;cnt<11;cnt++){
			display_num(cnt);
			delay(500);
			PB_ODR |= (1<<5);
			delay(500);
      PB_ODR &= ~(1<<5);
		}
	
	}*/
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

