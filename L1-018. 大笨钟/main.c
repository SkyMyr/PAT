
/*
΢�����и��Գơ�����V���ļһÿ�����Ӵߴ���ũ�ǰ�ϧ�������˯�����������ڱ����Լ���ϢҲ���Ǻܹ��ɣ��������Ӳ�����ʱ��һ�����ӵĵ����Ǹ�������ʱ������ģ����������ĳ�������ã���ô���������͵����Ǹ�������������������㣬������һ�������������⣬��Ȼһ����24Сʱ����ȴ��ֻ�ں������1~12�¡�������23:00���ӣ����ǡ���������������������������������23:01�ͻ��ǡ���������������������������������ҹ00:00������12:00�ڼ䣨�˵�ʱ��������ڣ��������ǲ��õġ�

���������д�����򣬸��ݵ�ǰʱ����������ӡ�

�����ʽ��

�����һ�а��ա�hh:mm���ĸ�ʽ������ǰʱ�䡣����hh��Сʱ����00��23֮�䣻mm�Ƿ��ӣ���00��59֮�䡣

�����ʽ��

���ݵ�ǰʱ����������ӣ�����һ���������Ӧ��������Dang����������������ڣ��������

Only hh:mm.  Too early to Dang.

���С�hh:mm���������ʱ�䡣
��������1��

19:05

�������1��

DangDangDangDangDangDangDangDang

��������2��

07:05

�������2��

Only 07:05.  Too early to Dang.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int hh,minus;
    char s2[2],s1[2],time[5];
    scanf("%s",time);
    strncpy(s1,time,2);
    hh=atoi(s1);
    strncpy(s2,time+3,2);
    minus=atoi(s2);
    /*
    s1[0]=time[0];
    s1[1]=time[1];

    s2[0]=time[3];
    s2[1]=time[4];*/
    if( 0<=hh&&hh<24 && 0<=minus&&minus<60 )
    {
        if(0<=hh&&hh<12)
            printf("Only %02d:%02d.  Too early to Dang.",hh,minus);
        else if(hh==12&&minus==0)
            printf("Only %02d:%02d.  Too early to Dang.",hh,minus);
        else if(minus==0)
        {
            int i;
            for(i=0;i<hh-12;i++)
            {
                printf("Dang");
            }
        }
        else
        {
            int i;
            for(i=0;i<=hh-12;i++)
                printf("Dang");
        }
    }
    else
        printf("Error!");
    //printf("h=%02d,minus=%02d\n",h,minus);
    return 0;
}
