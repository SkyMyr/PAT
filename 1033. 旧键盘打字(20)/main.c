#include<stdio.h>
#include<string.h>
#include<math.h>
long a[1010][1010];
int u[1010][1010]={0};
int main(){
    long n,m,h;
    int i,j,i1,j1,k = 0;
    int c1,c2,c3;
    scanf("%ld %ld %ld",&n,&m,&h);
    for( i=1;i<=m;i++){
        for( j=1;j<=n;j++){
            scanf("%ld",&a[i][j]);
        }
    }
    for( i=0;i<=n+1;i++){
        a[0][i] = -(pow(2,24)-1);
    }
    for( i=0;i<=n+1;i++){
        a[m+1][i] = -(pow(2,24)-1);
    }
    for( i=0;i<=m+1;i++){
        a[i][0] = -(pow(2,24)-1);
    }
    for( i=0;i<=m+1;i++){
        a[i][n+1] = -(pow(2,24)-1);
    }
/*    for(int i=0;i<=m+1;i++){
        for(int j=0;j<=n+1;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }*/
    for( i=1;i<=m;i++){
        for( j=1;j<=n;j++){
            if(!u[i][j]){
                for( i1=i;i1<=m;i1++){
                    for( j1=1;j1<=n;j1++){
                        if( a[i][j] == a[i1][j1]  &&  (i!=i1||j!=j1)){
                            u[i1][j1] = 1;
                            u[i][j] = 1;
                        }
                    }
                }
            }

        }
    }
    for( i=1;i<=m;i++){
        for( j=1;j<=n;j++){
            if(u[i][j])
                continue;
            int b1 = labs(a[i][j]-a[i][j-1]);
            int b2 = labs(a[i][j]-a[i][j+1]);
            int b3 = labs(a[i][j]-a[i+1][j-1]);
            int b4 = labs(a[i][j]-a[i+1][j]);
            int b5 = labs(a[i][j]-a[i+1][j+1]);
            int b6 = labs(a[i][j]-a[i-1][j]);
            int b7 = labs(a[i][j]-a[i-1][j-1]);
            int b8 = labs(a[i][j]-a[i-1][j+1]);
            if(b1>h&&b2>h&&b3>h&&b4>h&&b5>h&&b6>h&&b7>h&&b8>h){
                k++;
                if(k==1){
                    c1 = i;
                    c2 = j;
                    c3 = a[i][j];
                }
            }
        }
    }
    if(k==0){
        printf("Not Exist");
    }else if(k==1){
        printf("(%d, %d): %d",c2,c1,c3);
    }else{
        printf("Not Unique\n");
    }
}
/*
�ɼ����ϻ��˼���������������һ�����ֵ�ʱ�򣬶�Ӧ���ַ��Ͳ�����֡����ڸ���Ӧ�������һ�����֡��Լ���������Щ��������Ľ�����ֻ���������
�����ʽ��
������2���зֱ������������Щ�����Լ�Ӧ����������֡����ж�ӦӢ����ĸ�Ļ����Դ�д������ÿ�������ǲ�����105���ַ��Ĵ���
���õ��ַ�������ĸ[a-z, A-Z]������0-9���Լ��»��ߡ�_��������ո񣩡���,������.������-������+���������ϵ���������Ŀ��֤��2����������ִ��ǿա�
ע�⣺����ϵ��������ˣ���ô��д��Ӣ����ĸ�޷��������
�����ʽ��
��һ��������ܹ�������Ľ�����֡����û��һ���ַ��ܱ��������������С�
����������
7+IE.
7_This_is_a_test.
���������
_hs_s_a_tst
*/
//����һ��������ʽ
#include <stdio.h>
#include <ctype.h>

