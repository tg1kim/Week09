#include "Stack.h"

void main()
{
	Stack aStack = Stack();		// Create Stack
	while (1) {
		Item nItem;
		printf("-2:Exit -1:Pop, *:Push ? ");
		scanf("%d", &nItem);
		if (nItem < -1)
			break;
		else if (nItem == -1) {
			if (???)
				Error("empty");
			else
				printf("%d is deleted\n", nItem);
		}
		else {
			if (???)
				Error("full");
			else
				printf("%d is inserted\n", nItem);
		}
		???
	}
}

int Error(const char *sMsg)
{
	printf("***** Stack is %s. *****\n", sMsg);
	return false;
}
