/*

����һ�����������ÿ�����ֶ�Ӧ��ƴ����������Ϊ����ʱ���������fu���֡�ʮ�����ֶ�Ӧ��ƴ�����£�

0: ling
1: yi
2: er
3: san
4: si
5: wu
6: liu
7: qi
8: ba
9: jiu

�����ʽ��

������һ���и���һ���������磺 1234 ��

��ʾ�������������������������

�����ʽ��

��һ����������������Ӧ��ƴ����ÿ�����ֵ�ƴ��֮���ÿո�ֿ�����ĩû�����Ŀո��� yi er san si��
����������

-600

���������

fu liu ling ling

*/
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void Dushuzi(char a)
{
    switch(a)
        {
        case '-':
            printf("fu");
            break;
        case '0':
            printf("ling");
            break;
        case '1':
            printf("yi");
            break;
        case '2':
            printf("er");
            break;
        case '3':
            printf("san");
            break;
        case '4':
            printf("si");
            break;
        case '5':
            printf("wu");
            break;
        case '6':
            printf("liu");
            break;
        case '7':
            printf("qi");
            break;
        case '8':
            printf("ba");
            break;
        case '9':
            printf("jiu");
            break;
        default:
            printf("erro!");
        }
}
int main()
{
    int i;
    char a[10];
    gets(a);
    //printf("%s\n",a);
    for(i=0;a[i]!='\0';i++)
    {
        char b=a[i];
        Dushuzi(b);
        if(a[i+1]!='\0')
            printf(" ");
    }
    return 0;
}
