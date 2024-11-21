//Составить логическую функцию, которая определяет, верно ли, что в заданном числе сумма цифр равна произведению.

void chet(int);

#include <stdio.h>

int main (void) {
	int a1;
	scanf("%d", &a1);
    chet(a1);
    return 0;
}

void chet(int a1)
{
    int summ = 0, mul = 1;
    while(a1>0)
    {
	    summ += (a1%10);
	    mul  *= (a1%10);
	    a1 /= 10;
	}
	
	if(summ == mul)
	{
	    printf("YES");
    }
    else
    {
	    printf("NO");
	}
    return;
}
