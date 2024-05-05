#define	ADD		1
#define	DELETE	2

#include "Queue.h"

int Queue::IsEmpty()
{	// ť�� ��������� ���� T/F�� ��ȯ�Ѵ�.
	return m_nFront == m_nRear && m_nAddDel == DELETE;
}

int Queue::IsFull()
{	// ť�� ���� á������ ���� T/F�� ��ȯ�Ѵ�.
	return m_nFront == m_nRear && m_nAddDel == ADD;
}

int Queue::Add(Item nItem)
{	// ť�� nItem�� �߰��ϴµ� ���п� ���� T/F�� ��ȯ�Ѵ�.
	if (IsFull())
		return false;
	m_arItems[m_nRear = (m_nRear + 1) % N] = nItem;		// rear�� �����Ͽ� ����
	m_nAddDel = ADD;
	return true;
}

int Queue::Delete(Item& nItem)
{	// ť���� �����Ͽ� nItem�� �����ϴµ� ���п� ���� T/F�� ��ȯ�Ѵ�.
	if (IsEmpty())
		return false;
	nItem = m_arItems[m_nFront = (m_nFront + 1) % N];	// front�� �����Ͽ� �޾Ƴ�
	m_nAddDel = DELETE;
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