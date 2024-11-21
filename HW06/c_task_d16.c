//Написать логическую рекурсивную функцию и используя ее определить является ли введенное натуральное число точной степенью двойки.

#include <stdio.h>


void fun(int);


int main (void) {
    int a1;
    scanf("%d",&a1);
    fun(a1);
    return 0;
}

void fun(int a1)
{
    if(a1<2)
    {
        printf("YES");
        return;
    }
    else
    {
    
        if((a1%2) == 0)
        {
	        
	        fun(a1/2);
	    }
	    else
	    {
	        printf("NO");
	        return;
	    }    
    }
}
