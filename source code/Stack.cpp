#include "Stack.h"

Stack::Stack()
{
	capacity = 8;
	last = 0;
	stack = new int[capacity];
}

Stack::~Stack()
{
	if (stack != nullptr)
	{
		delete stack;
	}
}

void Stack::push(int val) {
	if (stack == nullptr)
	{
		return;
	}
	else if (capacity == last)
	{
		int* tmp = stack;
		stack = new int[capacity * 2]();
		for (int i = 0; i < capacity; i++)
		{
			stack[i] = tmp[i];
		}
		capacity *= 2;
		delete tmp;
	}
	stack[last++] = val;
}

void Stack::pop() {
	if (stack != nullptr && last > 0)
	{
		last--;
	}
}

int Stack::top() {
	return (stack != nullptr && last > 0) ? stack[last - 1] : 0;
}

int Stack::getMin() {
	int min = 0;
	if (stack != nullptr && last > 0)
	{
		min = stack[0];
		for (int i = 1; i < last; i++)
		{
			if (min > stack[i])
			{
				min = stack[i];
			}
		}
	}
	return min;
}