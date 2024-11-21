#include <stdio.h>

 
int main() {
    int a1, i;
    
    scanf("%d",&a1);
	
	for(i=1;i<=a1;i++)
	{
	    printf("%d %d %d\n", i, i*i, i*i*i);
	}
	

    return 0;
}
