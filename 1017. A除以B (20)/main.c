#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
����Ҫ�����A/B������A�ǲ�����1000λ����������B��1λ������������Ҫ�������Q������R��ʹ��A = B * Q + R������

�����ʽ��

������1�������θ���A��B���м���1�ո�ָ���

�����ʽ��

��1�����������Q��R���м���1�ո�ָ���
����������

123456789050987654321 7

���������

17636684150141093474 3
*/

int main()
{
    char a[1001];
    int b,i,len,yu=0,flag=0;
    scanf("%s%d",a,&b);
    len=strlen(a);
    for(i=0;i<len;i++)
    {
        yu=a[i]-'0'+yu*10;
        if(yu>=b)
        {
            printf("%d",yu/b);
            flag=1;
        }
        else if(flag)
        {
            printf("0");
        }
        yu=yu%b;
    }
    if(flag==0)
        printf("0");
    printf(" %d",yu);
    return 0;
}
