#include <stdio.h>

int main (void) {
    int a1,a2,a3;
    scanf("%d%d%d", &a1, &a2, &a3);
    if(a1>a2) {
        if(a1>a3){
	        printf("%d", a1);
	    }
	    else{
	        printf("%d", a3);
	    }
        
    }
    else{
        if(a2>a3){
	        printf("%d", a2);
	    }
	    else{
	        printf("%d", a3);
	    }
    }
}
