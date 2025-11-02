// while 문을 이용한 최대 공약수 구하기 프로그램
#include <stdio.h>

#pragma warning(disable: 4996 4326 6031)

void main() 
{
	int x, y, r;
	printf("두 개의 정수를 입력하시오(큰수, 작은수): ");
	scanf("%d%d", &x, &y);
	while (y != 0) {
		r = x % y;
		x = y;
		y = r;
	}
	printf("최대 공약수는 %d입니다.\n", x);
}
