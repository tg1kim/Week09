#include "Deque.h"

#define	LEN	50

void main()
{
	void Forward(char aMsg[]);
	void Backward(char aMsg[]);
	while (1) {
		printf("Message ? ");
		char aMsg[LEN];
		gets_s(aMsg);
		if (aMsg[0] == 0)
			break;
		Forward(aMsg);
		Backward(aMsg);
		putchar('\n');
	}
	printf("\nBye, ...\n");
}

void Forward(char aMsg[])
{
	printf(" Forward: ");
	Item aItem;
	Deque aDeque;
	for (int i = 0; aMsg[i]; i++)
		aDeque.JumpIn(aMsg[i]);
	while (aDeque.IsEmpty() == false) {
		aDeque.Yield(aItem);
		putchar(aItem);
	}
	putchar('\n');
}

void Backward(char aMsg[])
{
	printf("Backward: ");
	Item aItem;
	Deque aDeque;
	for (int i = 0; aMsg[i]; i++)
		aDeque.JumpIn(aMsg[i]);
	while (aDeque.IsEmpty() == false) {
		aDeque.Delete(aItem);
		putchar(aItem);
	}
	putchar('\n');
}
