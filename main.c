#include <stdio.h>
#include <stdlib.h>
#include "resistance/resistance.h"
#include "power/power.h"
#include "component/component.h"

int main(void)
{
  float *p_array;
  p_array = (float *)malloc(sizeof(float) *3);

	puts("Testing shared lib");
	hello();
	float array[3] = {300,500,598};
	float x = calc_resistance(3,'P',array);
	printf("%f\n",x);

  printf("%f\n",calc_power_r(50, 1398));
	printf("%f\n",calc_power_i(50,45));

  float eff = 1398;

  int value = e_resistance(eff, p_array); /* calculate resistors */
  printf("no of resitors: %d values = %f %f %f \n", value, p_array[0], p_array[1], p_array[2]);
  free(p_array);    
           
	return 0;
}
