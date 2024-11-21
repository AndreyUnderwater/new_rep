//Составить функцию логическую функцию, которая определяет, верно ли, что сумма его цифр – четное число. Используя эту функцию решить задачу.

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
    int summ = 0;
    while(a1>0)
    {
	    summ += (a1%10);
	    a1 /= 10;
	}
	
	if(summ%2 == 0)
	{
	    printf("YES");
    }
    else
    {
	    printf("NO");
	}
    return;
}
