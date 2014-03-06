#include <stdio.h>

float calc_resistance(int count, char conn, float *array){
	float total = 0.0;
	// Check so that conn is P or S.
  if(conn != 'P' && conn != 'S') {
	  return -1;
  }

  // Check so that array is not 0
  if(array == 0) {
    return -1;
  }
  
  for(int i = 0; i < count; i++) {
      if(conn == 'P') {
			  if(array[i] == 0 )
				  return 0;	
		  }
		  total += array[i];
  }
	return total;
}

void hello() {
	puts("hello");

}
