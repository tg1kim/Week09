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
			if (pDeque->Yield(value) == false)
				Error("empty");
			else
				printf("%d is deleted(양보)\n", value);
		}
		else if (value == -1) {
			if (pDeque->Delete(value) == false)
				Error("empty");
			else
				printf("%d is deleted(삭제)\n", value);
		}
		else if (value < 1000) {
			if (pDeque->Add(value) == false)
				Error("full");
			else
				printf("%d is inserted(삽입)\n", value);
		}
		else {
			if (pDeque->JumpIn(value %= 1000) == false)
				Error("full");
			else
				printf("%d is inserted(새치기)\n", value);
		}
		pDeque->Print();
	}
}
