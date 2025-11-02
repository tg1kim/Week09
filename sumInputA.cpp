// while 문을 이용한 합계 프로그램

#include <stdio.h>

#pragma warning(disable: 4996 4326 6031)

void main() 
{
	int i = 0, n, sum = 0;
	while (++i <= 5) {
		printf("값을 입력하시오: ");
		scanf("%d", &n);
		sum = sum + n;	// sum += n;과 같다.
	}
	printf("합계는 %d입니다.\n", sum);
}
