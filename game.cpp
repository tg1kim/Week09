#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#pragma warning(disable: 4996 4326 6031)

void main() 
{
	time 함수로 시드 설정
	answer를 1~100으로 설정
	tries를 0으로 초기화
	// 반복 구조
	반복 시작
		"정답을 추측하여 보시오: "
		guess에 입력
		tries 증가
		"HIGH\n" 또는 "LOW\n"
	반복 끝 guess와 answer가 다를 동안
	"축하합니다. 시도횟수 = %d\n"
}