/*


����̽����Ħ˹�ӵ�һ����ֵ�������������Լ��ɣ� 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm����
����̽�ܿ�������ˣ���������ֵ�����ʵ���Ͼ���Լ���ʱ�䡰������ 14:04����
��Ϊǰ�����ַ����е�1����ͬ�Ĵ�дӢ����ĸ����Сд�����֣��ǵ�4����ĸ'D'�����������ģ�
��2����ͬ���ַ���'E'�����ǵ�5��Ӣ����ĸ������һ����ĵ�14����ͷ������һ���0�㵽23��������0��9���Լ���д��ĸA��N��ʾ����
�������ַ�����1����ͬ��Ӣ����ĸ's'�����ڵ�4��λ�ã���0��ʼ�������ϣ������4���ӡ��ָ��������ַ��������������Ħ˹����õ�Լ���ʱ�䡣

�����ʽ��

������4���зֱ����4���ǿա��������ո��ҳ��Ȳ�����60���ַ�����

�����ʽ��

��һ�������Լ���ʱ�䣬��ʽΪ��DAY HH:MM�������С�DAY����ĳ���ڵ�3�ַ���д����MON��ʾ����һ��TUE��ʾ���ڶ���WED��ʾ��������THU��ʾ�����ģ�FRI��ʾ�����壬SAT��ʾ��������SUN��ʾ�����ա�
��Ŀ���뱣֤ÿ�����Դ���Ψһ�⡣
����������

3485djDkxh4hhGE
2984akDfkkkkggEdsb
s&hgsfdk
d&Hyscvnm

���������

THU 14:04


*/

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int mm;
char day,hh,a[60],b[60],c[60],d[60];
void search1()
{
    int i,p,count=0;
    for(i=0;i<strlen(a)&&i<strlen(b);i++)
    {
            if(count==0&&'A'<=a[i]&&a[i]<='G'&&a[i]==b[i])
            {
                day=a[i];
                count++;
                for(p=i+1;p<strlen(a)&&p<strlen(b);p++)
                {

                        if(count==1&&(('A'<=a[p]&&a[p]<='N')||('0'<=a[p]&&a[p]<='9'))&&a[p]==b[p])
                        {
                            hh=a[p];
                            //printf("p=%d,q=%dhh=%c\n",p,q,hh);
                            return ;
                        }

                }
            }
    }
}
void search2()
{
    int i;
    for(i=0;i<strlen(c)&&i<strlen(d);i++)
    {
            if(c[i]==d[i])//65<=c[i]&&c[i]<=90||97<=c[i]&&c[i]<=122 &&
            {
                if((c[i] >= 65 && c[i] <= 90) || (c[i] >= 97 && c[i] <= 122))
                {
                    mm=i;
                    printf("%02d",mm);
                    return ;
                }
                //printf("---c%d=%c d%d=%c---",i,c[i],j,d[j]);
            }
    }
}
void DAY(char week)
{
    switch(week)
    {
        case'A':printf("MON ");break;
        case'B':printf("TUE ");break;
        case'C':printf("WED ");break;
        case'D':printf("THU ");break;
        case'E':printf("FRI ");break;
        case'F':printf("SAT ");break;
        case'G':printf("SUN ");break;
        default:printf("error!\n");break;
    }
}
void HH(char hour)
{
    int count=10;
    char i;
    if(hour>='0'&&hour<='9')
    {
        printf("0%c:",hour);
    }
    else
    {
        for(i='A';i<='N';i++)
        {
            if(hour==i)
            {
                printf("%d:",count);
                return;
            }
            count++;
        }
    }
}
int main()
{
    scanf("%s%s%s%s",a,b,c,d);
    search1();
    DAY(day);
    HH(hh);
    search2();
    return 0;
}
