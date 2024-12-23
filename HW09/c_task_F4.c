//Написать только одну функцию. Всю программу отправлять не надо. Вывести в порядке возрастания цифры, входящие в строку. Цифра - количество. Функция должно строго соответствовать прототипу:
//void print_digit(char s[]).
//#include <stdio.h>


//void print_digit(char s[]);

//int main() {

//    char s[] = "8768768hfjhfjhf097975753643888888888888888888888888888888888888888888888888888888888888888888888";

//    print_digit(s);


//    return 0;
//}

void print_digit(char s[])
{
    int tmp, n=0;;
    while(s[n] != 0)
        n++;
    
    for(char k = '0'; k <= '9'; k++)
    {    
        tmp = 0;
        for(int j = 0; j < n; j++)
        {
            if(k == s[j])
                tmp++;  
        }
        if(tmp>0)
            printf("%c %d\n", k, tmp);
    }
}
