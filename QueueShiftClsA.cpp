#include "Queue.h"

int Queue::IsEmpty()
{	// 큐가 비었는지에 따라 T/F를 반환한다.
	return m_nFront == m_nRear;
}

int Queue::CanNotShift()
{	// 빈 공간이 있으면 데이터를 이동시키는데 큐의 가득 여부에 따라 T/F를 반환한다.
	if (m_nFront != -1) {
		int nTo = -1;
		for (int nFrom = m_nFront + 1; nFrom < N; nFrom++)
			m_arItems[++nTo] = m_arItems[nFrom];
		m_nFront = -1;
		m_nRear = nTo;
	}
	return m_nRear == N - 1;
}

int Queue::IsFull()
{	// 큐가 가득 찼는지에 따라 T/F를 반환한다.
	return m_nRear >= N - 1 && CanNotShift();
}

int Queue::Add(Item nItem)
{	// 큐에 nItem을 추가하는데 승패에 따라 T/F를 반환한다.
	if (IsFull())
		return false;
	m_arItems[++m_nRear] = nItem;	// rear를 증가하여 삽입
	return true;
}

int Queue::Delete(Item& nItem)
{	// 큐에서 삭제하여 nItem에 저장하는데 승패에 따라 T/F를 반환한다.
	if (IsEmpty())
		return false;
	nItem = m_arItems[++m_nFront];	// front를 증가하여 받아냄
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
