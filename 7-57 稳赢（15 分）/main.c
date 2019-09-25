#include <stdlib.h>
#include<stdio.h>
#include<string.h>

char b[3][10]={"ChuiZi","Bu","JianDao"};

int main()
{
	int i=0,n;
	scanf("%d",&n);
	char a[10];
	char  c[4]="End";
	scanf("%s",a);
	while(1)
	{

		if(strcmp(a,c)==0)
		{
			break;
		}
		else
		{

				if(i==n)
				{
						printf("%s\n",a);
						i=0;
						scanf("%s",a);
				}
				else
				{
					if(strcmp(a,b[0])==0)
					{
						printf("%s\n",b[1]);
						i++;
						scanf("%s",a);
					}
					else if(strcmp(a,b[1])==0)
					{
						printf("%s\n",b[2]);
						i++;
						scanf("%s",a);
					}
					else
					{
						printf("%s\n",b[0]);
						i++;
						scanf("%s",a);
					}
				 }
		}
	}
}
