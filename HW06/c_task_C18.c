//Составить логическую функцию, которая определяет, что текущий символ это цифра. Написать программу считающую количество цифр в тексте.


#include <stdio.h>

int fun(void);


int main (void) {
	
	printf("%d", fun());
	
    return 0;

 
}

int fun(void)
{
	char s;
	int s1 = 0;
    
    while((s = getchar()) != '.')
    {
	    
	    if(s >= '0' && s <= '9')
	    {
		    s1 += 1;
		}
	    
	}

    return s1;
}   
