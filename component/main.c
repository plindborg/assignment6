#include <stdio.h>
#include <stdlib.h>
#include "component.h"
   
/*
 * Simple test program for component library
 */
int main(int argc, char**argv){

  float *p_array;
  p_array = (float *)malloc(sizeof(float) *3);

  if(argc > 2){ /* simple error test */
    printf("Usage: test x, where x is a number from the E12 resistor series\n");
  }
  else {
    int x = e_resistance(atof(argv[1]), p_array); /* calculate resistors */
    printf("no of resitors: %d values = %f %f %f \n", x, p_array[0], p_array[1], p_array[2]);
    free(p_array);
  }
  return 0;
}
