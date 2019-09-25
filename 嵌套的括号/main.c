#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char a[1010];
struct Node
{
    int value,times;
}p[1000],*aa,*bb;
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
int main()
{
    gets(a);
    int i,j=0,k;
    for(i=0;i<strlen(a);i++)
    {
        if(a[i]<'9'&&a[i]>='0')
        {
            int left=0,right=0;
            p[j].value=a[i]-'0';
            for(k=0;k<i;k++)
            {
                if(a[k]=='(')
                    left++;
                else if(a[k]==')'&&left>0)
                    left--;
            }
            for(k=i+1;k<strlen(a);k++)
            {
                if(a[k]==')')
                    right++;
                else if(a[k]=='(')
                    right--;
            }
            if(left>=right)
                p[j].times=right;
            else
                p[j].times=left;
            j++;
        }
    }
    qsort(p,j,sizeof(p[0]),cmp);
    for(i=0;i<j;i++)
        printf("%d %d\n",p[i].value,p[i].times);
    return 0;
}
