//Составить рекурсивную функцию, которая определяет сумму всех чисел от 1 до N
#include <stdio.h>


void fun(int);


int main (void) {
    int a;
    scanf("%d",&a);
    fun(a);
    return 0;
}

void fun(int a)
{
    static int summ=0;
    if(a<1)
    {
        printf("%d", summ);
        return;
    }
    summ+= a;
    fun(a-1);
}
