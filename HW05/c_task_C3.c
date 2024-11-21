#include <stdio.h>
//#include <math.h>

int middle(int ch, int st);

int main (void) {
    int a1, a2;
    scanf("%d %d", &a1, &a2);

    printf("%d", middle(a1, a2));
}

int middle(int ch1, int ch2)
{
        return (ch1+ch2)/2;
}
