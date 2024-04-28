#include "Deque.h"

void main()
{
	Deque aDeque = Deque();		// Create Deque
	Deque *pDeque = &aDeque;
	while (1) {
		int value;
		printf("-3:끝, -2:양보, -1:삭제, 0~999:삽입, *:새치기 ? ");
		scanf("%d", &value);
		if (value < -2)
			break;
		else if (value == -2) {
			if (???)
				Error("empty");
			else
				printf("%d is deleted(양보)\n", value);
		}
		else if (value == -1) {
			if (???)
				Error("empty");
			else
				printf("%d is deleted(삭제)\n", value);
		}
		else if (value < 1000) {
			if (???)
				Error("full");
			else
				printf("%d is inserted(삽입)\n", value);
		}
		else {
			if (???)
				Error("full");
			else
				printf("%d is inserted(새치기)\n", value);
		}
		???
	}
}
