/*
 ����������Ȧ��һ����������2��14���˽��ˣ��Ҿ����츣��ҡ���2���޺͵�14���޵ģ��ҽ���������ʶ�������������Է��������롭����
 �ָ��������µ��޵����������������ҳ�����λҪ��͵ĵ�ù����

�����ʽ��

���밴�յ��޵��Ⱥ�˳�������֪�����ٸ����޵�������ÿ������ռһ�У�Ϊ������10��Ӣ����ĸ�ķǿյ��ʣ��Իس�������
һ��Ӣ�ľ�㡰.����־����Ľ�����������Ų����ڵ��������

�����ʽ��

���ݵ��������һ����������ۣ������ڵ�2����A�͵�14����B���������A and B are inviting you to dinner...����
��ֻ��Aû��B���������A is the only one for you...��������A��û�У��������Momo... No one is for you ...����
��������1��

GaoXZh
Magi
Einst
Quark
LaoLao
FatMouse
ZhaShen
fantacy
latesum
SenSen
QuanQuan
whatever
whenever
Potaty
hahaha
.

�������1��

Magi and Potaty are inviting you to dinner...

��������2��

LaoLao
FatMouse
whoever
.

�������2��

FatMouse is the only one for you...

��������3��

LaoLao
.

�������3��

Momo... No one is for you ...
*/
#include <stdio.h>
#include <stdlib.h>
struct zan
{
    char name[12];
}a[10000];
int main()
{
    int i;
    scanf("%s",a[0].name);
    for(i=0;a[i].name[0]!='.';i++)
    {
        scanf("%s",a[i+1].name);
    }
    if(i>=14)
        printf("%s and %s are inviting you to dinner...",a[1].name,a[13].name);
    else if(i>=2&&i<14)
        printf("%s is the only one for you...",a[1].name);
    else
        printf("Momo... No one is for you ...");
    return 0;
}
