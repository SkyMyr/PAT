/*
����������13���Ƽ����ģ�

    �����˵�0�������˳�Ϊtret��
    ����������1��12�Ļ����ķֱ�Ϊ��jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec��
    �����˽���λ�Ժ��12����λ���ֱַ��Ϊ��tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou��

��������˵����֡�29������ɻ����ľ��ǡ�hel mar�����������ġ�elo nov����Ӧ�������֡�115����Ϊ�˷��㽻���������д����ʵ�ֵ���ͻ�������֮��Ļ��롣

�����ʽ��

�����һ�и���һ��������N��<100�������N�У�ÿ�и���һ��[0, 169)�����ڵ����� ���� �����ǵ����ģ������ǻ����ġ�

�����ʽ��

��Ӧ�����ÿһ�У���һ���������������һ�����Ե����֡�
����������

4
29
5
elo nov
tam

���������

hel mar
may
115
13

*/

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct node
{
    char *s1;
    char *s2;
}Mars[12];
int check(char a[])
{
    if(a[0]=='0')
        printf("tret\n");
    else if(!strcmp(a,"tret"))
        printf("0\n");
    else
        return 0;
    return 1;

}
int transform_single(char p[])
{
    int i;
    for(i=0;i<12;i++)
        if(!strcmp(p,Mars[i].s1))
            return i;
    return -1;
}
int transform_tens(char p[])
{
    int i;
    for(i=0;i<12;i++)
        if(!strcmp(p,Mars[i].s2))
            return i;
    return -1;
}
int main()
{
    Mars[0].s1="jan";  Mars[0].s2="tam";
    Mars[1].s1="feb";  Mars[1].s2="hel";
    Mars[2].s1="mar";  Mars[2].s2="maa";
    Mars[3].s1="apr";  Mars[3].s2="huh";
    Mars[4].s1="may";  Mars[4].s2="tou";
    Mars[5].s1="jun";  Mars[5].s2="kes";
    Mars[6].s1="jly";  Mars[6].s2="hei";
    Mars[7].s1="aug";  Mars[7].s2="elo";
    Mars[8].s1="sep";  Mars[8].s2="syy";
    Mars[9].s1="oct";  Mars[9].s2="lok";
    Mars[10].s1="nov";  Mars[10].s2="mer";
    Mars[11].s1="dec";  Mars[11].s2="jou";
    int i,n;
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++)
    {
        char a[7];
        gets(a);
        if(!check(a))
        {
            if(atoi(a))
            {
                int b,c;
                b=atoi(a)%13;
                c=(atoi(a)%169)/13;
                if(c!=0&&b!=0)
                    printf("%s %s\n",Mars[c-1].s2,Mars[b-1].s1);
                else if(b!=0)
                    puts(Mars[b-1].s1);//printf("%s\n" Mars[b-1].s1);
                else
                    puts(Mars[c-1].s2);//printf("%s\n" Mars[c-1].s2);
            }
            else
            {
                char b[4],c[4];
                strncpy(b,a,3);
                b[3]='\0';
                if(transform_single(b)!=-1)
                    printf("%d\n",transform_single(b)+1);
                else
                {
                    if(strlen(a)>4)
                    {
                        strncpy(c,a+4,3);
                        c[3]='\0';
                        printf("%d\n",(transform_tens(b)+1)*13+transform_single(c)+1);
                    }
                    else
                        printf("%d\n",(transform_tens(b)+1)*13);
                }
            }
        }
    }
    return 0;
}
/*
���������ַ���Ϊstr1��str2��
��str1==str2���򷵻��㣻
��str1<str2���򷵻ظ�����
��str1>str2���򷵻�������*/
