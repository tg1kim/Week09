#include "Stack.h"

int Stack::IsEmpty()
{	// ������ ��������� ���� T/F�� ��ȯ�Ѵ�.
	return true;
}

int Stack::IsFull()
{	// ������ ���� á������ ���� T/F�� ��ȯ�Ѵ�.
	return true;
}

int Stack::Push(Item nItem)
{	// ���ÿ� nItem�� push�ϴµ� ���п� ���� T/F�� ��ȯ�Ѵ�.
	return true;
}

int Stack::Pop(Item& nItem)
{	// ���ÿ��� pop�Ͽ� nItem�� �����ϴµ� ���п� ���� T/F�� ��ȯ�Ѵ�.
	return true;
}

void Stack::Print()
{
	printf("|    |\n");
	for (int i = m_nTop; i >= 0; i--)
		printf("|%3d |\n", m_arItems[i]);
	printf("+----+\n\n");
}
