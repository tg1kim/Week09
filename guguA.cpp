// while 문을 이용한 구구단 출력 프로그램

#include <stdio.h>

#pragma warning(disable: 4996 4326 6031)

void main() 
{
	int n;
	int i = 1;
	printf("출력하고 싶은 단: ");
	scanf("%d", &n);
	while (i <= 9) {
		printf("%d x %d = %2d \n", n, i, n*i);
		i++;
	}
}
