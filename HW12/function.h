#define january   1
#define february  2
#define march     3
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

//функция записи промежуточного файла с исправными полями. Число структур в n
void t_save_file_temperature_data(FILE* f, FILE* f2, temperature_data* a, uint32_t n);

//функция расчета мин макс и средней температуры по всему файлу. Число структур в n
int t_file_temperature_data(FILE*, temperature_data*, uint32_t);

//функция расчета минимальной температуры за год. Ищет в переданном массиве структур. Число структур в n
int min_t_year_temperature_data(FILE*, temperature_data*, int year, uint32_t n);

//функция расчета максимальной температуры за год. Ищет в переданном массиве структур. Число структур в n
int max_t_year_temperature_data(FILE* f, temperature_data* a, int year, uint32_t n);

//функция расчета средней температуры за год. Ищет в переданном массиве структур. Число структур в n
float middle_t_year_temperature_data(FILE*, temperature_data*, int year, uint32_t n);

//функция расчета минимальной температуры за месяц. Ищет в переданном массиве структур. Число структур в n
int min_t_mounth_temperature_data(FILE*, temperature_data*, int mounth, int year, uint32_t n);


//функция расчета максимальной температуры за месяц
int max_t_mounth_temperature_data(FILE*, temperature_data*, int mounth, int year, uint32_t n);

//функция расчета средней температуры за месяц
float middle_t_mounth_temperature_data(FILE*, temperature_data*, int mounth, int year, uint32_t n);

// возвращает число правильно прочитанных строк из файла, строки с ошибками не записываются
uint32_t fread_temperature_data(FILE*, temperature_data*,  uint32_t number_start,  uint32_t number_offset, uint32_t* t_seek, uint32_t* kol_str, uint32_t n_blok);
