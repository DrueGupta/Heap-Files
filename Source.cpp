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

	srand(time(NULL));
	Heap<int> test1;
	Heap<int> test2;
	for (int i = 0; i < 20 + 1; i++)
	{
		test1.insert(rand() % 100);
	}
	for (int i = 0; i < (rand() % 20 + 1); i++)
	{
		test2.insert(rand() % 100);
	}
	test1.merge(test2);
	test1.print();
	test2.print();
}
