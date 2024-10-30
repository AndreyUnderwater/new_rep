#include <stdio.h>

 
int main() {
    int a1, a2, a3;
    double out;
    scanf("%d%d%d", &a1, &a2, &a3);
    out = ((float)a1 + (float)a2 + (float)a3) / 3;
    printf("%.2f", out);
    //out = a1 * a2 * a3;
    //printf("%d*%d*%d=%d", a1,a2,a3,out);    
    return 0;
}
