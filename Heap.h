#include <iostream>
#include <vector>
using namespace std;

template <typename TYPE>
class Heap
{
private:
	vector<TYPE> value;
public:
	int root()
	{
		return 0;
	}
	int last()
	{
		return this->value.size() - 1;
	}
	int left(int index)
	{
		return index * 2 + 1;
	}
	int right(int index)
	{
		return index * 2 + 2;
	}
	int parent(int index)
	{
		return (index - 1) / 2;
	}
	int size()
	{
		return this->value.size();
	}
	void print()
	{
		int rowSize = 1;
		int printPlace = 0;
		while (printPlace < this->value.size())
		{
			for (int i = rowSize - 1; i < 2 * (rowSize - 1) && printPlace < this->value.size(); i++)
			{
				cout << this->value[printPlace] << " ";
				printPlace++;
			}
			cout << endl;
			rowSize *= 2;
		}
	}
	void swap(int a, int b)
	{
		TYPE temp;
		temp = this->value[a];
		this->value[a] = this->value[b];
		this->value[b] = temp;
	}
	void insert(TYPE item)
	{
		this->value.push_back(item);
		int newIndex = this->last();
		while (newIndex > 0 && this->value[newIndex] > this->value[this->parent(newIndex)])
		{
			this->swap(newIndex, this->parent(newIndex));
			newIndex = this->parent(newIndex);
		}
	}
	TYPE read()
	{
		return this->value[this->root()];
	}
	bool hasLargerChild(int index)
	{
		return	(this->left(index) < this->value.size() &&
			this->value[index] < this->value[this->left(index)]) ||
			(this->right(index) < this->value.size() &&
				this->value[index] < this->value[this->right(index)]);
	}
	int largerChild(int index)
	{
		if (this->right(index) >= this->value.size())
			return this->left(index);
		else if (this->value[index] > this->value[this-> right(index)])
			return this->left(index);
		else
			return this->right(index);
	}
	void remove()
	{
		this->swap(this->root(), this->last());
		this->value.pop_back();
		int index = 0, big = 0;
		while (this->hasLargerChild(index))
		{
			big = this->largerChild(index);
			swap(index, big);
			index = big;
		}
	}
	void merge(Heap<TYPE> other)
	{
		int size = other.size();
		for (int i = 0; i < size; i++)
		{
			this->insert(other.read());
			other.remove();
		}
	}
};
