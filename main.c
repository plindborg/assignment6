#include <stdio.h>
#include <stdlib.h>
#include "resistance/resistance.h"
#include "power/power.h"
#include "component/component.h"

/************************************
 * Assignment 6 - simple test program
 * trying out dynamic libraries
 */ 
int main(void)
{
  float *p_array;
  float voltage, resistance;
  char sp;
  int count, i;
  float *components;
  p_array = (float *)malloc(sizeof(float) *3);

  printf("Ange spänningskälla i V:");
  scanf("%f",&voltage);
  printf("Ange koppling[S|P]:");
  scanf(" %c", &sp);
  printf("Antal komponenter:");
  scanf("%d", &count);

  components = (float *)malloc(sizeof(float) *count);
  
  for(i = 0; i < count; i++){
    printf("Komponent %d i ohm:", i+1);
    scanf("%f", &components[i]);
  }
  
  resistance =  calc_resistance(count,sp,components); /* calculate resistance */
  printf("Ersättningsresistans: %.1f ohm\n", resistance) ; 
  printf("Effekt: %.2f W\n",  calc_power_r(voltage, resistance)); /* calculate power */
   
  int value = e_resistance(resistance, p_array); /* calculate resistors */
  printf("Ersättningsresistanser i E12-serien kopplade i serie:  %.1f %.1f %.1f \n", p_array[0], p_array[1], p_array[2]);
  /* release pointers */
  free(p_array);
  free(components);    
           
  return 0;
}
