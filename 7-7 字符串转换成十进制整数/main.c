#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    char a[100],b[100];
    int i,j=0,flag=0,result=0;
    gets(a);
    int length=0;
    while(a[length]!='#')
    {
        length++;
    }
    //printf("%d\n",length);
    for(i=0;i<length;i++)
    {
        if(flag==0&&((a[i]<=9&&a[i]>=0)||(a[i]>='A'&&a[i]<='F')||(a[i]>='a'&&a[i]<='f')))
            break;
        if(a[i]=='-')
        {
            flag=1;
            break;
        }
    }
    for(i=0;i<length;i++)
    {
        if((a[i]<='9'&&a[i]>='0')||(a[i]>='A'&&a[i]<='F')||(a[i]>='a'&&a[i]<='f'))
        {
            b[j]=a[i];
            j++;
        }
    }
    //puts(b);
    //printf("%d",j);
    for(i=0;i<j;i++)
    {
        int num;
        if(b[i]>='0'&&b[i]<='9')
            num=pow(16,(j-1-i))*(b[i]-48);
        else
        {
            if(b[i]=='a'||b[i]=='A')
				num=(int)pow(16,(j-1-i))*10;
			else if(b[i]=='b'||b[i]=='B')
				num=(int)pow(16,(j-1-i))*11;
			else if(b[i]=='c'||b[i]=='C')
				num=(int)pow(16,(j-1-i))*12;
			else if(b[i]=='d'||b[i]=='D')
				num=(int)pow(16,(j-1-i))*13;
			else if(b[i]=='e'||b[i]=='E')
				num=(int)pow(16,(j-1-i))*14;
			else
				num=(int)pow(16,(j-1-i))*15;

        }
        //printf("%d %d %d\n",(j-1-i),(int)pow(16,(j-1-i)),num);
        result+=num;
    }
    if(flag==1&&result!=0)
        printf("-%d",result);
    else
        printf("%d",result);
    return 0;
}
