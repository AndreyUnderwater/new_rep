#include <stdio.h>

int main (void) {
    int a1,a2,a3;
    scanf("%d%d%d", &a1, &a2, &a3);

    if(a1<(a2+a3)) {
        if(a3<(a1+a2)){
	        if(a2<(a1+a3)){
	            printf("YES");   
	 		}
	 		else{
				printf("NO");
			}
        }
        else{
			printf("NO");
		}
    }
    else{
        printf("NO");  
    }
}
