#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "temp_api.h"



//функция записи промежуточного файла с исправными полями. Число структур в n
void t_save_file_temperature_data(FILE* f, FILE* f2, temperature_data* a, uint32_t n)
{
    uint32_t number = 0, tmp;
    uint32_t t_seek[1], kol_str[1], n_blok = 0;

    t_seek[0] = 0;
    //t_seek[0]  - число след позиции в файле, читает блоками по n
    //kol_str[0] - кол-во прочитанных без ошибок строк файла
    //n_blok     - кол-во блоков, для правильного отображения ошибочной строки
    
    while(tmp != -1)
    {
        tmp = fread_temperature_data(f, a,  t_seek[0],  n, t_seek, kol_str, n_blok);
        
        number += kol_str[0];
        t_seek[0]--;
        n_blok++;

        for(int i = 0; i < kol_str[0]; i++)
        {
            fprintf(f2,"%d",a[i].year);
            fprintf(f2,";");
            fprintf(f2,"%d",a[i].mounth);
            fprintf(f2,";");
            fprintf(f2,"%d",a[i].day);
            fprintf(f2,";");
            fprintf(f2,"%d",a[i].hour);
            fprintf(f2,";");
            fprintf(f2,"%d",a[i].minutes);
            fprintf(f2,";");
            fprintf(f2,"%d",a[i].t);
            fprintf(f2,"\n");
        }
    }

    printf("\nwrite %d strok in file",number);
}



//функция расчета мин макс и средней температуры по всему файлу. Число структур в n
int t_file_temperature_data(FILE* f, temperature_data* a, uint32_t n)
{
    int min_t = 200;
    int max_t = -200;
    int summ_t = 0;
    uint32_t number = 0, tmp;
    uint32_t t_seek[1], kol_str[1], n_blok = 0;
    char err = 0;

    t_seek[0] = 0;
    //t_seek[0]  - число след позиции в файле, читает блоками по n
    //kol_str[0] - кол-во прочитанных без ошибок строк файла
    //n_blok     - кол-во блоков, для правильного отображения ошибочной строки
    
    while(tmp != -1)
    {
        tmp = fread_temperature_data(f, a,  t_seek[0],  n, t_seek, kol_str, n_blok);
        
        number += kol_str[0];
        t_seek[0]--;
        n_blok++;
        for(int i=0; i<kol_str[0]; i++)
        {
            if(min_t > a[i].t)
            {
                min_t = a[i].t;
            }
            if(max_t < a[i].t)
            {
                max_t = a[i].t;
            }
            summ_t += a[i].t;
        }
    }
    printf("\nmin    temperature all file = %d",min_t);
    printf("\nmax    temperature all file = %d",max_t);
    printf("\nmiddle temperature all file = %f",(float)summ_t/(float)number);
    printf("\nread %d strok in input file",number);

    return 0;
}


//функция расчета минимальной температуры за год. Ищет в переданном массиве структур. Число структур в n
int min_t_year_temperature_data(FILE* f, temperature_data* a, int year, uint32_t n)
{
    int min_t = 200;
    uint32_t number = 0, tmp;
    uint32_t t_seek[1], kol_str[1], n_blok = 0;
    char err = 0;

    t_seek[0] = 0;
    //t_seek[0]  - число след позиции в файле, читает блоками по n
    //kol_str[0] - кол-во прочитанных без ошибок строк файла
    //n_blok     - кол-во блоков, для правильного отображения ошибочной строки
    while(tmp != -1)
    {
        tmp = fread_temperature_data(f, a,  t_seek[0],  n, t_seek, kol_str, n_blok);
        
        number += kol_str[0];
        t_seek[0]--;
        n_blok++;
        for(int i=0; i<kol_str[0]; i++)
            //if(a[i].year == year)
                if(a[i].year == year)
                {
                    if(min_t > a[i].t)
                    {
                        err = 1;
                        min_t = a[i].t;
                    }
                }
    }
    if(err == 0)
        printf("\nyear not found, max temperature is error");

    printf("\nmin temperature = %d  year - %d",min_t, year);

    printf("\nread %d strok in input file",number);
    
    return min_t;
}




