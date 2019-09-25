#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char asc[26],desc[26];

int main()
{
   unsigned int a = 1,b=2,c=4,d=8,e=16,f=32,g=64,h=128;    /* 60 = 0011 1100 */
   //unsigned int b = 2;    /* 13 = 0000 1101 */
   int cc = 0;

   cc = a & b;       /* 12 = 0000 1100 */
   printf("Line 1 - c 的值是 %d\n", cc );

   cc = a | b|c|d|e|f|g|h;       /* 61 = 0011 1101 */
   printf("Line 2 - c 的值是 %d\n", cc );

   cc = a ^ b;       /* 49 = 0011 0001 */
   printf("Line 3 - c 的值是 %d\n", cc );

   cc = ~a;          /*-61 = 1100 0011 */
   printf("Line 4 - c 的值是 %d\n", cc );

   cc = a << 2;     /* 240 = 1111 0000 */
   printf("Line 5 - c 的值是 %d\n", cc );

   cc = a >> 2;     /* 15 = 0000 1111 */
   printf("Line 6 - c 的值是 %d\n", cc );

/*
    int i,j;
	char a[81];
	gets(a);
	for(i=0;i<26;i++)
	{
		asc[i]=65+i;
	}
	for(i=25,j=0;i>=0;i--,j++)
	{
		desc[j]=65+i;
	}
	for(i=0;i<strlen(a);i++)
	{
		if(a[i]>='A'&&a[i]<='Z')
		{
		    int j;
            for(j=0;j<26;j++)
            {
                if(asc[j]==a[i])
                    break;
            }
			a[i]=desc[j];
		}
	}
	puts(a);*/
	return 0;
}
