//Считать массив из 12 элементов и выполнить инверсию для каждой трети массива.

#include <stdio.h>

void input_Array(int array[], int array_len); 
void print_Array(int array[], int array_len, int offset_k);
void work_Array(int array[], int array_len);


#define A_LEN 12

int main() {
    int a[12]={0};
    input_Array(a, A_LEN);
    //print_Array(a, A_LEN);  
    //work_Array(a, A_LEN);   
    print_Array(a, A_LEN, 0);  
    print_Array(a, A_LEN, A_LEN / 3);  
    print_Array(a, A_LEN, 2 * A_LEN / 3);
    return 0;
}

void input_Array(int array[], int array_len)
{
    for(int i=0;i < array_len; i++)
        scanf("%d", &array[i]);
}

void print_Array(int array[], int array_len, int offset_k)
{
    for(int i = array_len / 3 - 1; i >= 0; i--)
        printf("%d ", array[i + offset_k]);
}

void work_Array(int array[], int array_len)
{
    for(int i = 0; i < array_len / 2; i++)
    {
        array[i] = -1 * array[i];
    }
}
