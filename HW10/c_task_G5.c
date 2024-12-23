//В файле input.txt дана символьная строка не более 1000 символов. Необходимо заменить все буквы "а" на буквы "b" и наоборот, как заглавные, так и строчные. Результат записать в output.txt.
#include <stdio.h>

int main() {
    FILE *f1, *f2;
    signed char c;
    f1 = fopen("input.txt","r");
    f2 = fopen("output.txt","w");
    
    
    while( (c = fgetc(f1)) != EOF )
    {
        if(c == 'a')
            fprintf(f2, "%c", 'b');
        else
            if(c == 'b')
                fprintf(f2,"%c", 'a');
            else
                if(c == 'A')
                    fprintf(f2, "%c", 'B');
                else
                    if(c == 'B')
                        fprintf(f2,"%c", 'A');
                    else
                        fprintf(f2,"%c", c);
    }       
    fclose(f1);
    fclose(f2);
    
    return 0;
}

