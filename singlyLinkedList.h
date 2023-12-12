#pragma once
#include <iostream>

using namespace std;

template<typename T>
class SinglyLinkedList {
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

	Node* head;
	int len;

public:

	SinglyLinkedList() {
		head = nullptr;
		len = 0;
	}

	int getLength() {
		return len;
	}

	void appendElem(T elem) {
		if (head == nullptr) {
			head = new Node(elem);
			len = 1;
		}
		else
		{
			Node* current = head;
			while (current->next != nullptr)
			{
				current = current->next;
			}
			current->next = new Node(elem);
			len++;
		}
	}

	void insertElem(T elem, int index) {
		if (index < len)
		{
			if (index == 0)
			{
				Node* temp = head;
				head = new Node(elem);
				head->next = temp;
				len++;
			}
			else
			{
				Node* current = head;
				for (int i = 0; i < index - 1; i++)
				{
					current = current->next;
				}
				Node* temp = current->next;
				current->next = new Node(elem);
				current->next->next = temp;
				len++;
			}
		}
		else
		{
			cout<< "Index out of range" << endl;
			exit(1);
		}
	}

	void deleteElem(int index) {
		if (index < len)
		{
			Node* current = head;
			for (int i = 0; i < index - 1; i++)
			{
				current = current->next;
			}

			Node* temp = current->next;
			current->next = temp->next;
			delete temp;
			len--;
		}
		else
		{
			cout << "Index out of range" << endl;
			exit(1);
		}
	}

	void clear() {
		for (int i = 0; i < len; i++)
		{
			Node* temp = head;
			head = head->next;
			delete temp;
		}
		head = nullptr;
		len = 0;
	}

	T operator[](int index) {
		Node* current = head;
		if (index < len)
		{
			for (int i = 0; i < index; i++)
			{
				current = current->next;
			}
			return current->elem;
		}
		else
		{
			cout << "Index out of range" << endl;
			exit(1);
		}
		
	}

	~SinglyLinkedList() {
		clear();
	}
};