#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int i,index=-1;
	char a,s[81];
	scanf("%c",&a);
	getchar();
	gets(s);
	int length=strlen(s);
	for(i=0; i<length; i++)
		if(a==s[i])
			index=i;
    if(index!=-1)
        printf("index = %d", index);
    else
        printf("Not Found");

	return 0;
}
