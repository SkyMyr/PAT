/*#include<stdio.h>
#include<string.h>
#define M 1000000
typedef struct{
	char name[16];
	int height;
	int weight;
}Student;
typedef struct{
	Student stu[4];
	int num;
	int max;
}Dormitory;
int main()
{
	int n;
	Dormitory dor[M];
	int arr[M];
	int i,j,k,l,max=0;
	scanf("%d",&n);
	for(i=0;i<M;i++)
	{
		dor[i].num=0;
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&j);
		arr[i]=j;
		getwchar();
		scanf("%s",dor[j].stu[dor[j].num].name);
		getchar();
		scanf("%d %d",&dor[j].stu[dor[j].num].height,&dor[j].stu[dor[j].num].weight);
		dor[j].num++;
	}
	for(i=0;i<n;i++)
	{
		max=0;
		for(j=0;j<dor[arr[i]].num;j++)
		{
			if(dor[arr[i]].stu[i].height>max)
			{
				dor[arr[i]].max=j;
				max=dor[arr[i]].stu[j].height;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%06d %s %d %d\n",arr[i],dor[arr[i]].stu[dor[arr[i]].max].name,dor[arr[i]].stu[dor[arr[i]].max].height,dor[arr[i]].stu[dor[arr[i]].max].weight);
	}
}
*/

#include<stdio.h>
int main()
{
    char a[4][30],b[9];
    int i,j=0;
    for(i=0;i<4;i++)
    {
      scanf("%s",a[i]);
    }
    for(i=0;i<4;i++)
    {
      b[j++]=a[i][0];
      b[j++]=a[i][1];
    }
    printf("%s",b);
    return 0;
}
