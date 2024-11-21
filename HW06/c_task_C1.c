#include <stdio.h>
#include <math.h>

int modul(int i);

int main (void) {
    int a1, a2;
    scanf("%d", &a1);

    a2 = modul(a1);
    printf("%d", a2);
}

int modul(int i)
{
    return fabs(i);
}
