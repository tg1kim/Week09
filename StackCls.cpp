#include "Stack.h"

int Stack::IsEmpty()
{	// 스택이 비었는지에 따라 T/F를 반환한다.
	return true;
}

int Stack::IsFull()
{	// 스택이 가득 찼는지에 따라 T/F를 반환한다.
	return true;
}

int Stack::Push(Item nItem)
{	// 스택에 nItem을 push하는데 승패에 따라 T/F를 반환한다.
	return true;
}

int Stack::Pop(Item& nItem)
{	// 스택에서 pop하여 nItem에 저장하는데 승패에 따라 T/F를 반환한다.
	return true;
}

void Stack::Print()
{
	printf("|    |\n");
	for (int i = m_nTop; i >= 0; i--)
		printf("|%3d |\n", m_arItems[i]);
	printf("+----+\n\n");
}
