#include <stdio.h>
#include <stdlib.h>
int judge(char a,char b)
{
    if(a==b)
        return 3;
    else if((a=='C'&&b=='J')||(a=='J'&&b=='B')||(a=='B'&&b=='C'))
        return 1;
    else
        return 2;
}
struct person
{
    int win,fail,draw,C,J,B;
}p1,p2;
int main()
{
    int i,n;
    char m1,m2;
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++)
    {
        char a[4];
        gets(a);
        if(judge(a[0],a[2])==1)
        {
            p1.win++;
            if(a[0]=='C')
                p1.C++;
            else if(a[0]=='B')
                p1.B++;
            else
                p1.J++;
            p2.fail++;
        }
        else if(judge(a[0],a[2])==2)
        {
            p2.win++;
            if(a[2]=='C')
                p2.C++;
            else if(a[2]=='B')
                p2.B++;
            else
                p2.J++;
            p1.fail++;
        }
        else
        {
            p1.draw++;
            p2.draw++;
        }
    }
    printf("%d %d %d\n",p1.win,p1.draw,p1.fail);
    printf("%d %d %d\n",p2.win,p2.draw,p2.fail);
    if(p1.C>=p1.J&&p1.C>p1.B)
        m1='C';
    else if(p1.J>p1.C&&p1.J>p1.B)
        m1='J';
    else
        m1='B';
    if(p2.C>=p2.J&&p2.C>p2.B)
        m2='C';
    else if(p2.J>p2.C&&p2.J>p2.B)
        m2='J';
    else
        m2='B';
    printf("%c %c",m1,m2);
    return 0;
}
/*
���Ӧ�ö����桰���Ӽ�����������Ϸ������ͬʱ�������ƣ�ʤ��������ͼ��ʾ��

�ָ������˵Ľ����¼����ͳ��˫����ʤ��ƽ�������������Ҹ���˫���ֱ��ʲô���Ƶ�ʤ�����

�����ʽ��

�����1�и���������N��<=105������˫������Ĵ��������N�У�ÿ�и���һ�ν������Ϣ�����ס���˫��ͬʱ�����ĵ����ơ�
C�������ӡ���J������������B������������1����ĸ����׷�����2�������ҷ����м���1���ո�

�����ʽ��

�����1��2�зֱ�����ס��ҵ�ʤ��ƽ�������������ּ���1���ո�ָ���
��3�и���������ĸ���ֱ����ס��һ�ʤ�����������ƣ��м���1���ո�����ⲻΨһ�����������ĸ����С�Ľ⡣
����������

10
C J
J B
C B
B B
B C
C C
C B
J B
B C
J J

���������

5 3 2
2 3 5
B B

*/
