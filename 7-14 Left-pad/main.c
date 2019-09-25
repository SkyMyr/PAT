#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    char c,ch[100010];
	int i,l,n;
	scanf("%d %c",&n,&c);
	getchar();
	gets(ch);
	l=strlen(ch);
	if(l<n)
	{
		for(i=0;i<n-l;i++)
		{
			printf("%c",c);
		}
		puts(ch);
	}else
	{
		for(i=l-n;i<l;i++)
		{
			printf("%c",ch[i]);
		}
	}
	return 0;
}
