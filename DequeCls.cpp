#include "Deque.h"

int Deque::IsEmpty()
{	// ť�� ��������� ���� T/F�� ��ȯ�Ѵ�.
	return true;
}

int Deque::IsFull()
{	// ť�� ���� á������ ���� T/F�� ��ȯ�Ѵ�.
	return true;
}

int Deque::Add(Item nItem)
{	// ť�� nItem�� �߰��ϴµ� ���п� ���� T/F�� ��ȯ�Ѵ�.
	return true;
}

int Deque::Delete(Item& nItem)
{	// ť���� �����Ͽ� nItem�� �����ϴµ� ���п� ���� T/F�� ��ȯ�Ѵ�.
	return true;
}

int Deque::JumpIn(Item nItem)
{	// ť�� nItem�� �ճ��� ��ġ���ϴµ� ���п� ���� T/F�� ��ȯ�Ѵ�.
	return true;
}

int Deque::Yield(Item& nItem)
{	// ť���� �ڳ��� �����Ͽ� nItem�� �����ϴµ� ���п� ���� T/F�� ��ȯ�Ѵ�.
	return true;
}

void Deque::Print()
{
	int nCtr = (m_nRear - m_nFront + N) % N;
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

