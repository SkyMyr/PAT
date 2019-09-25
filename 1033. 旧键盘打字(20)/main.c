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
旧键盘上坏了几个键，于是在敲一段文字的时候，对应的字符就不会出现。现在给出应该输入的一段文字、以及坏掉的那些键，打出的结果文字会是怎样？
输入格式：
输入在2行中分别给出坏掉的那些键、以及应该输入的文字。其中对应英文字母的坏键以大写给出；每段文字是不超过105个字符的串。
可用的字符包括字母[a-z, A-Z]、数字0-9、以及下划线“_”（代表空格）、“,”、“.”、“-”、“+”（代表上档键）。题目保证第2行输入的文字串非空。
注意：如果上档键坏掉了，那么大写的英文字母无法被打出。
输出格式：
在一行中输出能够被打出的结果文字。如果没有一个字符能被打出，则输出空行。
输入样例：
7+IE.
7_This_is_a_test.
输出样例：
_hs_s_a_tst
*/
//方法一：正则表达式
#include <stdio.h>
#include <ctype.h>

int main()
{
    int list[128] = {0}, bad_key = 0, input;

    while ((bad_key = getchar()) != '\n') {
        list[bad_key] = 1;
        list[tolower(bad_key)] = 1; // 将所有坏键赋值为1，如果是字母，相应的大小写字符都要赋值为1
    }
    if (list['+'] == 1) // 检查上档键
        for (int i = 65; i < 91; i++)
            list[i] = 1;
    while ((input = getchar()) != '\n')
        if (list[input] == 0) // 查验字符表，并进行输出
            printf("%c", input);

    return 0;
}*/
/*
tolower()

C 标准库 - <ctype.h>

C 库函数 int tolower(int c) 把给定的字母转换为小写字母。
声明

int tolower(int c);

参数

    c -- 这是要被转换为小写的字母。

返回值

如果 c 有相对应的小写字母，则该函数返回 c 的小写字母，否则 c 保持不变。返回值是一个可被隐式转换为 char 类型的 int 值。*/
//方法二：数组
/*#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    int i,j,count;
    char error[42],s[100001];
    gets(error);//gets scanf 的区别见下
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
scanf( )函数和gets( )函数都可用于输入字符串，但在功能上有区别。若想从键盘上输入字符串"hihello"，则应该使用__gets__函数。
gets可以接收空格；而scanf遇到空格、回车和Tab键都会认为输入结束，所有它不能接收空格。
char string[15]; gets(string); //遇到回车认为输入结束
scanf("%s",string); //遇到空格认为输入结束
所以在输入的字符串中包含空格时，应该使用gets输入。
scanf和gets获取字符串时的区别
在C语言中，能构获取字符串的函数至少有两个：
1.scanf()
所在头文件：stdio.h
语法：scanf("格式控制字符串",变量地址列表);
接受字符串时：scanf("%s",字符数组名或指针);
2.gets()
所在头文件：stdio.h
语法：gets(字符数组名或指针);
两者在接受字符串时：
1.不同点：
scanf不能接受空格、制表符Tab、回车等；
而gets能够接受空格、制表符Tab和回车等；
2.相同点：
字符串接受结束后自动加'\0'。
例1：
#include <stdio.h>
main()
{
char ch1[10],ch2[10];
scanf("%s",ch1);
gets(ch2);
}
依次键入asd空格fg回车，asd空格fg回车，则ch1="asd\0"，ch2="asd fg\0"。
例2：
#include <stdio.h>
main()
{
char ch1[10],ch2[10],c1,c2;
scanf("%s",ch1);
c1=getchar();
gets(ch2);
c2=getchar();
}
依次键入asdfg回车，asdfg回车，则ch1="asdfg\0"，c1='\n'，ch2="asdfg\0"，c2需输入。
scanf ：当遇到回车，空格和tab键会自动在字符串后面添加'\0'，但是回车，空格和tab键仍会留在输入的缓冲区中。
gets：可接受回车键之前输入的所有字符，并用'\n'替代 '\0'.回车键不会留在输入缓冲区中
gets()用到读取字符串，用回车结束输入
scanf()可以读取所有类型的变量
（转载自：http://leoenglish.blog.163.com/blog/static/1750319852011296336486/）
*/
