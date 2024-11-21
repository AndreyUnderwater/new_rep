#include <stdio.h>

 
int main() {
    int a1, a2=0;
    
    scanf("%d",&a1);
	
	while(a1)
	{
        a2 +=a1%10;
        a1 /= 10;	    
	}
    
    printf("%d", a2);
    

    return 0;
}
