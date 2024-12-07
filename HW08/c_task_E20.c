//Переставить цифры в числе так, что бы получилось максимальное число.

#include <stdio.h>

void bubble_Sort(int array[], int array_len); 
void print_Array(int array[], int array_len);
int work_Array(int array[], int number);
int input_Keyboard(void);
int big_Number(int array[], int array_len);
int pow_int(int ch, int st);

#define A_LEN 10

int main() {
    int a[A_LEN];// = {9,8,7,6,5,4,3,2,1,0}; 
    int b;
    b = input_Keyboard();
    //printf("%d\n", b);
    //print_Array(a, A_LEN);  
    b = work_Array(a, b);   
    //printf("%d\n", b);
    //print_Array(a, b);
    bubble_Sort(a, b);  
    //print_Array(a, b);
    b = big_Number(a, b);
    printf("%d\n", b);
    return 0;
}

//void input_Array(int array[], int array_len)
//{
//    for(int i=0;i < array_len; i++)
//        scanf("%d", &array[i]);
//}

int input_Keyboard(void)
{
    int tmp;
    scanf("%d", &tmp);
    return tmp;
}

void print_Array(int array[], int array_len)
{
    for(int i = 0; i < array_len; i++)
        printf("%d ", array[i]);
    printf("\n");
}

void bubble_Sort(int array[], int array_len)
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

int big_Number(int array[], int array_len)
{
    int tmp = 0;
    for(int i = 0; i < array_len; i++)
        tmp += array[i] * pow_int(10, i);
        
    return tmp;

}

int pow_int(int ch, int st)
{
    int tmp=1;
    for(int i=0; i<st;i++)
        tmp *= ch;
    return tmp;
}

int work_Array(int array[], int number)
{
    int i = 0;
    while(number > 0)
    {
        array[i] = number%10;
        i++;
        number /= 10;
    }
    
    return i;
}
