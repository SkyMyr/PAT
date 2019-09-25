#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int i;
    double n,a[10000],sum=0;
    scanf("%lf",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lf",&a[i]);
        sum+=a[i];
    }
    double s,avg=sum/n;
    for(i=0;i<n;i++)
    {
        s+=(a[i]-avg)*(a[i]-avg);
    }
    printf("%.5lf",sqrt(s/n));
    return 0;
}
