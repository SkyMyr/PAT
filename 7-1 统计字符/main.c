#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int i,letter,blank,digit,other;
	letter=blank=digit=other=0;
	for(i=0;i<10;i++)
    {
		char a=getchar();
		if((a>='a'&&a<='z')||(a>='A'&&a<='Z'))
        {
			letter++;
		}
		else if(a>='0'&&a<='9')
        {
			digit++;
		}
		else if(a==' '||a=='\n')
        {
			blank++;
		}
		else
        {
			other++;
		}
	}
	printf("letter = %d, blank = %d, digit = %d, other = %d",letter,blank,digit,other);

    return 0;
}

