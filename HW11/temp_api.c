#include <stdio.h>
#include <stdint.h>
#include "temp_api.h"


//функция расчета минимальной температуры за месяц. Ищет в переданном массиве структур. Число структур в number
int min_t_year_temperature_data(temperature_data* a, int year, uint32_t number)
{
    int tmp = 99;
    
    for(uint32_t i = 0; i < number; i++)
    {
        if(a[i].year == year)
        {
            if(tmp > a[i].t)
                tmp = a[i].t;
        }
    }
    return tmp;
}


//функция расчета максимальной температуры за месяц. Ищет в переданном массиве структур. Число структур в number
int max_t_year_temperature_data(temperature_data* a, int year, uint32_t number)
{
    int tmp = -99;
    
    for(uint32_t i = 0; i < number; i++)
    {
        if(a[i].year == year)
        {
            if(tmp < a[i].t)
                tmp = a[i].t;
        }
    }
    return tmp;
}

//функция расчета средней температуры за месяц. Ищет в переданном массиве структур. Число структур в number
float middle_t_year_temperature_data(temperature_data* a, int year, uint32_t number)
{
    int summ = 0, tmp = 0;
    
    for(uint32_t i = 0; i < number; i++)
    {
        if(a[i].year == year)
        {
            summ += a[i].t;
            tmp++;
        }
    }
    return (float)summ/((float)tmp);
}



//функция расчета минимальной температуры за месяц. Ищет в переданном массиве структур. Число структур в number
int min_t_mounth_temperature_data(temperature_data* a, int mounth, uint32_t number)
{
    int tmp = 99;
    
    for(uint32_t i = 0; i < number; i++)
    {
        if(a[i].mounth == mounth)
        {
            if(tmp > a[i].t)
                tmp = a[i].t;
        }
    }
    return tmp;
}


//функция расчета максимальной температуры за месяц. Ищет в переданном массиве структур. Число структур в number
int max_t_mounth_temperature_data(temperature_data* a, int mounth, uint32_t number)
{
    int tmp = -99;
    
    for(uint32_t i = 0; i < number; i++)
    {
        if(a[i].mounth == mounth)
        {
            if(tmp < a[i].t)
                tmp = a[i].t;
        }
    }
    return tmp;
}



//функция расчета средней температуры за месяц. Ищет в переданном массиве структур. Число структур в number
float middle_t_mounth_temperature_data(temperature_data* a, int mounth, uint32_t number)
{
    int summ = 0, tmp = 0;
    
    for(uint32_t i = 0; i < number; i++)
    {
        if(a[i].mounth == mounth)
        {
            summ += a[i].t;
            tmp++;
        }
    }
    return (float)summ/((float)tmp);
}



//функция сравнения двух структур по дню -1 а младше b, 0 равно, 1 a старше b
int cmp_day_temperature_data(temperature_data* a, temperature_data* b)
{
    if(a->day == b->day)
        return 0;
    else
        if(a->day < b->day)
            return -1;
        else
            return 1;
}

//функция сравнения двух структур по месяцу -1 а младше b, 0 равно, 1 a старше b
int cmp_mounth_temperature_data(temperature_data* a, temperature_data* b)
{
    if(a->mounth == b->mounth)
        return 0;
    else
        if(a->mounth < b->mounth)
            return -1;
        else
            return 1;
}


//функция сравнения двух структур по году -1 а младше b, 0 равно, 1 a старше b
int cmp_year_temperature_data(temperature_data* a, temperature_data* b)
{
    if(a->year == b->year)
        return 0;
    else
        if(a->year < b->year)
            return -1;
        else
            return 1;
}



//функция просто  сравнения двух структур 0 - равны, 1 - разные
int cmp_temperature_data(temperature_data* a, temperature_data* b)
{
    int tmp = 0;
    if(a->year != b->year)
    {
        tmp |= 1;
    }
    else
    {
        if(a->mounth != b->mounth)
        {
            tmp |= 1;
        }
        else
        {
            if(a->day != b->day)
            {
                tmp |= 1;
            }
            else
            {
                if(a->hour != b->hour)
                {
                    tmp |= 1;
                }
                else
                {
                    if(a->minutes != b->minutes)
                    {
                        tmp |= 1;
                    }
                    else
                    {
                        if(a->t != b->t)
                        {
                            tmp |= 1;
                        }
                    }
                }
            }
        }
    }
    
    if(tmp == 1)
        return 1;
    else
        return 0;
}

//та же fread, но 
//uint32_t fread2_temperature_data(temperature_data* a, char* filename,  uint32_t number_start,  uint32_t number_offset)
//{

//}





