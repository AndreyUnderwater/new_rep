//В файле input.txt дано предложение требуется разобрать его на отдельные слова. Напечатать каждое слово на отдельной строке в файл output.txt.
#include <stdio.h>

int main() {
    FILE *f1, *f2;

    f1 = fopen("input.txt","r");
    f2 = fopen("output.txt","w");

    signed char c, n = 0, k=0, c_old;
   
    while( (c = fgetc(f1)) != EOF )
    {
        if(c == ' ' && k == 0)
            n = 1;
        else
        {
            k = 1;
            n = 1;
        }
            
        
        if(n == 1 && k == 1)
        {
            if(c == ' ' && c_old != ' ')
                fprintf(f2, "\n");
                //putc(c,f2);
            if(c != ' ')
                putc(c,f2);
        }   

        c_old = c;
    }       



    fclose(f1);
    fclose(f2);

    return 0;
}