//функция расчета максимальной температуры за год. Ищет в переданном массиве структур. Число структур в n
int max_t_year_temperature_data(FILE* f, temperature_data* a, int year, uint32_t n)
{
    int max_t = -200;
    uint32_t number = 0, tmp;
    uint32_t t_seek[1], kol_str[1], n_blok = 0;
    char err = 0;

    t_seek[0] = 0;
    //t_seek[0]  - число след позиции в файле, читает блоками по n
    //kol_str[0] - кол-во прочитанных без ошибок строк файла
    //n_blok     - кол-во блоков, для правильного отображения ошибочной строки
    while(tmp != -1)
    {
        tmp = fread_temperature_data(f, a,  t_seek[0],  n, t_seek, kol_str, n_blok);
        
        number += kol_str[0];
        t_seek[0]--;
        n_blok++;
        for(int i=0; i<kol_str[0]; i++)
            //if(a[i].year == year)
                if(a[i].year == year)
                {
                    if(max_t < a[i].t)
                    {
                        err = 1;
                        max_t = a[i].t;
                    }
                }
    }
    if(err == 0)
        printf("\nyear not found, max temperature is error");

    printf("\nmax temperature = %d  year - %d",max_t, year);

    printf("\nread %d strok in input file",number);
    return max_t;
}



//функция расчета средней температуры за год. Ищет в переданном массиве структур. Число структур в n
float middle_t_year_temperature_data(FILE* f, temperature_data* a, int year, uint32_t n)
{
    int summ_t = 0;
    uint32_t number = 0, tmp;
    uint32_t t_seek[1], kol_str[1], n_blok = 0;
    char err = 0;

    t_seek[0] = 0;
    //t_seek[0]  - число след позиции в файле, читает блоками по n
    //kol_str[0] - кол-во прочитанных без ошибок строк файла
    //n_blok     - кол-во блоков, для правильного отображения ошибочной строки
    while(tmp != -1)
    {
        tmp = fread_temperature_data(f, a,  t_seek[0],  n, t_seek, kol_str, n_blok);
        
        number += kol_str[0];
        t_seek[0]--;
        n_blok++;
        for(int i=0; i<kol_str[0]; i++)
            //if(a[i].year == year)
                if(a[i].year == year)
                    {
                        err = 1;
                        summ_t += a[i].t;
                    }
                }
    if(err == 0)
        printf("\nyear not found, middle temperature is error");

    printf("\nmiddle temperature = %f  year - %d",(float)summ_t/(float)number, year);
    printf("\nread %d strok in input file",number);
    return (float)summ_t/((float)number);
}




//функция расчета минимальной температуры за месяц. Ищет в переданном массиве структур. Число структур в n
int min_t_mounth_temperature_data(FILE* f, temperature_data* a, int mounth, int year, uint32_t n)
{
    int min_t = 200;
    uint32_t number = 0, tmp;
    uint32_t t_seek[1], kol_str[1], n_blok = 0;
    char err = 0;

    t_seek[0] = 0;
    //t_seek[0]  - число след позиции в файле, читает блоками по n
    //kol_str[0] - кол-во прочитанных без ошибок строк файла
    //n_blok     - кол-во блоков, для правильного отображения ошибочной строки
    while(tmp != -1)
    {
        tmp = fread_temperature_data(f, a,  t_seek[0],  n, t_seek, kol_str, n_blok);
        
        number += kol_str[0];
        t_seek[0]--;
        n_blok++;
        for(int i=0; i<kol_str[0]; i++)
            if(a[i].year == year)
                if(a[i].mounth == mounth)
                {
                    if(min_t > a[i].t)
                    {
                        err = 1;
                        min_t = a[i].t;
                    }
                }
    }
    if(err == 0)
        printf("\nmonth not found, max temperature is error");

    if(mounth == 1)
        printf("\nmin temperature of january = %d  year - %d",min_t, year);
    if(mounth == 2)
        printf("\nmin temperature of february = %d   year - %d",min_t, year);
    if(mounth == 3)
        printf("\nmin temperature of march = %d  year - %d",min_t, year);
    if(mounth == 4)
        printf("\nmin temperature of april = %d  year - %d",min_t, year);
    if(mounth == 5)
        printf("\nmin temperature of may = %d  year - %d",min_t, year);
    if(mounth == 6)
        printf("\nmin temperature of june = %d  year - %d",min_t, year);
    if(mounth == 7)
        printf("\nmin temperature of july = %d  year - %d",min_t, year);
    if(mounth == 8)
        printf("\nmin temperature of august = %d  year - %d",min_t, year);
    if(mounth == 9)
        printf("\nmin temperature of september = %d  year - %d",min_t, year);
    if(mounth == 10)
        printf("\nmin temperature of november = %d  year - %d",min_t, year);
    if(mounth == 11)
        printf("\nmin temperature of october = %d  year - %d",min_t, year);
    if(mounth == 12)
        printf("\nmin temperature of december = %d  year - %d",min_t, year);

    printf("\nread %d strok in input file",number);
    
    return min_t;
}




