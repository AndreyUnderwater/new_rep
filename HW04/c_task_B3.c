#include <stdio.h>

 
int main() {
    int a1, a2, i;
    
    scanf("%d%d",&a1,&a2);
	
	for(i=a1;i<=a2;i++)
	{
	    if(i == a1) {a1 = 0;}
	    a1 += i*i;
	}
	
    printf("%d", a1);
    return 0;
}
