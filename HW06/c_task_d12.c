//Дана монотонная последовательность, в которой каждое натуральное число k встречается ровно k раз: 1, 2, 2, 3, 3, 3, 4, 4, 4, 4,… Выведите первые n членов этой последовательности. Только один цикл for.
#include <stdio.h>

void fun(int, int);

int main (void) {
    int a;
    scanf("%d", &a);
    fun(a, a);
    return 0;
}

void fun(int a, int b)
{
    static int k = 0;
    
    if(a<1) {
        return;
    }
    else
    {
	    fun(a-1, b);
	    for(int i = 0; i < a; i++)
	    {
	        k++;
	        if(k <= b) 
	        {
	            printf("%d ", a);
	        }
	    }	
    } 
}
