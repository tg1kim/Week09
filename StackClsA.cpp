#include "Stack.h"

int Stack::IsEmpty()
{	// ������ ��������� ���� T/F�� ��ȯ�Ѵ�.
	return m_nTop < 0;
}

int Stack::IsFull()
{	// ������ ���� á������ ���� T/F�� ��ȯ�Ѵ�.
	return m_nTop >= N - 1;
}

int Stack::Push(Item nItem)
{	// ���ÿ� nItem�� push�ϴµ� ���п� ���� T/F�� ��ȯ�Ѵ�.
	if (IsFull())
		return false;
	m_arItems[++m_nTop] = nItem;	// top�� �����Ͽ� ����
	return true;
}

int Stack::Pop(Item& nItem)
{	// ���ÿ��� pop�Ͽ� nItem�� �����ϴµ� ���п� ���� T/F�� ��ȯ�Ѵ�.
	if (IsEmpty())
		return false;
	nItem = m_arItems[m_nTop--];	// �޾Ƴ��� top�� ����
	return true;
}

void Stack::Print()
{
	printf("|    |\n");
	for (int i = m_nTop; i >= 0; i--)
		printf("|%3d |\n", m_arItems[i]);
	printf("+----+\n\n");
}
