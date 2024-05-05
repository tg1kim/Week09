#include "Stack.h"

int Stack::IsEmpty()
{	// 스택이 비었는지에 따라 T/F를 반환한다.
	return m_nTop < 0;
}

int Stack::IsFull()
{	// 스택이 가득 찼는지에 따라 T/F를 반환한다.
	return m_nTop >= N - 1;
}

int Stack::Push(Item nItem)
{	// 스택에 nItem을 push하는데 승패에 따라 T/F를 반환한다.
	if (IsFull())
		return false;
	m_arItems[++m_nTop] = nItem;	// top을 증가하여 삽입
	return true;
}

int Stack::Pop(Item& nItem)
{	// 스택에서 pop하여 nItem에 저장하는데 승패에 따라 T/F를 반환한다.
	if (IsEmpty())
		return false;
	nItem = m_arItems[m_nTop--];	// 받아내고 top을 감소
	return true;
}

void Stack::Print()
{
	printf("|    |\n");
	for (int i = m_nTop; i >= 0; i--)
		printf("|%3d |\n", m_arItems[i]);
	printf("+----+\n\n");
}
