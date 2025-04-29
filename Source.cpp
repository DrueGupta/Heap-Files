#include <iostream>
#include "Heap.h"
using namespace std;

int main()
{
	Heap<int> lucky;
	lucky.insert(13);
	lucky.insert(42);
	lucky.insert(64);
	lucky.insert(74);
	lucky.insert(68);
	lucky.insert(94);
	lucky.insert(65);
	lucky.insert(73);
	lucky.insert(25);
	lucky.insert(56);
	lucky.insert(63);
	lucky.insert(25);
	lucky.insert(94);
	lucky.insert(53);
	lucky.insert(85);
	lucky.insert(44);
	lucky.print();
}
