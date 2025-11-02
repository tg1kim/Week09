#include <stdio.h>

#pragma warning(disable: 4996 4326 6031)

void main() 
{
	int i = 3;
	while (i) {
		printf("%d은 참입니다.\n", i);
		i--;
	}
	printf("%d은 거짓입니다.\n", i);
}
