//[Base.h]
#pragma once
#include <stdio.h>
#pragma warning (disable: 4326 4996 6031)

#define	M	11
#define	N	15
#define	M2	(M + 2)
#define	N2	(N + 2)
#define StackSize (M * N)

typedef char Arr2Dim[M2][N2];	// 2차원 배열 미로 타입을 정의한다.

typedef struct {				// 다음 좌표를 쉽게 구하기 위하여
	int nRow;
	int nCol;
}	Offsets;

typedef struct {				// 미로에서 위치와 방향
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
	if (aMaze.FindPath())				// 길을 찾았다.
		aMaze.PrintPath();
	else								// 길이 없다.
		printf("No path has been found.\n");
}

[Maze.h]
#pragma once
#include "Stack.h"

class Maze {
	Arr2Dim m_arMaze;		// 길을 찾을 미로
	Arr2Dim m_arMark;		// 왔던 표시
	Stack   m_aStack;		// 스택이 하나 필요
	Step    m_curStep;		// 현재 위치와 방향
	Step    m_nxtStep;		// 다음 위치와 방향

	void DoMark();			// 현재 위치를 표시한다.
	int  IsMoreDirection();	// 현재 위치에서 갈 방향이 있는가?
	void GetNextPosition();	// 현재 위치에서 다음 위치를 구함
	int  IsGoal();			// 다음 위치가 목표인가?
	int  CanGo();			// 다음 위치가 미로에서 갈 수 있는가?
	int  IsNotMarked();		// 다음 위치에 표시가 없는가?

public:
	Maze(Arr2Dim arMaze);	// 미로와 미로를 찾을 환경을 설정
	int  FindPath();		// 설정된 환경에서 미로는 찾음
	void PrintPath();		// 찾은 미로를 출력
};

[Maze.cpp]
#include "Maze.h"

Maze::Maze(Arr2Dim arMaze)					// 미로 arMaze를 입력으로
{	// m_arMaze와 m_arMark를 초기화 한다.
}

int Maze::FindPath()						// 미로에서 길을 찾아라.
{
	현재 위치를 시작 위치로
	현재 위치의 시작 방향을 0번으로
	현재 위치를 표시한다
	현재 위치를 스택에 push한다
	while (빈 스택이 아니다) {
		스택에서 pop하여 현재 위치에 저장한다
		while (현재 위치에서 더 길이 있다) {
			다음 위치(m_nxtStep)을 설정
			if (다음 위치가 목표이다) {
				현재 위치를 스택에 저장한다.
				목표 위치를 스택에 저장한다.
				return true;			// 길을 찾았다.
			}
			if (다음 위치가 갈 수 있다 &&
			   다음 위치가 왔던 곳이 아니다) {
				다음에 찾을 방향을 설정한다
				현재 위치를 스택에 저장하라
				새로운 위치로 전진하라
				현재 위치를 표시하라.
				현재 위치의 시작 방향을 0번으로
			}
			else
				다음 방향을 설정하라
		}
	}
	return false;						// 길을 못 찾았다.
}

void Maze::PrintPath()						// 스택에 저장된 길을 출력하라.
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

int Maze::IsGoal()							// 목표에 도달하였는가?
{
	return true;
}

int Maze::IsNotMarked()						// 이미 왔던 곳이 아닌가?
{
	return true;
}

int Maze::CanGo()							// 갈수 있는 길인가?
{
	return true;
}

void Maze::DoMark()							// 왔던 곳으로 표시하라.
{
	// ??
}

int Maze::IsMoreDirection()					// 더 갈 길이 있는가?
{
	return true;
}

void Maze::GetNextPosition()				// 갈 다음 위치를 설정한다
{
	static Offsets move[8] = {
		{1, 1},		// 남동
		{1, 0},		// 남
		{0, 1},		// 동
		{-1, 1},	// 북동
		{1, -1},	// 남서
		{-1, 0},	// 서
		{0, -1},	// 북
		{-1, -1}};	// 북서
	// m_curStep으로부터 m_nxtStep을 설정한다
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
