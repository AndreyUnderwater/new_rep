#include <stdio.h>

 
int main() {
    int a1, i=0;
    
    scanf("%d",&a1);
	
	while(a1)
	{
        a1 /= 10;i++;	    
	}
    
    if(i==3)
    {
	    printf("YES");
	}
	else
	{
	    printf("NO");	
    }
    
    

    return 0;
}
