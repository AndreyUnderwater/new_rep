#include <stdio.h>

int main (void) {

    int b[5];
    int i, j;
    int tmp;
    
    scanf("%d%d%d%d%d", &b[0], &b[1], &b[2], &b[3], &b[4]);
    
   
    for(j=0;j<4;j++){
        for(i=0;i<4;i++){
	        if(b[i+1]>b[i]){
	            tmp = b[i+1];
	            b[i+1] = b[i];
	            b[i] = tmp;
	        }
	    }
    }  
    
    printf("%d", b[4]+b[0]);
}
