#include <stdio.h>

 
int main() {
    int a1, a2, i=0;
    
    scanf("%d",&a1);
	
	a2 = a1;
	
	while(a2)
	{
	    a1 = a2/10;
	    while(a1)
	    {
            
            if(a1%10 == a2%10) 
            {
		        i = 1;
		    }

            a1    /= 10;

	    }
        
        a2 /= 10;
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
