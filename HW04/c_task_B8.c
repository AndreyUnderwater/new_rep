//Ввести целое число и определить, верно ли, что в нём ровно одна цифра «9».

#include <stdio.h>

 
int main() {
    int a1, s2 = 0;
    
    scanf("%d",&a1);
	
	while(a1>0)
	{
        if((a1%10) == 9)
        {
		    s2 +=1;
		}
		
		a1 /= 10;
    }

    if(s2 == 1)
    {
        printf("YES");
    }
    else
    {
		printf("NO");
	}
    return 0;
}
