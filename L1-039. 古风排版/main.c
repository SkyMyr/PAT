/*


�й��Ĺ���д���֣��Ǵ������������Ű�ġ�����������д���򣬰�һ�����ְ��ŷ��Ű档

�����ʽ��

�����ڵ�һ�и���һ��������N��<100������ÿһ�е��ַ������ڶ��и���һ�����Ȳ�����1000�ķǿ��ַ������Իس�������

�����ʽ��

���ŷ��ʽ�Ű�������ַ�����ÿ��N���ַ����������һ�п��ܲ���N����
����������

4
This is a test case

���������

asa T
st ih
e tsi
 ce s

*/
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
//��Ҫ���ַ������鿪��1100 �����δ���
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

//ֱ�Ӳ����ö��⿪�ַ�������ռ�
int main()
{
    int n;
    char s[1000];
    scanf("%d",&n);
    getchar();
    gets(s);
    //printf("%c\n",s[16]);
    int length=strlen(s),column;
    //printf("%d\n",length);
    if(length%n==0)
    {
        column=length/n;
    }
    else
    {
        column=length/n+1;
    }
    char antiquity[n][column];
    int i,j,k=0;
    for(i=column-1;i>=0;i--)
    {
        for(j=0;j<n;j++)
        {
            if(k<length)
            {
                antiquity[j][i]=s[k];
                k++;
            }
            else
                antiquity[j][i]=' ';
            //printf("%c\n",antiquity[j][i]);
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
