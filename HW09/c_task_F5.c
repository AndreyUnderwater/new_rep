//Написать только одну функцию, которая находит максимальный элемент в массиве. Всю программу загружать не надо.
//Прототип функции: int find_max_array(int size, int a[])
//#include <stdio.h>


//int find_max_array(int size, int a[]);

//int main() {

//    int s[8] = {-66,-88,-99,-22,-1,-89,-67,-5};

//    printf("%d", find_max_array(8, s));


//    return 0;
//}

int find_max_array(int size, int a[])
{
    int tmp = -999999999;
    for(int i=0;i<size;i++)
        if(tmp < a[i])
            tmp = a[i];
    return tmp;
}
