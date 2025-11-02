// 사용자가 0을 입력할 때까지 숫자를 더한다. 

#include <stdio.h>

#pragma warning(disable: 4996 4326 6031)

void main() 
{
	int number, sum = 0;
	do {		// 루프 몸체가 적어도 한번은 실행된다. 
		printf("정수를 입력하시오: ");
		scanf("%d", &number);
		sum += number;
	} while (number);
	printf("숫자들의 합 = %d \n", sum);
}