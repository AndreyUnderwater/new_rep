//Проверить строку состоящую из скобок "(" и ")" на корректность.

void chet(int);

#include <stdio.h>

int main (void) {
	char s;
	int s1 = 0, s2 = 0;
    
    while((s = getchar()) != '.')
    {
	    
	    if(s == ')' && s1 < 1)
	    {
		    break;
		}
	    
	    if (s == '(')
	    {
		    s1 += 1;
		}
		if(s == ')')
		{
		    s2 += 1;
		}
	}
	
	if((s1+s2) == 0)
	{
	    printf("NO");
	}
	else
	{
		if(s1==s2)
		{
		    printf("YES");
		}
		else
		{
			printf("NO");
		}
	}
    
    return 0;
}
