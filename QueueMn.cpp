#include "Queue.h"

void main()
{
	Queue aQueue = Queue();		// Create Queue
	Queue *pQueue = &aQueue;
	while (1) {
		int nItem;
		printf("-2:Exit -1:Delete, *:Add ? ");
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
	printf("***** Queue is %s. *****\n", sMsg);
	return -1;
}