int main()
{
    int list[128] = {0}, bad_key = 0, input;

    while ((bad_key = getchar()) != '\n') {
        list[bad_key] = 1;
        list[tolower(bad_key)] = 1; // �����л�����ֵΪ1���������ĸ����Ӧ�Ĵ�Сд�ַ���Ҫ��ֵΪ1
    }
    if (list['+'] == 1) // ����ϵ���
        for (int i = 65; i < 91; i++)
            list[i] = 1;
    while ((input = getchar()) != '\n')
        if (list[input] == 0) // �����ַ������������
            printf("%c", input);

    return 0;
}*/
/*
tolower()

C ��׼�� - <ctype.h>

C �⺯�� int tolower(int c) �Ѹ�������ĸת��ΪСд��ĸ��
����

int tolower(int c);

����

    c -- ����Ҫ��ת��ΪСд����ĸ��

����ֵ

��� c �����Ӧ��Сд��ĸ����ú������� c ��Сд��ĸ������ c ���ֲ��䡣����ֵ��һ���ɱ���ʽת��Ϊ char ���͵� int ֵ��*/
//������������
/*#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    int i,j,count;
    char error[42],s[100001];
    gets(error);//gets scanf ���������
    gets(s);
    //s.find(error[0]);
    if(error==NULL)
        puts(s);
    else
    {
    for(i=0;i<strlen(error);i++)
    {
        if(error[i]=='+')
        {
            for(j=0;j<strlen(s);j++)
            {
                if(s[j]>='A'&&s[j]<='Z')
                    s[j]='#';
            }
        }

    }
    for(i=0;i<strlen(error);i++)
    {
        for(j=0;j<strlen(s);j++)
        {
             if(s[j]==error[i])
                s[j]='#';
             if(error[i]<='Z'&&error[i]>='A'&&s[j]==error[i]+32)
                s[j]='#';
        }
    }

    for(j=0;j<strlen(s);j++)
    {
        if(s[j]!='#')
        {
            printf("%c",s[j]);
            count=1;
        }
    }
    if(count==0)
        printf("\n");
    }
    return 0;
}*/
/*
scanf( )������gets( )�����������������ַ��������ڹ���������������Ӽ����������ַ���"hihello"����Ӧ��ʹ��__gets__������
gets���Խ��տո񣻶�scanf�����ո񡢻س���Tab��������Ϊ������������������ܽ��տո�
char string[15]; gets(string); //�����س���Ϊ�������
scanf("%s",string); //�����ո���Ϊ�������
������������ַ����а����ո�ʱ��Ӧ��ʹ��gets���롣
scanf��gets��ȡ�ַ���ʱ������
��C�����У��ܹ���ȡ�ַ����ĺ���������������
1.scanf()
����ͷ�ļ���stdio.h
�﷨��scanf("��ʽ�����ַ���",������ַ�б�);
�����ַ���ʱ��scanf("%s",�ַ���������ָ��);
2.gets()
����ͷ�ļ���stdio.h
�﷨��gets(�ַ���������ָ��);
�����ڽ����ַ���ʱ��
1.��ͬ�㣺
scanf���ܽ��ܿո��Ʊ��Tab���س��ȣ�
��gets�ܹ����ܿո��Ʊ��Tab�ͻس��ȣ�
2.��ͬ�㣺
�ַ������ܽ������Զ���'\0'��
��1��
#include <stdio.h>
main()
{
char ch1[10],ch2[10];
scanf("%s",ch1);
gets(ch2);
}
���μ���asd�ո�fg�س���asd�ո�fg�س�����ch1="asd\0"��ch2="asd fg\0"��
��2��
#include <stdio.h>
main()
{
char ch1[10],ch2[10],c1,c2;
scanf("%s",ch1);
c1=getchar();
gets(ch2);
c2=getchar();
}
���μ���asdfg�س���asdfg�س�����ch1="asdfg\0"��c1='\n'��ch2="asdfg\0"��c2�����롣
scanf ���������س����ո��tab�����Զ����ַ����������'\0'�����ǻس����ո��tab���Ի���������Ļ������С�
gets���ɽ��ܻس���֮ǰ����������ַ�������'\n'��� '\0'.�س��������������뻺������
gets()�õ���ȡ�ַ������ûس���������
scanf()���Զ�ȡ�������͵ı���
��ת���ԣ�http://leoenglish.blog.163.com/blog/static/1750319852011296336486/��
*/
