#include <stdio.h>

 
int main() {
    int a1, a1_old=999, i=0;
    
    scanf("%d",&a1);
	
	while(a1)
	{
        if(a1%10 == a1_old) 
        {
		    i = 1;
		}
		
        a1_old = a1%10;	    

        a1    /= 10;

	}
    
    if(i==1) 
    {
	    printf("YES");
	}
	else
	{
	    printf("NO");
	}
    

    return 0;
}
