#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,i,count=0,flag=0;
    scanf("%d %d",&n,&m);
    getchar();
    for(i=0;i<n;i++)
    {
        char a;
        while((a=getchar())!='\n')
        {
            if(a=='S')
            {
                count++;
                if(count>m)
                    flag=1;
            }
            if(a=='X')
            {
                count--;
                if(count<0)
                    flag=1;
            }
        }
        if(count == 0 && flag == 0)
            printf("YES\n");
        else
            printf("NO\n");
        count = 0;
        flag = 0;
    }
   // printf("Hello world!\n");
    return 0;
}
