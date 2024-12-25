
#include <stdio.h>
#include <stdint.h>
#include "temp_api.h"
//#include "temp_api.c"


//typedef struct
//{
//    uint16_t year;
//    uint8_t  month;
//    uint8_t  day;
//    uint8_t  hour;
//    uint8_t  minutes;
//    int16_t   t;
//} temperature_data;



int main() {

//    FILE *f;
    char s[] = "temperature_big.csv";
    //uint32_t k = 600000;
    temperature_data a[100000];
//    a[2].year = 3;
    uint32_t tmp;
    
//    f = fopen(filename,"r");
    
//    for(int j=0;j<5;j++)
//    {
        tmp = fread_temperature_data(a, s, 500000, 100000);
//        for(int i=0;i<tmp;i++)
//        {
//          while(  (c = fgetc(f)) != EOF && number < number_offset)
          
            //printf("# %d\tyear %d\tmounth %d\tday %d\t   hour %d\t   minutes %d\t   t= %d\n",i, a[i].year, a[i].mounth, a[i].day, a[i].hour,a[i].minutes,a[i].t);
            
//        }
//    }


    printf("\nread strok = %d", tmp);
//    printf("\nmiddle t = %f", middle_t_mounth_temperature_data(a, january, tmp));
//    printf("\nmax t = %d", max_t_mounth_temperature_data(a, january, tmp));


//    fclose(f);
    return 0;
}







