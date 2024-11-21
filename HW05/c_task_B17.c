//Ввести натурально число и напечатать все числа от 10 до введенного числа - у которых сумма цифр равна произведению цифр

#include <stdio.h>

 
int main() {
    int s, tmp, summ=0, mul=1, i;
    
    scanf("%d", &s);
	
	for(i=10; i<=s; i++)
	{
	    tmp = i;
	    while(tmp > 0)
	    {
		    summ += tmp%10;
		    mul  *= tmp%10;
		    tmp /= 10;
		}
		
		if(summ == mul)
		{
		    printf("%d ", i);
        }
        summ = 0;
        mul = 1;
    }
    return 0;
}
