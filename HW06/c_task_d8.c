//Составить рекурсивную функцию, Выведите все числа от A до B включительно, в порядке возрастания, если A < B, или в порядке убывания в противном случае.
#include <stdio.h>


void fun(int, int, int);


int main (void) {
    int a1, a2, k;
    scanf("%d%d",&a1,&a2);
    if(a1<a2)
    {
	    k=1;
	}
	else
	{
	    k=0;
	}
    fun(a1,a2, k);
    return 0;
}

void fun(int a1, int a2, int k)
{
    
    if(k>0)
    {
	    printf("%d ", a1);
	    if(a1==a2)
	    {
			return;
		}
	    fun(a1+1, a2, k);
	}
    else
    {
	    printf("%d ", a1);
	    if(a1==a2)
	    {
			return;
		}
	    fun(a1-1, a2, k); 
    }
}
