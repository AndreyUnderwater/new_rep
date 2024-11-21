#include <stdio.h>

int main (void) {
    int a1,a2,a3, a4,a5;
    int b[5];
    int i, j;
    int tmp;
    
    scanf("%d%d%d%d%d", &a1, &a2, &a3, &a4, &a5);
    
    b[0]=a1;
    b[1]=a2;
    b[2]=a3;
    b[3]=a4;
    b[4]=a5;
    
    for(j=0;j<4;j++){
        for(i=0;i<4;i++){
	        if(b[i+1]>b[i]){
	            tmp = b[i+1];
	            b[i+1] = b[i];
	            b[i] = tmp;
	        }
	    }
    }  
    
    printf("%d", b[0]);
}
