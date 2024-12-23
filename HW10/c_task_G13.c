//В файле input.txt записан полный адрес файла (возможно, без расширения). Необходимо изменить его расширение на ".html" и записать результат в файл output.txt.
#include <stdio.h>

int main() {
    FILE *f1, *f2;

    f1 = fopen("input.txt","r");
    f2 = fopen("output.txt","w");

    signed char c, n = 0;
   
    while( (c = fgetc(f1)) != EOF )
    {
        putc(c,f2);
        if(c=='.')
            n++;
        if(c == '.' && n==2)
            break;
    }       

    if(n == 1)
    {
        c='.';
        putc(c,f2);
        c='h';
        putc(c,f2);
        c='t';
        putc(c,f2);
        c='m';
        putc(c,f2);
        c='l';
        putc(c,f2);     
    }
    else
    {
        c='h';
        putc(c,f2);
        c='t';
        putc(c,f2);
        c='m';
        putc(c,f2);
        c='l';
        putc(c,f2);     
    }

    fclose(f1);
    fclose(f2);

    return 0;
}


