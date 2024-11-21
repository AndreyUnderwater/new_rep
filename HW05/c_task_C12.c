//Составить функцию, которая вычисляет синус как сумму ряда (с точностью 0.001)
//sin(x) = x - x3/3! + x5/5! - x7/7! + ...(x в радианах)
//float sinus(float x)

float sinus(float);

#include <stdio.h>
//#include <math.h>

float sinus(float);

int main (void) {
	int x;
	scanf("%d", &x);
    printf("%.3f", sinus((float)x));
    return 0;
}

float sinus(float x)
{
        x = 3.14159265 * (x / 180);
        return x - (x*x*x)/6 + (x*x*x*x*x)/120 - (x*x*x*x*x*x*x)/5040;
}
