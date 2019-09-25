/*
复数可以写成(A + Bi)的常规形式，其中A是实部，B是虚部，i是虚数单位，满足i2 = -1；也可以写成极坐标下的指数形式(R*e(Pi))，
其中R是复数模，P是辐角，i是虚数单位，其等价于三角形式 R(cos(P) + isin(P))。

现给定两个复数的R和P，要求输出两数乘积的常规形式。

输入格式：

输入在一行中依次给出两个复数的R1, P1, R2, P2，数字间以空格分隔。

输出格式：

在一行中按照“A+Bi”的格式输出两数乘积的常规形式，实部和虚部均保留2位小数。注意：如果B是负数，则应该写成“A-|B|i”的形式。
输入样例：

2.3 3.5 5.2 0.4

输出样例：

-8.68-8.23i


*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double a,b;
void exchange(double r,double p)
{
    //R(cos(P) + isin(P))
    b=sin(p)*r;
    a=r*cos(p);
}
int main()
{
    double r,p,r1,p1,r2,p2;
    scanf("%lf%lf%lf%lf",&r1,&p1,&r2,&p2);
    r=r1*r2;
    p=(p1+p2);
    exchange(r,p);

    //注意：由于实部、虚部都保留两位小数，所以当A、B的值介于0与-0.01之间时就必须要把它们设置为零，否则会有用例无法通过。
    if(fabs(a)<0.01)
        a=0;
    if(fabs(b)<0.01)
        b=0;
    if(b<0)
        printf("%.2lf%.2lfi\n",a,b);
    else
        printf("%.2lf+%.2lfi\n",a,b);
    return 0;
}
