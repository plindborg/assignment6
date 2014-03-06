#include <stdio.h>
#include "resistance.h"


int main(void)
{
	puts("Testing shared lib");
	hello();
	float array[3] = {1.1,1.1,1.3};
	float x = calc_resistance(3,'P',array);
	printf("%f",x);
	return 0;
}
