#include <stdio.h>
#include <stdlib.h>
#include<string.h>
//需要把字符串数组开到1100 否则会段错误

int main()
{
    int n;
    char s[1100];
    scanf("%d",&n);
    getchar();
    gets(s);
    int length=strlen(s),column;
    if(length%n==0)
    {
        column=length/n;
    }
    else
    {
        int i,r=length;

        column=length/n+1;
        for(i=length%n;i<n;i++)
        {
            s[r]=' ';
            r++;
        }
    }
    char antiquity[n][column];
    int i,j,k=0;
    for(i=column-1;i>=0;i--)
    {
        for(j=0;j<n;j++)
        {
            antiquity[j][i]=s[k];
            k++;
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<column;j++)
            printf("%c",antiquity[i][j]);
        printf("\n");
    }

    return 0;
}
