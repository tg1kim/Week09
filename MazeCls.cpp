//[Base.h]
#pragma once
#include <stdio.h>
#pragma warning (disable: 4326 4996 6031)

#define	M	11
#define	N	15
#define	M2	(M + 2)
#define	N2	(N + 2)
#define StackSize (M * N)

typedef char Arr2Dim[M2][N2];	// 2���� �迭 �̷� Ÿ���� �����Ѵ�.

typedef struct {				// ���� ��ǥ�� ���� ���ϱ� ���Ͽ�
	int nRow;
	int nCol;
}	Offsets;

typedef struct {				// �̷ο��� ��ġ�� ����
	int nRow;
	int nCol;
	int nDir;
}	Step, *StepPtr;

//[Main.cpp]
#include "Maze.h"

void main()
{
	Arr2Dim arMaze = {
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1 },
		{ 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
		{ 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 1 },
		{ 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1 },
		{ 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1 },
		{ 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1 },
		{ 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } };

	Maze aMaze = Maze(arMaze);
	if (aMaze.FindPath())				// ���� ã�Ҵ�.
		aMaze.PrintPath();
	else								// ���� ����.
		printf("No path has been found.\n");
}

[Maze.h]
#pragma once
#include "Stack.h"

class Maze {
	Arr2Dim m_arMaze;		// ���� ã�� �̷�
	Arr2Dim m_arMark;		// �Դ� ǥ��
	Stack   m_aStack;		// ������ �ϳ� �ʿ�
	Step    m_curStep;		// ���� ��ġ�� ����
	Step    m_nxtStep;		// ���� ��ġ�� ����

	void DoMark();			// ���� ��ġ�� ǥ���Ѵ�.
	int  IsMoreDirection();	// ���� ��ġ���� �� ������ �ִ°�?
	void GetNextPosition();	// ���� ��ġ���� ���� ��ġ�� ����
	int  IsGoal();			// ���� ��ġ�� ��ǥ�ΰ�?
	int  CanGo();			// ���� ��ġ�� �̷ο��� �� �� �ִ°�?
	int  IsNotMarked();		// ���� ��ġ�� ǥ�ð� ���°�?

public:
	Maze(Arr2Dim arMaze);	// �̷ο� �̷θ� ã�� ȯ���� ����
	int  FindPath();		// ������ ȯ�濡�� �̷δ� ã��
	void PrintPath();		// ã�� �̷θ� ���
};

[Maze.cpp]
#include "Maze.h"

Maze::Maze(Arr2Dim arMaze)					// �̷� arMaze�� �Է�����
{	// m_arMaze�� m_arMark�� �ʱ�ȭ �Ѵ�.
}

int Maze::FindPath()						// �̷ο��� ���� ã�ƶ�.
{
	���� ��ġ�� ���� ��ġ��
	���� ��ġ�� ���� ������ 0������
	���� ��ġ�� ǥ���Ѵ�
	���� ��ġ�� ���ÿ� push�Ѵ�
	while (�� ������ �ƴϴ�) {
		���ÿ��� pop�Ͽ� ���� ��ġ�� �����Ѵ�
		while (���� ��ġ���� �� ���� �ִ�) {
			���� ��ġ(m_nxtStep)�� ����
			if (���� ��ġ�� ��ǥ�̴�) {
				���� ��ġ�� ���ÿ� �����Ѵ�.
				��ǥ ��ġ�� ���ÿ� �����Ѵ�.
				return true;			// ���� ã�Ҵ�.
			}
			if (���� ��ġ�� �� �� �ִ� &&
			   ���� ��ġ�� �Դ� ���� �ƴϴ�) {
				������ ã�� ������ �����Ѵ�
				���� ��ġ�� ���ÿ� �����϶�
				���ο� ��ġ�� �����϶�
				���� ��ġ�� ǥ���϶�.
				���� ��ġ�� ���� ������ 0������
			}
			else
				���� ������ �����϶�
		}
	}
	return false;						// ���� �� ã�Ҵ�.
}

void Maze::PrintPath()						// ���ÿ� ����� ���� ����϶�.
{
	Arr2Dim arMaze;
	for (int i = 0; i < M + 2; i++)
		for (int j = 0; j < N + 2; j++)		// 0->'0', 1->'1', mark->'*'
			arMaze[i][j] = m_arMark[i][j] ? '*' : m_arMaze[i][j] + 0x30;
	Step step;
	while (!m_aStack.IsEmpty()) {
		m_aStack.Pop(&step);
		arMaze[step.nRow][step.nCol] = 'x';	// path->'x'
	}
	for (int i = 0; i < M + 2; i++) {
		for (int j = 0; j < N + 2; j++)
			putchar(arMaze[i][j]);
		putchar('\n');
	}
}

int Maze::IsGoal()							// ��ǥ�� �����Ͽ��°�?
{
	return true;
}

int Maze::IsNotMarked()						// �̹� �Դ� ���� �ƴѰ�?
{
	return true;
}

int Maze::CanGo()							// ���� �ִ� ���ΰ�?
{
	return true;
}

void Maze::DoMark()							// �Դ� ������ ǥ���϶�.
{
	// ??
}

int Maze::IsMoreDirection()					// �� �� ���� �ִ°�?
{
	return true;
}

void Maze::GetNextPosition()				// �� ���� ��ġ�� �����Ѵ�
{
	static Offsets move[8] = {
		{1, 1},		// ����
		{1, 0},		// ��
		{0, 1},		// ��
		{-1, 1},	// �ϵ�
		{1, -1},	// ����
		{-1, 0},	// ��
		{0, -1},	// ��
		{-1, -1}};	// �ϼ�
	// m_curStep���κ��� m_nxtStep�� �����Ѵ�
}

[Stack.h]
#pragma once
#include "Base.h"

class Stack {
	int  m_nTop;
	Step m_arSteps[StackSize];

public:
	Stack() { m_nTop = -1; };
	int  IsEmpty();
	void Push(StepPtr pStep);
	void Pop(StepPtr pStep);
};

[Stack.cpp]
#include "Stack.h"

int Stack::IsEmpty()
{
	return m_nTop < 0;
}

void Stack::Push(StepPtr pStep)
{
	m_arSteps[++m_nTop] = *pStep;
}

void Stack::Pop(StepPtr pStep)
{
	*pStep = m_arSteps[m_nTop--];
}
