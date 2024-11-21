#include <stdio.h>

int main (void) {

    int b;
//    int i, j;
    int tmp1,tmp2,tmp3;
    
    scanf("%d", &b);
    
    tmp1 = b%10;    
    tmp2 = (b - tmp1) / 10;
    tmp3 = tmp2 / 10;
    
    
    printf("%d", tmp1 + tmp2%10 + tmp3);
}
