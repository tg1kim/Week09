#include "Queue.h"

int Queue::IsEmpty()
{	// 큐가 비었는지에 따라 T/F를 반환한다.
	return m_nFront == m_nRear;
}

int Queue::IsFull()
{	// 큐가 가득 찼는지에 따라 T/F를 반환한다.
	return (m_nRear + 1) % N == m_nFront;
}

int Queue::Add(Item nItem)
{	// 큐에 nItem을 추가하는데 승패에 따라 T/F를 반환한다.
	if (IsFull())
		return false;
	m_arItems[m_nRear = (m_nRear + 1) % N] = nItem;		// rear를 증가하여 삽입
	return true;
}

int Queue::Delete(Item& nItem)
{	// 큐에서 삭제하여 nItem에 저장하는데 승패에 따라 T/F를 반환한다.
	if (IsEmpty())
		return false;
	nItem = m_arItems[m_nFront = (m_nFront + 1) % N];	// front를 증가하여 받아냄
	return true;
}

void Queue::Print()
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
