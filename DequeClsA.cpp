#include "Deque.h"

int Deque::IsEmpty()
{	// ť�� ��������� ���� T/F�� ��ȯ�Ѵ�.
	return m_nFront == m_nRear;
}

int Deque::IsFull()
{	// ť�� ���� á������ ���� T/F�� ��ȯ�Ѵ�.
	return (m_nRear + 1) % N == m_nFront;
}

int Deque::Add(Item nItem)
{	// ť�� nItem�� �߰��ϴµ� ���п� ���� T/F�� ��ȯ�Ѵ�.
	if (IsFull())
		return false;
	m_arItems[m_nRear = (m_nRear + 1) % N] = nItem;		// rear�� �����Ͽ� ����
	return true;
}

int Deque::Delete(Item& nItem)
{	// ť���� �����Ͽ� nItem�� �����ϴµ� ���п� ���� T/F�� ��ȯ�Ѵ�.
	if (IsEmpty())
		return false;
	nItem = m_arItems[m_nFront = (m_nFront + 1) % N];	// front�� �����Ͽ� �޾Ƴ�
	return true;
}

int Deque::JumpIn(Item nItem)
{	// ť�� nItem�� �ճ��� ��ġ���ϴµ� ���п� ���� T/F�� ��ȯ�Ѵ�.
	if (IsFull())
		return false;
	m_arItems[m_nFront] = nItem;
	m_nFront = (m_nFront + N - 1) % N;					// front�� item�� �ְ� ����
	return true;
}

int Deque::Yield(Item& nItem)
{	// ť���� �ڳ��� �����Ͽ� nItem�� �����ϴµ� ���п� ���� T/F�� ��ȯ�Ѵ�.
	if (IsEmpty())
		return false;
	nItem = m_arItems[m_nRear];
	m_nRear = (m_nRear + N - 1) % N;					// rear�� item�� �޾Ƴ��� ����
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

