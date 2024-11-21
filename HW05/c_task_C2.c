#include <stdio.h>
//#include <math.h>

int pow2(int ch, int st);

int main (void) {
    int a1, a2;
    scanf("%d %d", &a1, &a2);

    printf("%d", pow2(a1, a2));
}

int pow2(int ch, int st)
{
    int i, j=1;
    
    if(st==0)
    {
	    return 1;
	}
	else
	{
        for(i=0;i<st;i++)
        {
		    j*=ch;
		}
        return j;
    }
}
