#pragma once
class Stack
{
public:
	Stack();
	~Stack();
	void push(int val);
	void pop();
	int top();
	int getMin();
private:
	int* stack = nullptr;
	int capacity = 0, last = 0;
};