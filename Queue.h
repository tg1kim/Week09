#include <stdio.h>
#pragma warning (disable: 4326 4996 6031 26495)

#define N		10
//#define	SHIFT
//#define	TAG
//#define	ADD		1
//#define	DELETE	2

int Error(const char* sMsg);

typedef int Item;

class Queue {
	// m_arItems
	// m_nFront
	// m_nRear
#ifdef TAG
	// m_nAddDel
#endif
	// constructor
	// IsEmpty
	// IsFull
	// Add
	// Delete
#ifdef SHIFT
	// CanNotShift
#endif
	// Print
};
