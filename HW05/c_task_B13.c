//Посчитать количество четных и нечетных цифр числа.

#include <stdio.h>

 
int main() {
    int a1, s1 = 0, s2 = 0;
    
    scanf("%d",&a1);
	
	while(a1>0)
	{
        if((a1%10)%2 == 0)
        {
		    s2 +=1;
		}
		else
		{
		    s1 +=1;
		}
		
		a1 /= 10;
    }

    printf("%d %d", s2, s1);

    return 0;
}
