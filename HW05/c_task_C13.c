//Составить функцию, которая вычисляет синус как сумму ряда (с точностью 0.001)
//cos(x) = 1 - x2/2! + x4/4! - x6/6! + ... (x в радианах)
//float cosinus(float x)

float cosinus(float);

#include <stdio.h>
//#include <math.h>

double sinus(double);

int main (void) {
	float x;
	scanf("%f", &x);
    printf("%.3f", cosinus(x));
    return 0;
}

float cosinus(float x)
{
        x = 3.14159265 * (x / 180);
        return 1 - (x*x)/2 + (x*x*x*x)/24 - (x*x*x*x*x*x)/720 + (x*x*x*x*x*x*x*x)/40320 - (x*x*x*x*x*x*x*x*x*x)/3628800;
}
