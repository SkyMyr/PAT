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
            {					//���˵�1
				do{
					a /= i ;								//�ҵ�����Լ�������ҵ������
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
                {										//���һλ�������*
                    printf("*");
                }
            }
		}
	}
	return 0;
}