//функция расчета максимальной температуры за месяц. Ищет в переданном массиве структур. Число структур в n
int max_t_mounth_temperature_data(FILE* f, temperature_data* a, int mounth, int year, uint32_t n)
{
    int max_t = -200;
    uint32_t number = 0, tmp;
    uint32_t t_seek[1], kol_str[1], n_blok = 0;
    char err = 0;

    t_seek[0] = 0;
    //t_seek[0]  - число след позиции в файле, читает блоками по n
    //kol_str[0] - кол-во прочитанных без ошибок строк файла
    //n_blok     - кол-во блоков, для правильного отображения ошибочной строки
    while(tmp != -1)
    {
        tmp = fread_temperature_data(f, a,  t_seek[0],  n, t_seek, kol_str, n_blok);
        
        number += kol_str[0];
        t_seek[0]--;
        n_blok++;
        for(int i=0; i<kol_str[0]; i++)
            if(a[i].year == year)
                if(a[i].mounth == mounth)
                {
                    if(max_t < a[i].t)
                    {
                        err = 1;
                        max_t = a[i].t;
                    }
                }
    }
    if(err == 0)
        printf("\nmonth not found, max temperature is error");

    if(mounth == 1)
        printf("\nmax temperature of january = %d  year - %d",max_t, year);
    if(mounth == 2)
        printf("\nmax temperature of february = %d   year - %d",max_t, year);
    if(mounth == 3)
        printf("\nmax temperature of march = %d  year - %d",max_t, year);
    if(mounth == 4)
        printf("\nmax temperature of april = %d  year - %d",max_t, year);
    if(mounth == 5)
        printf("\nmax temperature of may = %d  year - %d",max_t, year);
    if(mounth == 6)
        printf("\nmax temperature of june = %d  year - %d",max_t, year);
    if(mounth == 7)
        printf("\nmax temperature of july = %d  year - %d",max_t, year);
    if(mounth == 8)
        printf("\nmax temperature of august = %d  year - %d",max_t, year);
    if(mounth == 9)
        printf("\nmax temperature of september = %d  year - %d",max_t, year);
    if(mounth == 10)
        printf("\nmax temperature of november = %d  year - %d",max_t, year);
    if(mounth == 11)
        printf("\nmax temperature of october = %d  year - %d",max_t, year);
    if(mounth == 12)
        printf("\nmax temperature of december = %d  year - %d",max_t, year);

    printf("\nread %d strok in input file",number);
    return max_t;
}






