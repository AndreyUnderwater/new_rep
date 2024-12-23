//В файле input.txt символьная строка не более 1000 символов. Необходимо проверить, является ли она палиндромом (палиндром читается одинаково в обоих направлениях). Реализовать логическую функцию is_palindrom(str) и записать ответ в файл output.txt.
#include <stdio.h>


unsigned char is_palindrom(signed char *);

int main() {
    FILE *f1, *f2;

    f1 = fopen("input.txt","r");
    f2 = fopen("output.txt","w");

    signed char c, a[1000] = {0};
    int n = 0;
   
    while( (c = fgetc(f1)) != EOF )
    {
        a[n] = c;
        n++;
    }       
    a[n] = 0;

    c = 0;
    if(is_palindrom(a) == 1)
    {
        fprintf(f2, "YES");
    }
    else
    {
        fprintf(f2, "NO");
    }
    
    fclose(f1);
    fclose(f2);

    
    return 0;
}

unsigned char is_palindrom(signed char *a)
{
    int n = 0;
    unsigned char d;

    while(a[n] != 0)
    {  
        n++;   
    }
    n=n-1;
    for(int i=0;i<n;i++)
    {
        if(a[i] == a[n - i - 1])
            d = 1;
        else
        {
            d = 0;
            break;
        }
    }
    return d;
}
