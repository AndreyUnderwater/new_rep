#include <stdio.h>

int main (void) {
    int a1, a2;
    scanf("%d%d", &a1,&a2);

    
    
    if(a1>a2) {
        printf("Above");
    }
    else {
	
        if(a1 == a2) {
            printf("Equal");
        }
        else{
	        printf("Less");
	    }
    }




}
