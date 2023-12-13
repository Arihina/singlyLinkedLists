#pragma once
#include <iostream>

using namespace std;

template<typename T>
class Stack {
private:

	class Node {
	public:
		T elem;
		Node* next;

		Node(T elem) {
			this->elem = elem;
			next = nullptr;
		}
	};

	Node* top;

public:
	Stack() 
	{
		top = nullptr;
	}

	void push(T elem) 
	{
		Node* temp = new Node(elem);

		if (!temp)
		{
			cout << "Stack Overflow" << endl;
			exit(1);
		}

		temp->elem = elem;
		temp->next = top;
		top = temp;
	}

	bool isEmpty()
	{
		return top == nullptr;
	}

	T getTop()
	{
		if (!isEmpty())
		{
			return top->elem;
		}
		else
		{
			exit(1);
		}
	}

	void pop()
	{
		Node* temp;

		if (top == nullptr)
		{
			cout << "Stack Underflow" << endl;
			exit(1);
		}
		else
		{
			temp = top;
			top = top->next;
			delete temp;
		}
	}

	void print()
	{
		Node* temp;

		if (top == nullptr)
		{
			cout << "Stack Underflow" << endl;
			exit(1);
		}
		else
		{
			temp = top;
			while (temp != nullptr)
			{
				cout << temp->elem << " ";
				temp = temp->next;
			}
			cout << endl;
		}
	}

	void clear()
	{
		while (top != nullptr)
		{
			Node* temp = top;
			top = top->next;
			delete temp;
		}
	}

	~Stack() 
	{
		clear();
	}
};