//функция расчета средней температуры за месяц. Ищет в переданном массиве структур. Число структур в n
float middle_t_mounth_temperature_data(FILE* f, temperature_data* a, int mounth, int year, uint32_t n)
{
    int summ_t = 0;
    uint32_t number = 0, tmp;
    uint32_t t_seek[1], kol_str[1], n_blok = 0;
    char err = 0;

    t_seek[0] = 0;
    //t_seek[0]  - число след позиции в файле, читает блоками по n
    //kol_str[0] - кол-во прочитанных без ошибок строк файла
    //n_blok     - кол-во блоков, для правильного отображения ошибочной строки
    while(tmp != -1)
    {
        tmp = fread_temperature_data(f, a,  t_seek[0],  n, t_seek, kol_str, n_blok);
        
        number += kol_str[0];
        t_seek[0]--;
        n_blok++;
        for(int i=0; i<kol_str[0]; i++)
            if(a[i].year == year)
                if(a[i].mounth == mounth)
                    {
                        err = 1;
                        summ_t += a[i].t;
                    }
                }
    if(err == 0)
        printf("\nmonth not found, middle temperature is error");
    //number++;
    //printf("\n%d",number);
    if(mounth == 1)
        printf("\nmiddle temperature of january = %f  year - %d",(float)summ_t/(float)number, year);
    if(mounth == 2)
        printf("\nmiddle temperature of february = %f  year - %d",(float)summ_t/(float)number, year);
    if(mounth == 3)
        printf("\nmiddle temperature of march = %f  year - %d",(float)summ_t/(float)number, year);
    if(mounth == 4)
        printf("\nmiddle temperature of april = %f  year - %d",(float)summ_t/(float)number, year);
    if(mounth == 5)
        printf("\nmiddle temperature of may = %f  year - %d",(float)summ_t/(float)number, year);
    if(mounth == 6)
        printf("\nmiddle temperature of june = %f  year - %d",(float)summ_t/(float)number, year);
    if(mounth == 7)
        printf("\nmiddle temperature of july = %f  year - %d",(float)summ_t/(float)number, year);
    if(mounth == 8)
        printf("\nmiddle temperature of august = %f  year - %d",(float)summ_t/(float)number, year);
    if(mounth == 9)
        printf("\nmiddle temperature of september = %f  year - %d",(float)summ_t/(float)number, year);
    if(mounth == 10)
        printf("\nmiddle temperature of november = %f  year - %d",(float)summ_t/(float)number, year);
    if(mounth == 11)
        printf("\nmiddle temperature of october = %f  year - %d",(float)summ_t/(float)number, year);
    if(mounth == 12)
        printf("\nmiddle temperature of december = %f  year - %d",(float)summ_t/(float)number, year);

    printf("\nread %d strok in input file",number);
    return (float)summ_t/((float)number);
}

//отрабатывает только одинарные ошибки в строке, если ошибок много в строке, находит дефектную строку, но не конкретную дефектную запись
uint32_t fread_temperature_data(FILE* f, temperature_data* a,  uint32_t number_start,  uint32_t number_offset, uint32_t* t_seek, uint32_t* kol_str, uint32_t n_blok)
{
    //FILE *f;
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
    
    if(number_offset == 0)  //если 0, то читать весь файл целиком
        number_offset = -1;
    

    fseek(f, number_start, SEEK_SET);
    number = 0;
    while(  (c = fgetc(f)) != EOF && number < number_offset)
        {
            //printf("\n%d %c", ftell(f), c);
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
                //printf("# %d\tyear %d\tmounth %d\tday %d\t   hour %d\t   minutes %d\t   t= %d\n",number + n_blok * number_offset, year, mounth, day, hour,minutes,t);
                if(err[0] == 1)
                {
                    printf("\nerror in input file in stroke = %d\n", err[2] + n_blok * number_offset);
                    printf("# %d\tyear %d\tmounth %d\tday %d\t   hour %d\t   minutes %d\t   t= %d\n",number + n_blok * number_offset, year, mounth, day, hour,minutes,t);
                }
                number++;
                //printf("%d ", year);
                k_t      = 1;
                year     = 0;
                mounth   = 0;
                day      = 0;
                hour     = 0;
                minutes  = 0;
                t        = 0;

                
                
                err[0] = 0;
                err[1] = 0;
                err[2] = 0;
            }
        }
    t_seek[0] = ftell(f);

    kol_str[0] = number2;
    if(c == EOF)
        return -1;
    else
        return 0;
}


