#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char a[100];
    char m;
    gets(a);
    scanf("%c",&m);
    int length=strlen(a),i,count=0;
    for(i=0;i<length;i++)
    {
        if(a[i]==m)
            count++;
    }
    printf("%d",count);
    return 0;
}
