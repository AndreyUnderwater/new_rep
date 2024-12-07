//Считать массив из 10 элементов и отсортировать первую половину по возрастанию, а вторую – по убыванию.

#include <stdio.h>

void bubble_Sort_high(int array[], int array_len);
void bubble_Sort_down(int array[], int array_len); 
void print_Array(int array[], int array_len);
void input_Array(int array[], int array_len);

void copy_Array(int array1[], int array2[], int offset, int k);

#define A_LEN 10
#define B_LEN 5

int main() {
    int a1[A_LEN];// = {9,8,7,6,5,4,3,2,1,0}; 
    int a2[B_LEN];
    input_Array(a1, A_LEN);
    
    copy_Array(a1, a2, 0, A_LEN / 2);
    //print_Array(a2, A_LEN / 2);
    bubble_Sort_high(a2, A_LEN / 2);
    print_Array(a2, A_LEN / 2);
    
    copy_Array(a1, a2, 5, A_LEN / 2);
    //print_Array(a2, A_LEN / 2);
    bubble_Sort_down(a2, A_LEN / 2);
    print_Array(a2, A_LEN / 2);
    
    
    
    //copy_Array(a1, a2, 5, A_LEN / 2);
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
    //printf("\n");
}

void bubble_Sort_high(int array[], int array_len)
{
    int tmp;
    for(int i=0;i<array_len;i++)
    {
        for(int j=0;j<array_len-i-1;j++)
        {
            if(array[j] > array[j+1])
            {
                tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
            }
            //printf("%d  ", i);
            //print_Array(array, A_LEN);
        }
    }   
    
}

void bubble_Sort_down(int array[], int array_len)
{
    int tmp;
    for(int i=0;i<array_len;i++)
    {
        for(int j=0;j<array_len-i-1;j++)
        {
            if(array[j] < array[j+1])
            {
                tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
            }
            //printf("%d  ", i);
            //print_Array(array, A_LEN);
        }
    }   
    
}




void copy_Array(int array1[], int array2[], int offset, int k)
{
    for(int i = 0; i < k; i++)
        array2[i] = array1[i + offset];
}
