#include <stdio.h>
#include <stdlib.h>
int arr[1000010];
int main()
{
	int n;
	int j=0;
	scanf("%d",&n);
	scanf("%d",&arr[j]);
	while(1)
	{
		scanf("%d",&arr[++j]);
		if(arr[j]<0)
		{
			break;
		}
	}
	if(n>j)
	{
		printf("NULL");
	}
	else
		printf("%d",arr[j-n]);
    return 0;
}
