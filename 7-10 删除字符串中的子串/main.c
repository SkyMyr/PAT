#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[81], s[81], resultstr[81];
    int i, j, length, s_len;
    gets(str);
    gets(s);
    s_len = strlen(s);
    strcpy(resultstr, str);
    char *p;
    p = strstr(resultstr, s);
    length = strlen(resultstr);
    while(p != NULL) {
        for(i = p - resultstr; i < length - s_len + 1; i++) {
            resultstr[i] = resultstr[i + s_len];
        }
        length = strlen(resultstr);
        p = strstr(resultstr, s);
    }
    puts(resultstr);
    return 0;
}
