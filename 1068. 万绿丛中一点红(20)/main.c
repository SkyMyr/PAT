/*
对于计算机而言，颜色不过是像素点对应的一个24位的数值。现给定一幅分辨率为MxN的画，要求你找出万绿丛中的一点红，
即有独一无二颜色的那个像素点，并且该点的颜色与其周围8个相邻像素的颜色差充分大。

输入格式：

输入第一行给出三个正整数，分别是M和N（<= 1000），即图像的分辨率；以及TOL，是所求像素点与相邻点的颜色差阈值，色差超过TOL的点才被考虑。
随后N行，每行给出M个像素的颜色值，范围在[0, 224)内。所有同行数字间用空格或TAB分开。

输出格式：

在一行中按照“(x, y): color”的格式输出所求像素点的位置以及颜色值，其中位置x和y分别是该像素在图像矩阵中的列、行编号（从1开始编号）。
如果这样的点不唯一，则输出“Not Unique”；如果这样的点不存在，则输出“Not Exist”。
输入样例1：

8 6 200
0 	 0 	  0 	   0	    0 	     0 	      0        0
65280 	 65280    65280    16711479 65280    65280    65280    65280
16711479 65280    65280    65280    16711680 65280    65280    65280
65280 	 65280    65280    65280    65280    65280    165280   165280
65280 	 65280 	  16777015 65280    65280    165280   65480    165280
16777215 16777215 16777215 16777215 16777215 16777215 16777215 16777215

输出样例1：

(5, 3): 16711680

输入样例2：

4 5 2
0 0 0 0
0 0 3 0
0 0 0 0
0 5 0 0
0 0 0 0

输出样例2：

Not Unique

输入样例3：

3 3 5
1 2 3
3 4 5
5 6 7

输出样例3：

Not Exist

*/
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int m,n,tol,p[1000][1000];
int pc[1000][1000]={{0}};
int judge(int x,int y)
{
    //int a1=-tol-1,a2=-tol-1,a3=-tol-1,a4=-tol-1,a5=-tol-1,a6=-tol-1,a7=-tol-1,a8=-tol-1;
    int a1=tol+1,a2=tol+1,a3=tol+1,a4=tol+1,a5=tol+1,a6=tol+1,a7=tol+1,a8=tol+1;
    if(x>=1&&y>=1)
    a1=p[x][y]-p[x-1][y-1];
    if(x>=1)
    a2=p[x][y]-p[x-1][y];
    if(x>=1&&y<m-1)
    a3=p[x][y]-p[x-1][y+1];
    if(y>=1)
    a4=p[x][y]-p[x][y-1];
    if(y<m-1)
    a5=p[x][y]-p[x][y+1];
    if(x<n-1&&y>=1)
    a6=p[x][y]-p[x+1][y-1];
    if(x<n-1)
    a7=p[x][y]-p[x+1][y];
    if(x<n-1&&y<m-1)
    a8=p[x][y]-p[x+1][y+1];
    if(tol<abs(a1)&&tol<abs(a2)&&tol<abs(a3)&&tol<abs(a4)&&tol<abs(a5)&&tol<abs(a6)&&tol<abs(a7)&&tol<abs(a8))
    {
        //printf("%d %d %d %d %d %d %d %d\n",a1,a2,a3,a4,a5,a6,a7,a8);
        return 1;
    }
    return 0;
}
int main()
{
    int i,j,i1,j1;
    int count = 0;
    scanf("%d %d %d",&m,&n,&tol);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&p[i][j]);
        }
    }
    for( i=0;i<n;i++)
    {
        for( j=0;j<m;j++)
        {
            if(pc[i][j]==0)
            {
                for( i1=i;i1<n;i1++)
                {
                    for( j1=0;j1<m;j1++)
                    {
                        if( p[i][j] == p[i1][j1]  &&  (i!=i1||j!=j1))
                        {
                            pc[i1][j1] = 1;
                            pc[i][j] = 1;
                        }
                    }
                }
            }

        }
    }
    int o,q;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(pc[i][j]==0&&judge(i,j)==1)
            {
                if(count==0)
                    o=i;q=j;
                count++;
            }
        }
    }
    if(count==1)
        printf("(%d, %d): %d",q+1,o+1,p[o][q]);
    else if(count==0)
        printf("Not Exist");
    else
        printf("Not Unique");
/*
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%d  ",pc[i][j]);
        }
        printf("\n");
    }
    printf("Hello world!\n");*/
    return 0;
}
