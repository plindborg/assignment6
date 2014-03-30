#include <stdio.h>
#include <stdlib.h>
#include "component.h"

/*! Library for calculating equivalent series resistance */

/*
 * Function:  e_resitance 
 * --------------------
 * calculates equivalent series resistance 
 * using up to three resistors from the E12 series   
 *
 *  orig_resistance: the required resistance
 *  res_array: array with three ohm values from the E12 series  
 *  returns: number of resistors used
 *           
 */
int e_resistance(float orig_resistance, float *res_array){

  float temp = orig_resistance;
  float sum = 0;
  int i, j,count = 0;
 
  for(j = 0; j < 3; j++){
    
    i = sizeof(e12_table)/sizeof(e12_table[0]) - 1; /* 61 values */
    
    while(e12_table[i] > temp && i > 0){
      i--;
    }
       
    res_array[j] = e12_table[i];
    sum += res_array[j]; 
        
    if(sum >= orig_resistance){
      if(sum > orig_resistance){
	res_array[j] = 0;
      }
      break;
    }	    
    else {    
      temp = orig_resistance - sum;
    }  
  }  
  
  for(i=0; i<3; i++){
    if(res_array[i]>0){
      count++;
    }
  }
    
  return count;
}
