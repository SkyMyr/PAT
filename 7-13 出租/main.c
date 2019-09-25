#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int GetIndex(int arr[11],int n,int x)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(arr[i]==x)
		{
			return i;
		}
	}
	return -1;
}
int cmp(const void * a, const void * b)
{
   return *(int*)b - *(int*)a;
}
int main()
{
	char ch[12];
	int arr[11];
	int i,l=0;
	gets(ch);
	for(i=0;i<11;i++)
	{
		if(GetIndex(arr,l,ch[i]-48)==-1)
		{
			arr[l++]=ch[i]-48;
			//printf("%d",arr[l-1]);
		}
	}
	qsort(arr,l,sizeof(arr[0]),cmp);
	printf("int[] arr = new int[]{");
	for(i=0;i<l-1;i++)
	{
		printf("%d,",arr[i]);
	}
	printf("%d};\n",arr[i]);
	printf("int[] index = new int[]{");
	for(i=0;i<10;i++)
	{
		printf("%d,",GetIndex(arr,l,ch[i]-48));
	}
	printf("%d};\n",GetIndex(arr,l,ch[i]-48));
	return 0;
}
