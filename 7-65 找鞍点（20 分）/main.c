#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i,j,n,a[6][6],b[6],c[6];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		int max=0;
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j]>max)
			{
				max=a[i][j];
				b[i]=max;
			}
		}
	}
	for(j=0;j<n;j++)
	{
		int min=9999;
		for(i=0;i<n;i++)
		{
			if(a[i][j]<min)
			{
				min=a[i][j];
				c[j]=min;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(b[i]==c[j])
			{
				printf("%d %d\n",i,j);
				return 0;
			}
		}
	}
	puts("NONE");
	return 0;
}
