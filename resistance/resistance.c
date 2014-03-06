#include <stdio.h>

float calc_resistance(int count, char conn, float *array){
	float total = 0.0;
	for(int i = 0; i < count; i++) {
		if(conn == 'P') {
			if(array[i] = 0 )
				return 0;	
		}
		printf("%f",array[i]);
		total += array[i];
	}

	return total;
}

void hello() {
	puts("hello");

}
