#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char a[50];
	char b[50];
	int i,sum1=0,sum2=0,flag1=1,flag2=1;
	scanf("%s",a);
	getchar();
	gets(b);
	int l1,l2;
	l1=strlen(a);
	l2=strlen(b);
	if(l1<1||l1>4)
	{
		flag1=0;
	}
	else
	{
	for(i=0;i<l1;i++)
	{
		if(a[i]<'0'||a[i]>'9')
		{
			flag1=0;
			break;
		}

	}
	}
	if(l2<1||l2>4)
	{
		flag2=0;
	}
	else{
	for(i=0;i<l2;i++)
	{
		if(b[i]<'0'||b[i]>'9')
		{
			flag2=0;
			break;
		}

	}
	}
	if(flag1==1)
	{
		for(i=0;i<l1;i++)
		{
			sum1=sum1*10+(a[i]-'0');
		}
	}
	if(sum1<1||sum1>1000)
	{
		flag1=0;
	}
	if(flag2==1)
	{
		for(i=0;i<l2;i++)
		{
			sum2=sum2*10+(b[i]-'0');
		}
	}
	if(sum2<1||sum2>1000)
	{
		flag2=0;
	}
	if(flag1==1 &&flag2==1)
	{
		printf("%d + %d = %d",sum1,sum2,sum1+sum2);
	}
	if(flag1==0 &&flag2==1 )
	{
		printf("? + %d = ?",sum2);
	}
	if(flag1==1 &&flag2==0 )
	{
		printf("%d + ? = ?",sum1);
	}
	if(flag1==0 &&flag2==0 )
	{
		printf("? + ? = ?");
	}
	return 0;
}
