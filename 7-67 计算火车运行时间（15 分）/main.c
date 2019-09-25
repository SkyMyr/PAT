#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
    int h,m,depart,arrive;
    scanf("%d%d",&depart,&arrive);
    h=arrive/100-depart/100;
    m=arrive%100-depart%100;
    if(m<0)
    {
        m=60+m;
        h=h-1;
    }
    printf("%02d:%02d\n",h,m);
	return 0;
}
