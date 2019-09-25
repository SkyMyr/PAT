/*
专家通过多组情侣研究数据发现，最佳的情侣身高差遵循着一个公式：（女方的身高）×1.09=（男方的身高）。
如果符合，你俩的身高差不管是牵手、拥抱、接吻，都是最和谐的差度。

下面就请你写个程序，为任意一位用户计算他/她的情侣的最佳身高。

输入格式：

输入第一行给出正整数N（<=10），为前来查询的用户数。随后N行，每行按照“性别 身高”的格式给出前来查询的用户的性别和身高，
其中“性别”为“F”表示女性、“M”表示男性；“身高”为区间 [1.0, 3.0] 之间的实数。

输出格式：

对每一个查询，在一行中为该用户计算出其情侣的最佳身高，保留小数点后2位。
输入样例：

2
M 1.75
F 1.8

输出样例：

1.61
1.96


#include <stdio.h>
#include <stdlib.h>
struct person
{
    char sex;
    double high;
}p[10];
int main()
{
    int i,n;
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++)
    {
        scanf("%c",&p[i].sex);
        getchar();
        scanf("%lf",&p[i].high);
        getchar();//scanf不对回车进行处理，它是以空格作为字符输入的结束。 而getchar()会对空格进行处理，以回车作为输入结束。
    }
    for(i=0;i<n;i++)
    {
        if(p[i].sex =='F')
            printf("%.2lf\n",p[i].high*1.09);
        else
            printf("%.2lf\n",p[i].high/1.09);
    }
    return 0;
}*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    getchar();
      char a;
      double high;
      scanf("%c %lf",&a,&high);
      if(a=='M')
      {
        printf("%.2lf",(high/1.09));
      }
      else
        printf("%.2lf",(high*1.09));
    }
    return 0;
}

