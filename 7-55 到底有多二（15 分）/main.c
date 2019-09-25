#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i,count=0,j;
    double beishu=1;
    char a[100];
    gets(a);
    int length = strlen(a);
    if(a[0]=='-')
    {
        j=length-1;
        beishu*=1.5;
    }
    else
        j=length;
    if((a[length-1]-48)%2==0)
        beishu*=2;
    for(i=0;i<length;i++)
    {
        if(a[i]=='2')
        {
            count++;
        }
    }
    //printf("%d %d %lf\n",j,count,beishu);
    double result = (double)count/(double)j*beishu;
    printf("%.2lf",result*100);
    printf("%%");
    return 0;
}
