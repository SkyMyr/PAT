#include <stdio.h>
#include <stdlib.h>

int main()
{
	 int a;
	scanf("%d",&a);
	 int i,k;
	if(a == 1)
    {
		printf("1=1");
	}
	else
    {
		printf("%d=",a);
		for(i=1; i<=a; ++i)
        {
			k = 0 ;
			if(a%i == 0 && i!=1)
            {					//过滤掉1
				do{
					a /= i ;								//找到素数约数，并找到其个数
					++k;
				}while(a%i == 0);

				if(k>1)
				{
					printf("%d^%d",i,k);
				}
				else
				{
					printf("%d",i);
				}
                if(a/i>0)
                {										//最后一位不再输出*
                    printf("*");
                }
            }
		}
	}
	return 0;
}
