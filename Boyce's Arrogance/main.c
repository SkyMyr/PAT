#include <stdio.h>
#include <stdlib.h>
typedef struct p{
	int LL,LR,RL,RR;
	int count;
}node;
int main()
{
	int n;
	char ch[300100];
	int nodes[300100];
	node fir;
	char t;
	int i,j,k;
	int min=300000;
	int lcount=0,rcount=0;
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++)
	{
		scanf("%c",&ch[i]);
		if(ch[i]=='L')
		{
			lcount++;
		}
		else
		{
			rcount++;
		}
	}
	if(ch[0]=='L')
	{
		fir.LL=0;fir.LR=0;fir.RR=rcount;fir.RL=lcount-1;
	}
	else
	{
		fir.LL=0;fir.LR=0;fir.RR=rcount-1;fir.RL=lcount;
	}
	nodes[0]=fir.LL+fir.RR;
	for(i=1;i<n;i++)
	{
		if(ch[i]=='L')
		{
			if(ch[i-1]=='L')
			{
				nodes[i]=nodes[i-1]+1;
			}else
			{
				nodes[i]=nodes[i-1];
			}
		}
		else
		{
			if(ch[i-1]=='L')
			{
				nodes[i]=nodes[i-1];
			}else
			{
				nodes[i]=nodes[i-1]-1;
			}
		}
		if(nodes[i]<=min)
		{
			min=nodes[i];
		}
	}
	printf("%d",min<nodes[0]?min:nodes[0]);
}
