#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "temp_api.h"
//#include "temp_api.c"


int main(int argc, char* argv[]) 
{

    FILE *fp;
    int j2, year = 2021, month = 1;
    char s[30] = {0}; //name file
    //char s[] = "temperature_big.csv";
    uint32_t n_blok = 1000;
    float tmp2 = 0;
    char cmd = -1;
    
    // n_blok - число копий структуры температуры в памяти
    temperature_data a[n_blok];
    
    if(argc>1)
    {
        for(int i = 1; i < argc; i++)
        {
            char* str = argv[i];

            if(cmd == 'f')
            {
                
                strcpy(s, str);
                //printf("\n%s", str);
                fp = fopen(str, "r");
                if(fp == 0)
                    printf("\ndon't open file %s", str);
                else
                {
                    printf("\nfile %s is open", str);
                    if(argc == 3)
                        t_file_temperature_data(fp, a, 1000);
                }
            }
            
            if(cmd == 'y')
            {
                //printf("\n%s", str);
                j2 = sscanf(str,"%d",&year);
                //printf("\n%d",year);
                if(year < 0 || year > 2022 || j2 != 1)
                    printf("\nerror input year");    
            }

            if(cmd == 'c')
            {
                if((j2 = strcmp(str,"middle-t-month")) == 0)
                   tmp2 = middle_t_mounth_temperature_data(fp, a, month, year, n_blok);
                else
                    printf("\nerror command");
                if((j2 = strcmp(str,"max-t-month")) == 0)
                    j2 = max_t_mounth_temperature_data(fp, a, month, year, n_blok);
                else
                    printf("\nerror command");
                if((j2 = strcmp(str,"min-t-month")) == 0)
                    j2 = min_t_mounth_temperature_data(fp, a, month, year, n_blok);
                else
                    printf("\nerror command");
                if((j2 = strcmp(str,"middle-t-year")) == 0)
                    tmp2 = middle_t_year_temperature_data(fp, a, year, n_blok);
                else
                    printf("\nerror command");
                if((j2 = strcmp(str,"max-t-year")) == 0)
                    j2 = max_t_year_temperature_data(fp, a, year, n_blok);
                else
                    printf("\nerror command");
                if((j2 = strcmp(str,"min-t-year")) == 0)
                    j2 = min_t_year_temperature_data(fp, a, year, n_blok);
                else
                    printf("\nerror command");
            }

            if(cmd == 'm')
            {
                if((j2 = strcmp(str,"january")) == 0)
                    month = 1;
                else
                    printf("\nerror month in command");
                if((j2 = strcmp(str,"february")) == 0)
                    month = 2;
                else
                    printf("\nerror month in command");
                if((j2 = strcmp(str,"march")) == 0)
                    month = 3;
                else
                    printf("\nerror month in command");
                if((j2 = strcmp(str,"april")) == 0)
                    month = 4;
                else
                    printf("\nerror month in command");
                if((j2 = strcmp(str,"may")) == 0)
                    month = 5;
                else
                    printf("\nerror month in command");
                if((j2 = strcmp(str,"june")) == 0)
                    month = 6;
                else
                    printf("\nerror month in command");
                if((j2 = strcmp(str,"july")) == 0)
                    month = 7;
                else
                    printf("\nerror month in command");
                if((j2 = strcmp(str,"august")) == 0)
                    month = 8;
                else
                    printf("\nerror month in command");
                if((j2 = strcmp(str,"september")) == 0)
                    month = 9;
                else
                    printf("\nerror month in command");
                if((j2 = strcmp(str,"october")) == 0)
                    month = 10;
                else
                    printf("\nerror month in command");
                if((j2 = strcmp(str,"november")) == 0)
                    month = 11;
                else
                    printf("\nerror month in command");
                if((j2 = strcmp(str,"december")) == 0)
                    month = 12;
                else
                    printf("\nerror month in command");
            }

            cmd = 0;
            
            if(str[0]=='-')
            {
                if(str[1]=='h')
                {
                    printf("\n\n-h                        /output help info");
                    printf("\n\n-c middle_t_month         /seach middle t for month (january)");
                    printf("\n\n-c max_t_month            /seach maximum t for month (january)");
                    printf("\n\n-c min_t_month            /seach minimum t for month (january)");
                    printf("\n\n-c middle_t_year          /seach middle t for year (2022)");
                    printf("\n\n-c max_t_year             /seach middle t for year (2022)");
                    printf("\n\n-c min_t_year             /seach middle t for year (2022)");
                    printf("\n\n-y 2021                   /input year for seach");
                    printf("\n\n-m january                /input year for seach");
                    printf("\n\n-f file_name              /input file_name for seach");
                    printf("\n\n...........example.....................");
                    printf("\n\n*.* -c max_t_month -y 2021 -m february -f data.csf");
                    printf("\n\n*.* -c max_t_year -y 2012 -f data2.csf\n");
                    
                    
                }                     
                if(str[1]=='f')
                    cmd = 'f';
                if(str[1]=='c')
                    cmd = 'c';
                if(str[1]=='y')
                    cmd = 'y';
                if(str[1]=='m')
                    cmd = 'm';
               if(str[1]=='e')
               {
                   //printf("\nerror open file%d",fp); 
                   FILE* fp2;
                   fp2 = fopen("temp.tmp", "w");
                   t_save_file_temperature_data(fp, fp2, a, 1000);
                   fclose(fp);
                   fclose(fp2);
                   fp = fopen(s, "w");
                   fp2 = fopen("temp.tmp", "r");
                   t_save_file_temperature_data(fp2, fp, a, 1000);
                   fclose(fp);
                   fclose(fp2);
               }
            }
        }
    }
    else
    {
        printf("\nfor more information input parameter -h");
    }
    

    
    
    
    
    //f = fopen(s,"r");
    
    //t_seek[0]=0;
    
    //tmp2 = min_t_mounth_temperature_data(f, a, january, 2021, 100);
    //min_t_year_temperature_data(f, a, 2021, 1000);

    
    fclose(fp);
    return 0;
}






