#include <stdio.h>
#include <stdlib.h>

int main()
{

    int n;
	int prev = 0, start = 1;
	int end = 0;
	int count = 1;
	scanf("%d", &n);
	if(n == start)
		printf("%d\n", count);
	else {
		++count;
		end = prev + start;
		while(end < n) {
			++count;
			prev = start;
			start = end;
			end = prev + start;
		}
		printf("%d\n", count);
	}
	return 0;
}
