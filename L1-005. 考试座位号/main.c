/*


ÿ��PAT�����ڲμӿ���ʱ���ᱻ����������λ�ţ�һ�����Ի���λ��һ���ǿ�����λ����������£��������볡ʱ�ȵõ��Ի���λ���룬���������Ի�״̬��ϵͳ����ʾ�ÿ����Ŀ�����λ���룬����ʱ������Ҫ����������λ����������Щ�����ٵ��ˣ��Ի��Ѿ�����������ֻ�������쵽���Ի���λ�����������㣬�Ӻ�̨������ǵĿ�����λ���롣

�����ʽ��

�����һ�и���һ��������N��<=1000�������N�У�ÿ�и���һ����������Ϣ����׼��֤�� �Ի���λ�� ������λ�š�������׼��֤����14λ������ɣ���λ��1��N��š����뱣֤ÿ���˵�׼��֤�Ŷ���ͬ�������κ�ʱ�򶼲���������˷��䵽ͬһ����λ�ϡ�

������Ϣ֮�󣬸���һ��������M��<=N�������һ���и���M������ѯ���Ի���λ���룬�Կո�ָ���

�����ʽ��

��Ӧÿ����Ҫ��ѯ���Ի���λ���룬��һ���������Ӧ������׼��֤�źͿ�����λ���룬�м���1���ո�ָ���
����������

4
10120150912233 2 4
10120150912119 4 1
10120150912126 1 3
10120150912002 3 2
2
3 4

���������

10120150912002 2
10120150912119 1


*/
//��ȱ��
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int N,M;
int main()
{
    scanf("%d",&N);
    int i,k,j,ask[N],ans[N];
    char s[N][14];
    for(i=0;i<N;i++)
    {
        scanf("%s%d%d", s[i],&ask[i],&ans[i]);
        for(j=0;j<i;j++)
        {
            char a[14];
            for(k=0;k<14;k++)
            {
                a[k]=s[j][k];
            }
            if(strcmp(s[i],a)==0)
                printf("Error!");
        }
        //printf("%s\n",s[i]);
    }
    /*for(i=0;i<N;i++)
        printf("%s\n",s[i]);*/

    scanf("%d",&M);
    int enquire[M];
    for(i=0;i<M;i++)
    {
        scanf("%d",&enquire[i]);
    }
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            if(enquire[i]==ask[j])
            {
                for(k=0;k<14;k++)
                    printf("%c",s[j][k]);
                printf(" %d\n",ans[j]);
                //printf("%s %d\n", s[j],ans[j]);
            }
        }
    }
    return 0;
}
//������
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stu
{
    char num[14];
    int ask,ans;
}student[1000];
int N,M;
int main()
{
    scanf("%d",&N);
    int i,k,j;//,ask[N],ans[N];
    //char s[N][14];
    for(i=0;i<N;i++)
    {
        scanf("%s%d%d", student[i].num,&student[i].ask,&student[i].ans);
        /*for(j=0;j<i;j++)
        {
            char a[14];
            for(k=0;k<14;k++)
            {
                a[k]=s[j][k];
            }
            if(strcmp(s[i],a)==0)
                printf("Error!");
        }*/
        //printf("%s\n",s[i]);
    }
    /*for(i=0;i<N;i++)
        printf("%s\n",s[i]);*/

    scanf("%d",&M);
    int enquire[M];
    for(i=0;i<M;i++)
    {
        scanf("%d",&enquire[i]);
    }
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            if(enquire[i]==student[j].ask)
            {
                /*for(k=0;k<14;k++)
                    printf("%c",s[j][k]);*/
                printf("%s",student[j].num);
                printf(" %d\n",student[j].ans);
                //printf("%s %d\n", s[j],ans[j]);
            }
        }
    }
    return 0;
}

