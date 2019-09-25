#include <stdio.h>
#include <stdlib.h>

int main()
{
    double x,y;
    int result;
    scanf("%lf",&x);
    if(x<=5)
    {
        y=x*x+3*x-4;
    }
    else
    {
        y=x*x-5*x+7;
    }
    result=y*1000;
    if(result%10>=5)
    {
        printf("%.2lf",y+0.01);
    }
    else
        printf("%.2lf",y);
    return 0;
}
