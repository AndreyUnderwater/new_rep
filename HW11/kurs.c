
#include <stdio.h>
#include <stdint.h>

typedef struct
{
    uint16_t year;
    uint8_t  month;
    uint8_t  day;
    uint8_t  hour;
    uint8_t  minutes;
    int8_t   t;
} temperature_data;

void fread_temperature_data(void)//(temperature_date a, char* b, uint32_t n)
{
    FILE *f;
    char *filename    = "data.txt";
    char c;
    
    int n = 0, k = 0;
    uint16_t year      = 0;
    uint8_t mounth     = 0;
    uint8_t day        = 0;
    uint8_t hour       = 0;
    uint8_t minutes    = 0;
    int16_t t           = 0;
    int pow10[10] = {1000,100,10,1,1,1,1,1,1,1}; // вычисление степени двойки через массив чтобы функцию не использовать
    int8_t k_t         = 1;
    uint32_t err[3]    = {0,0,0};  
    uint32_t number    = 0;  
    
    //f = fopen("data.txt","r");
    f = fopen(filename,"r");
    
    while(  (c = fgetc(f)) != EOF )
        {
            //printf("%c %d\n",c,c);
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
			    if(day > 31 || day < 1) // проверка порогов дня
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
	    
			    number++;
			    printf("%d\t%d\t%d\t%d\t%d\t%d\n", year, mounth, day, hour,minutes,t);
     		    //printf("%d ", year);
			    k_t     = 1;
			    year    = 0;
			    mounth   = 0;
			    day     = 0;
			    hour    = 0;
			    minutes = 0;
			    t       = 0;

			    if(k>5)       //проверка на лишнюю запись
			    {
			        err[0] = 1;
			        err[2] = number;
			    }
			    
			    if(err[0] == 1)
			        printf("\nerror in stroke = %d position error = %d\n", err[2], err[1]);
			    
			    err[0] = 0;
			    err[1] = 0;
			    err[2] = 0;
			}
        }
    fclose(f);
}





int main() {

    fread_temperature_data();
    return 0;
}

