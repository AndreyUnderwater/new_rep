//Считать массив из 10 элементов и выполнить циклический сдвиг ВПРАВО на 1.

#include <stdio.h>

void input_Array(int array[], int array_len); 
void print_Array(int array[], int array_len);
void work_Array(int array[], int array_len);


#define A_LEN 10

int main() {
    int a[A_LEN];
    input_Array(a, A_LEN);
    //print_Array(a, A_LEN);  
    work_Array(a, A_LEN);   
    print_Array(a, A_LEN);  
    return 0;
}

void input_Array(int array[], int array_len)
{
    for(int i=0;i < array_len; i++)
        scanf("%d", &array[i]);
}

void print_Array(int array[], int array_len)
{
    for(int i = 0; i < array_len; i++)
        printf("%d ", array[i]);
}

void work_Array(int array[], int array_len)
{
    int tmp;
    tmp = array[array_len - 1];
    for(int i = 0; i < array_len; i++)
    {
        array[array_len - i] = array[array_len - i - 1];
    }
    array[0] = tmp;
}
