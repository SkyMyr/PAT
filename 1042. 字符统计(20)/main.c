/*


���д�����ҳ�һ�θ��������г�����Ƶ�����Ǹ�Ӣ����ĸ��

�����ʽ��

������һ���и���һ�����Ȳ�����1000���ַ������ַ�����ASCII���������ɼ��ַ����ո���ɣ����ٰ���1��Ӣ����ĸ���Իس��������س��������ڣ���

�����ʽ��

��һ�����������Ƶ����ߵ��Ǹ�Ӣ����ĸ������ִ���������Կո�ָ�������в��У����������ĸ����С���Ǹ���ĸ��ͳ��ʱ�����ִ�Сд�����Сд��ĸ��
����������

This is a simple TEST.  There ARE numbers and other symbols 1&2&3...........

���������

e 7

*/

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
char a[1010];
struct data
{
    int n;
    char Letter;
}b[26],*aa,*bb;
int comp(const void *a,const void *b)
{
    aa=(struct data *)a;
    bb=(struct data *)b;
    if(aa->n==bb->n)
        return aa->Letter-bb->Letter;
    return bb->n-aa->n;
}
int cmp(const void *a,const void *b)
{
    return *(char *)a - *(char *)b;
}
int main()
{
    int i,p=0;
    gets(a);
    for(i=0;i<strlen(a);i++)
    {
        if(a[i]>=65&&a[i]<=90)
            a[i]=a[i]+32;
    }
    qsort(a,strlen(a),sizeof(a[0]),cmp);
    for(i=0;i<26;i++)
    {
        b[i].n=0;
    }
    for(i=0;i<strlen(a);i++)
    {
        if(a[i]>=97&&a[i]<=122)
        {
            int k=1;
            for(;i<strlen(a);i++)
            {
                if(a[i+1]==a[i])
                    k++;
                else
                {
                    b[p].Letter=a[i];
                    b[p].n=k;
                    p++;
                    break;
                }
            }
        }
    }
    qsort(b,p,sizeof(b[0]),comp);
    printf("%c %d",b[0].Letter,b[0].n);
    return 0;
}