//отрабатывает только одинарные ошибки в строке, если ошибок много в строке, находит дефектную строку, но не конкретную дефектную запись
uint32_t fread_temperature_data(temperature_data* a, char* filename,  uint32_t number_start,  uint32_t number_offset)
{
    FILE *f;
    //char *filename    = "data.txt";
    char c;
    
    int n = 0, k = 0;
    uint16_t year       = 0;
    uint8_t mounth      = 0;
    uint8_t day         = 0;
    uint8_t hour        = 0;
    uint8_t minutes     = 0;
    int16_t t           = 0;
    int pow10[10] = {1000,100,10,1,1,1,1,1,1,1}; // вычисление степени двойки через память, чтобы функцию не использовать
    int8_t k_t          = 1;
    uint32_t err[3]     = {0,0,0};      //поиск ошибки
    uint32_t number     = 0;            //номер считываемой строки из файла
    uint32_t number2    = 0;           //номер структуры строки 
    
    //f = fopen("data.txt","r");
    
    //printf("%d\n", a[2].year);
    f = fopen(filename,"r");
    
    if(number_offset == 0)  //если 0, то читать весь файл целиком
        number_offset = -1;
    
    if(number_start != 0)
        while(  (c = fgetc(f)) != EOF)
        {
            if(c==0xA)
            {
                number++;
                if(number >= number_start)
                    break;
            }
        }
    
    number = 0;
    while(  (c = fgetc(f)) != EOF && number < number_offset)
        {
            //printf("%c %d\n",c,c);
            if(c == ' ')// вставка для big файла
                c = '0';
            
            
            
            if(c != 0x0A)
            {
                if(c != ';')
                {
                    //printf("%d", k);
                    if(c>='0' || c <= '9')
                    {
                        //printf("%d", k);
                        if(k == 0)
                        {
                            if(n > 3)
                            {
                                err[0] = 1; // ошибка в числе цифр года
                                err[1] = k;
                                err[2] = number;
                            }
                            year    += (c - '0') * pow10[n];
                        }
                        if(k == 1)
                        {
                            if(n > 1)
                            {
                                err[0] = 1; // ошибка в числе цифр месяца
                                err[1] = k;
                                err[2] = number;
                            }
                            if(n == 0)
                                mounth   = (c - '0');
                            else
                                mounth   = (c - '0') + (mounth * 10);
                        }
                        if(k == 2)
                        {
                            if(n > 1)
                            {
                                err[0] = 1; // ошибка в числе цифр дня
                                err[1] = k;
                                err[2] = number;
                            }
                            if(n == 0)
                                day     = (c - '0');
                            else
                                day     = (c - '0') + (day * 10);
                        }
                        if(k == 3)
                        {
                            if(n > 1)
                            {
                                err[0] = 1; // ошибка в числе цифр часа
                                err[1] = k;
                                err[2] = number;
                            }
                            if(n == 0)
                                hour    = (c - '0');
                            else
                            hour    = (c - '0') + hour * 10;
                        }
                        if(k == 4)
                        {
                            if(n > 1)
                            {
                                err[0] = 1; // ошибка в числе цифр минут
                                err[1] = k;
                                err[2] = number;
                            }
                            if(n == 0)
                                minutes = (c - '0');
                            else
                                minutes = (c - '0') + minutes * 10;
                        }
                    }
                    else
                    {
                        if(k<5)
                        {
                            err[0] = 1; ///ошибка в строке
                            err[1] = k;
                            err[2] = number;
                        }
                    }
                    
                    if(k==5)
                    {
                        if(c=='-')
                            k_t = -1;
                        else
                            if(n == 0)
                                t = (c - '0') * k_t;
                            else
                                t = (c - '0') * k_t + t * 10;
                    }
                    n++;
                }
                else  // конец двоеточия
                {
                    //printf("%d ", year);
                    n = 0;
                    k++;
                }
            }
            else  // конец строки
            {
                k = 0;
                n = 0;
                if(mounth > 12 || mounth < 1) // проверка порогов месяцв
                {
                    err[0] = 1;
                    err[1] = 1;
                    err[2] = number;
                }
                if(mounth==1 || mounth==3 || mounth==5 || mounth==7 || mounth==8 ||mounth==10 ||mounth==12)    
                    if(day > 31 || day < 1) // проверка порогов дня месяцев=31
                    {
                        err[0] = 1;
                        err[1] = 2;
                        err[2] = number;
                    }
                if(mounth==4 || mounth==6 || mounth==9 || mounth==11)    
                    if(day > 30 || day < 1) // проверка порогов дня месяцев=30
                    {
                        err[0] = 1;
                        err[1] = 2;
                        err[2] = number;
                    }
                if(mounth==2)    
                    if(day > 29 || day < 1) // проверка порогов дня февраля
                    {
                        err[0] = 1;
                        err[1] = 2;
                        err[2] = number;
                    }

                if(hour > 24 || hour < 0) // проверка порогов часов
                {
                    err[0] = 1;
                    err[1] = 3;
                    err[2] = number;
                }
                if(minutes > 60 || minutes < 0) // проверка порогов минут
                {
                    err[0] = 1;
                    err[1] = 4;
                    err[2] = number;
                }
                
                if(t > 99 || t < -99) // проверка порогов температуры
                {
                    err[0] = 1;
                    err[1] = 5;
                    err[2] = number;
                }
        
                if(k > 5)       //проверка на лишнюю запись в строке
                {
                    err[0] = 1;
                    err[2] = number;
                }

                if(err[0] != 1)
                {
                    a[number2].year    = year;
                    a[number2].mounth  = mounth;
                    a[number2].day     = day;
                    a[number2].hour    = hour;
                    a[number2].minutes = minutes;
                    a[number2].t       = t;
                    number2++;
                }
                //printf("# %d\tyear %d\tmounth %d\tday %d\t   hour %d\t   minutes %d\t   t= %d\n",number, year, mounth, day, hour,minutes,t);
                number++;
                //printf("%d ", year);
                k_t      = 1;
                year     = 0;
                mounth   = 0;
                day      = 0;
                hour     = 0;
                minutes  = 0;
                t        = 0;

                
                if(err[0] == 1)
                    printf("\nerror in stroke = %d position error = %d\n", err[2], err[1]);
                
                err[0] = 0;
                err[1] = 0;
                err[2] = 0;
            }
        }
    fclose(f);
    //if(c == EOF)
    //    return -1;
    //else
        return number2;
}
