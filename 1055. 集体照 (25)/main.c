/*


拍集体照时队形很重要，这里对给定的N个人K排的队形设计排队规则如下：

    每排人数为N/K（向下取整），多出来的人全部站在最后一排；
    后排所有人的个子都不比前排任何人矮；
    每排中最高者站中间（中间位置为m/2+1，其中m为该排人数，除法向下取整）；
    每排其他人以中间人为轴，按身高非增序，先右后左交替入队站在中间人的两侧（例如5人身高为190、188、186、175、170，则队形为175、188、190、186、170。这里假设你面对拍照者，所以你的左边是中间人的右边）；
    若多人身高相同，则按名字的字典序升序排列。这里保证无重名。

现给定一组拍照人，请编写程序输出他们的队形。

输入格式：

每个输入包含1个测试用例。每个测试用例第1行给出两个正整数N（<=10000，总人数）和K（<=10，总排数）。随后N行，每行给出一个人的名字（不包含空格、长度不超过8个英文字母）和身高（[30, 300]区间内的整数）。

输出格式：

输出拍照的队形。即K排人名，其间以空格分隔，行末不得有多余空格。注意：假设你面对拍照者，后排的人输出在上方，前排输出在下方。
输入样例：

10 3
Tom 188
Mike 170
Eva 168
Tim 160
Joe 190
Ann 168
Bob 175
Nick 186
Amy 160
John 159

输出样例：

Bob Tom Joe Nick
Ann Mike Eva
Tim Amy John

*/
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct person
{
    char name[9];   //名字长度不小于八个  但存储八个长度的名字要九个长度 最后一个存\n  坑！
    int high;
}p[10000],*aa,*bb;

int cmp(const void *a,const void *b)
{
    aa=(struct person *)a;
    bb=(struct person *)b;
    if(aa->high==bb->high)
        return strcmp((aa->name),(bb->name));//int a1,a2;return a1>a2只会返回0，1，返回0时表示a1不大于a2,1表示a1大于a2,而strcmp(s1,s2)会返回-1，0，1
    return (((aa->high)<(bb->high))?1:-1);
}
void prin(int i,int j,int num)
{
    int k,middel=num/2,order[num];
    order[middel]=i;
    for(k=1;;k++)
    {
        if(i==j)
            break;
        order[middel-k]=++i;
        if(i==j)
            break;
        order[middel+k]=++i;
    }
    for(k=0;k<num-1;k++)
    {
        printf("%s ",p[order[k]].name);
    }
    printf("%s\n",p[order[num-1]].name);
}
int main()
{
    int i,n,k;
    scanf("%d%d",&n,&k);
    int row=n/k;
    for(i=0;i<n;i++)
    {
        scanf("%s%d",p[i].name,&p[i].high);
    }
    qsort(p,n,sizeof(p[0]),cmp);
    int row1=row+n%k;
    prin(0,row1-1,row1);
    if(n>=k)
    for(i=1;i<k;i++)
    {
        prin(row1+row*(i-1),row1+row*i-1,row);
    }
    /*for(i=0;i<n;i++)
         printf("%s %d\n",p[i].name,p[i].high);
    printf("Hello world!\n");*/
    return 0;
}
