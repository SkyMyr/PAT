#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int i,j,k=0,count=0,max=0;
    double p[1000],q[1000];
    char a[1000],b[1000];
    gets(a);
    gets(b);
    for(i=0;i<=strlen(a);i++)
    {
        if(a[i]==' ' || a[i]=='\0')
        {
            char tp[8];
            strncpy(tp,a+k,i-k);
            p[count]=atof(tp);
            //printf("%d %f\n",i,p[count]);
            count++;
            k=i+1;
        }
    }
    int length_p=count;
    k=0;count=0;
    for(i=0;i<=strlen(b);i++)
    {
        if(b[i]==' ' || b[i]=='\0')
        {
            char tmp[8];
            strncpy(tmp,b+k,i-k);
            q[count]=atof(tmp);
            //printf("%d %f\n",i,q[count]);
            count++;
            k=i+1;
        }
    }
    int length_q=count;
    //printf("%d %d\n",length_p,length_q);
    for(i=0;i<length_q;i+=4)
    {
        count=0;
        for(j=0;j<length_p;j+=2)
        {
            if(p[j]>=q[i]&&p[j]<=q[i+2]&&p[j+1]>=q[i+1]&&p[j+1]<=q[i+3])
            {
                count++;
            }
        }
        max=(max>=count)?max:count;
    }
    printf("%d",max);
    return 0;
}
/*
给你若干个点的坐标和若干个矩形区域，存在一个包括的点的数量最大的矩形区域，请输出该数量。
输入

第一行输入若干个点的坐标，x
和 y 成对出现。 第二行输入若干个矩形区域，x1,y1,x2,y2

成组出现。
输出

输出一行，包含题目所要求的答案
输入样例
Copy

1 1 2 2 3 3 4 4
0 0 5 5

输出样例
Copy

4

提示

坐标点为实数，请将坐标点进行离散化处理*/
