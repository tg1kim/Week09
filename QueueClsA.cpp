#include "Queue.h"

int Queue::IsEmpty()
{	// ť�� ��������� ���� T/F�� ��ȯ�Ѵ�.
	return m_nFront == m_nRear;
}

int Queue::IsFull()
{	// ť�� ���� á������ ���� T/F�� ��ȯ�Ѵ�.
	return m_nRear >= N - 1;
}

int Queue::Add(Item nItem)
{	// ť�� nItem�� �߰��ϴµ� ���п� ���� T/F�� ��ȯ�Ѵ�.
	if (IsFull())
		return false;
	m_arItems[++m_nRear] = nItem;	// rear�� �����Ͽ� ����
	return true;
}

int Queue::Delete(Item& nItem)
{	// ť���� �����Ͽ� nItem�� �����ϴµ� ���п� ���� T/F�� ��ȯ�Ѵ�.
	if (IsEmpty())
		return false;
	nItem = m_arItems[++m_nFront];	// front�� �����Ͽ� �޾Ƴ�
	return true;
}

void Queue::Print()
{
	for (int i = m_nFront + 1; i <= m_nRear; i++)
		printf("--%d-", i);
	printf("--\n");
	for (int i = m_nFront + 1; i <= m_nRear; i++)
		printf("%3d ", m_arItems[i]);
	printf("\n");
	for (int i = m_nFront + 1; i <= m_nRear; i++)
		printf("----");
	printf("--\n\n");
}
