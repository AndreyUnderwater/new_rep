//Дан массив из 10 элементов. Определить, какое число в массиве встречается чаще всего. Гарантируется, что такое число ровно 1.

#include <stdio.h>

//void print_Array(int array[], int array_len);
void input_Array(int array[], int array_len);
int work_Array(int array[], int array_len);


#define A_LEN 10

int main() {
    int a[A_LEN];// = {9,8,7,6,5,4,3,2,1,0}; 
    int b;
    input_Array(a, A_LEN);
    b = work_Array(a, A_LEN);   
    printf("%d\n", b);
    return 0;
}


void input_Array(int array[], int array_len)
{
    for(int i=0;i < array_len; i++)
        scanf("%d", &array[i]);
}


int work_Array(int array[], int array_len)
{
    int tmp, tmp_max = 0, tmp_ch;
    for(int i = 0; i < array_len; i++)
    {
        tmp = 0;
        for(int j = 0; j < array_len; j++)
        {
            if(array[i]==array[j])
                tmp++;
        }
        if(tmp_max < tmp)
        {
            tmp_max = tmp;
            tmp_ch  = array[i];
        }
    }
    return tmp_ch;
}
