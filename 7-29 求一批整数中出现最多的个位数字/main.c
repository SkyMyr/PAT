/*#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,a;
    scanf("%d",&n);
    int b[10]={0};
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        while (a != 0)
		{
			b[a%10]++;
			a = a/10;
		}
    }
    int max=b[0];
    for(i=1;i<10;i++)
    {
        if(b[i]>max)
            max=b[i];
    }
    printf("%d:",max);
    for(i=0;i<10;i++)
    {
        if(b[i]==max)
            printf(" %d",i);
    }
    return 0;
}*/
#include<stdio.h>
#include<string.h>
int main()
{
	int n;
	char ch[10000];
	int arr[10]={0};
	int i,j,k=0;
	scanf("%d",&n);
	getchar();
	gets(ch);
	int l=strlen(ch);
	for(i=0;i<l;i++)
	{
		if(ch[i]>='0'&&ch[i]<='9')
		{
			arr[ch[i]-48]++;
		}
	}
	for(i=0;i<10;i++)
	{
		if(k<arr[i])
		{
			k=arr[i];
		}
	}
	printf("%d:",k);
	for(i=0;i<10;i++)
	{
		if(arr[i]==k)
		{
			printf(" %d",i);
		}
	}
}
