//Написать только одну логическую функцию, которая определяет, верно ли, что среди элементов массива есть два одинаковых. Если ответ «да», функция возвращает 1; если ответ «нет», то 0. Строго согласно прототипу:
//int is_two_same(int size, int a[]);
//#include <stdio.h>


//int is_two_same(int size, int a[]);

//int main() {

//    int s[9] = {-66,-88,-99,-22,-1,-89,-67,-5,-88};

//    printf("%d", is_two_same(9, s));


//    return 0;
//}

int is_two_same(int size, int a[])
{
    int tmp = 0;
    for(int i=0;i<size;i++)
        for(int j=i+1;j<size;j++)
            if(a[i]==a[j])
                    tmp = 1;
    return tmp;
}
