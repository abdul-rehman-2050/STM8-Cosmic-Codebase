	#include <iostm8s103.h>
	
main()
{
	unsigned int d;
	PB_DDR = (1<<5);
	PB_CR1 = (1<<5);
	while (1){
	   for (d = 0; d < 40000; d++); //Delay ~ 1 second
	   PB_ODR |= (1<<5);
	   for (d = 0; d < 40000; d++); //Delay ~ 1 second
      	   PB_ODR &= ~(1<<5);
	}
}
