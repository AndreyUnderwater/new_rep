#define january   1
#define february  2
#define mart      3
#define april     4
#define may       5
#define jun       6
#define july      7
#define august    8
#define september 9
#define october   10
#define november  11
#define december  12




typedef struct
{
    uint16_t year;
    uint8_t  mounth;
    uint8_t  day;
    uint8_t  hour;
    uint8_t  minutes;
    int16_t   t;
} temperature_data;


//функция расчета минимальной температуры за год. Ищет в переданном массиве структур. Число структур в number
int min_t_year_temperature_data(temperature_data* a, int, uint32_t);


//функция расчета максимальной температуры за год. Ищет в переданном массиве структур. Число структур в number
int max_t_year_temperature_data(temperature_data*, int , uint32_t);

//функция расчета средней температуры за год
float middle_t_year_temperature_data(temperature_data*, int, uint32_t);

//функция расчета минимальной температуры за месяц. Ищет в переданном массиве структур. Число структур в number
int min_t_mounth_temperature_data(temperature_data* a, int, uint32_t);


//функция расчета максимальной температуры за месяц. Ищет в переданном массиве структур. Число структур в number
int max_t_mounth_temperature_data(temperature_data*, int , uint32_t);

//функция расчета средней температуры за месяц
float middle_t_mounth_temperature_data(temperature_data*, int, uint32_t);

//функция сравнения двух структур по дню -1 а младше b, 0 равно, 1 a старше b
int cmp_day_temperature_data(temperature_data*, temperature_data*);

//функция сравнения двух структур по месяцу -1 а младше b, 0 равно, 1 a старше b
int cmp_mounth_temperature_data(temperature_data*, temperature_data*);

//функция сравнения двух структур по году -1 а младше b, 0 равно, 1 a старше b
int cmp_year_temperature_data(temperature_data*, temperature_data*);

//функция сравнения двух структур
int cmp_temperature_data(temperature_data*, temperature_data*);

// возвращает число правильно прочитанных строк из файла, строки с ошибками не записываются
uint32_t fread_temperature_data(temperature_data* a, char* filename,  uint32_t number_start,  uint32_t number_end);
