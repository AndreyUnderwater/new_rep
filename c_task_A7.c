#include <stdio.h>

 
int main() {
    int a1, a2;
    scanf("%d%d", &a1, &a2);
    if(a1<a2)
    {
	    printf("%d %d", a1, a2);
	}
	else
	{
	    printf("%d %d", a2, a1);	
	}
    //out = a1 - a2;
    //printf("%d", out);
    //out = a1 * a2 * a3;
    //printf("%d*%d*%d=%d", a1,a2,a3,out);    
    return 0;
}
