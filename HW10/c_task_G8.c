//В файле input.txt дана строка, не более 1000 символов, содержащая буквы, целые числа и иные символы. Требуется все числа, которые встречаются в строке, поместить в отдельный целочисленный массив. Например, если дана строка "data 48 call 9 read13 blank0a", то в массиве числа 48, 9, 13 и 0. Вывести массив по возрастанию в файл output.txt.
#include <stdio.h>


int stp_10(int);

int main() {
    FILE *f1, *f2;

    f1 = fopen("input.txt","r");
    f2 = fopen("output.txt","w");

    signed char c;
    int n = 0, k = 0, a[1000] = {0}, summ=0,offst=-1, tmp;
   
    while( (c = fgetc(f1)) != EOF )
    {
        fseek(f1,offst,SEEK_END);
        offst--;
        if(c>='0' && c<='9')
        {
            //printf("%d %d %d %d\n", c-'0',k,n,summ);
            if(n == 0)
            {    summ = c - '0';}
            else
                {summ += (c - '0') * stp_10(n); }
            
            //printf("%d %d %d %d\n", c-'0',k,n,summ);
            n++;
        }
        else
        {
            if(n > 0)
            {
                a[k] = summ;
                k++;
                n = 0;
            } 
        }
    }       

    for(int i = 0; i < k; i++)
    {
        for(int j = 0; j < k-1; j++)
            {
                if(a[j]>a[j+1])
                {
                    tmp = a[j];
                    a[j]=a[j+1];
                    a[j+1]=tmp;
                }
            }
    }

    for(int i = 0; i < k; i++)
        {fprintf(f2, "%d ",a[i]);}
    
    fclose(f1);
    fclose(f2);

    return 0;
}



int stp_10(int st)
{
    int summ = 1;
    for(int i = 0; i < st; i++)
    {
        summ *= 10;
    }
    return summ;
}
