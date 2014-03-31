#include <stdio.h>
#include <stdlib.h>
#include "power.h"

int main()
{

    float a = 0;
    float b = 0;

    printf("A:\n");
    scanf("%f", &a);
    printf("B: \n");
    scanf("%f", &b);

    printf("%9.6f", calc_power_i(a,b));
    printf("%9.6f", calc_power_r(a,b));
    return 0;
}
