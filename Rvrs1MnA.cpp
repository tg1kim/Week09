#include "Stack.h"

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
	Stack aStack1, aStack2;
	for (int i = 0; aMsg[i]; i++)
		aStack1.Push(aMsg[i]);
	while (aStack1.IsEmpty() == false) {
		aStack1.Pop(aItem);
		aStack2.Push(aItem);
	}
	while (aStack2.IsEmpty() == false) {
		aStack2.Pop(aItem);
		putchar(aItem);
	}
	putchar('\n');
}

void Backward(char aMsg[])
{
	printf("Backward: ");
	Item aItem;
	Stack aStack;
	for (int i = 0; aMsg[i]; i++)
		aStack.Push(aMsg[i]);
	while (aStack.IsEmpty() == false) {
		aStack.Pop(aItem);
		putchar(aItem);
	}
	putchar('\n');
}
