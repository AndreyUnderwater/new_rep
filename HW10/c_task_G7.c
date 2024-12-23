//В файле input.txt считать символьную строку, не более 10 000 символов. Посчитать количество строчных (маленьких) и прописных (больших) букв в введенной строке. Учитывать только английские буквы. Результат записать в файл output.txt.
#include <stdio.h>


int main() {
    FILE *f1, *f2;

    f1 = fopen("input.txt","r");
    f2 = fopen("output.txt","w");

    signed char c;
    int n1 = 0, n2 = 0;
   
    while( (c = fgetc(f1)) != EOF )
    {
        if(c>='a' && c<='z')
            n1++;
        if(c>='A' && c<='Z')
            n2++;

    }       

    fprintf(f2, "%d %d", n1, n2);
    //printf("%d\n", n2);
    
    fclose(f1);
    fclose(f2);

    
    return 0;
}

