// while 문을 이용한 성적의 평균 구하기 프로그램

#include <stdio.h>

#pragma warning(disable: 4996 4326 6031)

void main() 
{
	int grade, n, sum;
	float average;
	// 필요한 변수들을 초기화한다.
	n = grade = sum =0;
	printf("성적 입력을 종료하려면 음수를 입력하시오\n");
	// 성적을 입력받아서 합계를 구하고 학생 수를 센다.
	while (1) {
		printf("성적을 입력하시오: ");
		scanf("%d", &grade);
		if (grade < 0)
			break;
		sum += grade;
		n++;
	}
	// 평균을 계산하고 화면에 출력한다.
	average = (float)sum / n;
	printf("성적의 평균은 %.2f입니다.\n", average);
}
