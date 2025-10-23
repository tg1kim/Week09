#include <stdio.h>

#pragma warning(disable: 4996 4326 6031)

void main() 
{
	"반감기를 입력하시오(년): "
	halflife에 입력한다
	initial에 100을, final에 initial의 1/10로 설정한다
	current를 initial로 설정한다
	current가 final보다 클 동안 { 
		years에 halflife를 더한다
		current를 반으로 설정한다
		"%d년 후에 남은 양 = %.2f\n"
	}
	"1/10 이하로 되기까지 걸린 시간 = %d년\n"
}