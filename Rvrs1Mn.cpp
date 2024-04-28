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
	// ???
	putchar('\n');
}

void Backward(char aMsg[])
{
	printf("Backward: ");
	Item aItem;
	// ???
	putchar('\n');
}
