#include "Queue.h"

int Queue::IsEmpty()
{	// ť�� ��������� ���� T/F�� ��ȯ�Ѵ�.
	return true;
}

int Queue::IsFull()
{	// ť�� ���� á������ ���� T/F�� ��ȯ�Ѵ�.
	return true;
}

int Queue::Add(Item nItem)
{	// ť�� nItem�� �߰��ϴµ� ���п� ���� T/F�� ��ȯ�Ѵ�.
	return true;
}

int Queue::Delete(Item& nItem)
{	// ť���� �����Ͽ� nItem�� �����ϴµ� ���п� ���� T/F�� ��ȯ�Ѵ�.
	return true;
}

void Queue::Print()
{
	int nCtr = (m_nRear - m_nFront + N) % N;
	nCtr += IsFull() * N;
	for (int i = 1; i <= nCtr; i++)
		printf("--%d-", (m_nFront + i) % N);
	printf("--\n");
	for (int i = 1; i <= nCtr; i++)
		printf("%3d ", m_arItems[(m_nFront + i) % N]);
	printf("\n");
	for (int i = 1; i <= nCtr; i++)
		printf("----");
	printf("--\n\n");
}
