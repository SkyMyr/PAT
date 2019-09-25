#include <stdio.h>
#include <stdlib.h>

int main()
{
    int s;
    scanf("%d",&s);
    if(s>=90&&s<=100)
        printf("A");
    else if(s>=80&&s<=89)
        printf("B");
    else if(s>=70&&s<=79)
        printf("C");
    else if(s>=60&&s<=69)
        printf("D");
    else if(s>=0&&s<60)
        printf("E");
    return 0;
}
