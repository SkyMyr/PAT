#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
	int arr[10];
	int nums[55];
	int i,j,k=0;
	for(i=0;i<10;i++)
	{
		scanf("%d",&arr[i]);
		if(arr[i]>0)
		{
			for(j=0;j<arr[i];j++)
			{
				nums[k++]=i;
			}

		}
	}
	for(i=0;i<k;i++)
	{
		if(nums[i]>0)
		{
			printf("%d",nums[i]);
			nums[i]=-1;
			break;
		}
	}
	for(i=0;i<k;i++)
	{
		if(nums[i]!=-1)
		{
			printf("%d",nums[i]);
		}
	}
	return 0;
}
