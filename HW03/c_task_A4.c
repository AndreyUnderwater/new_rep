#include <stdio.h>

 
int main() {
    int a1, a2, a3, out;
    scanf("%d%d%d", &a1, &a2, &a3);
    out = a1 + a2 + a3;
    printf("%d+%d+%d=%d\n", a1,a2,a3,out);
    out = a1 * a2 * a3;
    printf("%d*%d*%d=%d", a1,a2,a3,out);    
    return 0;
}
