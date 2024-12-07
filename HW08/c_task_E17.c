//Дан массив из 10 элементов. В массиве найти элементы, которые в нем встречаются только один раз, и вывести их на экран.

#include <stdio.h>

void input_Array(int array[], int array_len);
void work_Array(int array[], int number);

#define A_LEN 10

int main() {
    int a[A_LEN];// = {9,8,7,6,5,4,3,2,1,0}; 
    input_Array(a, A_LEN);

//    int b;
//    b = input_Keyboard();
    //printf("%d\n", b);
    //print_Array(a, A_LEN);  
    work_Array(a, A_LEN);   
    //printf("%d\n", b);
    //print_Array(a, b);
//    bubble_Sort(a, b);  
    //print_Array(a, b);
//    b = big_Number(a, b);
//    printf("%d\n", b);
    return 0;
}

void input_Array(int array[], int array_len)
{
    for(int i=0;i < array_len; i++)
        scanf("%d", &array[i]);
}


void work_Array(int array[], int array_len)
{
    int tmp = 0;
    for(int i = 0; i < array_len; i++)
    {
        tmp = 0;
        for(int j = 0; j < array_len; j++)
        {
            if(array[i]==array[j])
                tmp++;
        }
        if(tmp==1)
            printf("%d ", array[i]);
    }
}
