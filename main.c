#include <stdio.h>
#include "resistance/resistance.h"
#include "power/power.h"


int main(void)
{
	puts("Testing shared lib");
	hello();
	float array[3] = {300,500,598};
	float x = calc_resistance(3,'P',array);
	printf("%f\n",x);

  printf("%f\n",calc_power_r(50, 1398));
	printf("%f\n",calc_power_i(50,45));

	return 0;
}
