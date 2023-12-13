#include <iostream>

#include "singlyLinkedList.h"
#include "Stack.h"

using namespace std;

template<typename T>
void printList(SinglyLinkedList<T>&);

SinglyLinkedList<int> fillIntOrderList(int, int, int);

template<typename T>
SinglyLinkedList<T> mergeLists(SinglyLinkedList<T>&, SinglyLinkedList<T>&);

template<typename T>
void rearrangeElements(SinglyLinkedList<T>&, int, int);

template<typename T>
pair<int, T> findMax(SinglyLinkedList<T>&);

template<typename T>
pair<int, T> findMin(SinglyLinkedList<T>&);

template<typename T>
Stack<T> loadStack(SinglyLinkedList<T>&);

template<typename T>
void sortList(SinglyLinkedList<T>&);

int main()
{
    // demonstration of merging two ordered lists
    SinglyLinkedList<int> list1 = fillIntOrderList(0, 16, 3);
    SinglyLinkedList<int> list2 = fillIntOrderList(3, 7, 1);

    cout << "List 1" << endl;
    printList(list1);
    cout << "List 2" << endl;
    printList(list2);

	SinglyLinkedList<int> list3 = mergeLists(list1, list2);

    cout << "List 3 (merging list 1 with list 2)" << endl;
	printList(list3);

    cout << endl;

    // demonstration of the rearrange of the maximum and minimum elements of the list
    pair<int, int> max = findMax(list3);
    cout << "Max elem in list 3 = " << max.second << " with index " << max.first << endl;
    pair<int, int> min = findMin(list3);
    cout << "Min elem in list 3 = " << min.second << " with index " << min.first << endl;

    rearrangeElements(list3, max.first, min.first);
    cout << "List 3 with rearrange max and min elements" << endl;
    printList(list3);

    cout << endl;

    // demonstration work with stack (load Singly Linked List in Stack)
    cout << "Load elements from list 3 in stack" << endl;
    Stack<int> stack = loadStack(list3);
    stack.print();
    cout << "Top element in stack " << stack.getTop() << endl;

    cout << endl;

    // demonstration of sorting
    cout << "List 3 before sort" << endl;
    printList(list3);
    sortList(list3);
    cout << "List 3 after sort" << endl;
    printList(list3);

    cout << endl;

}


template<typename T>
void printList(SinglyLinkedList<T>& list) {
    for (int i = 0; i < list.getLength(); i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;
}


SinglyLinkedList<int> fillIntOrderList(int leftLim, int rightLim, int step) {

    SinglyLinkedList<int> list;
    for (int i = leftLim; i < rightLim; i+= step)
    {
        list.appendElem(i);
    }

    return list;
}


template<typename T>
SinglyLinkedList<T> mergeLists(SinglyLinkedList<T>& list1, SinglyLinkedList<T>& list2) {
    SinglyLinkedList<T> newList;

    int len1 = list1.getLength(), len2 = list2.getLength();
    int i = 0, j = 0;

    while (i < len1 && j < len2)
    {
        if (list1[i] <= list2[j])
        {
            newList.appendElem(list1[i++]);
        }
        else
        {
            newList.appendElem(list2[j++]);
        }
    }

    if (i < len1)
    {
        for (int k = i; k < len1; k++)
        {
            newList.appendElem(list1[k]);
        }
    }
    else if (j < len2)
    {
        for (int k = j; k < len2; k++)
        {
            newList.appendElem(list2[k]);
        }
    }

	return newList;
}


template<typename T>
pair<int, T> findMax(SinglyLinkedList<T>& list)
{
    int maxElem = list[0];
    int index = 0;

    for (int i = 0; i < list.getLength(); i++)
    {
        if (list[i] >= maxElem)
        {
            maxElem = list[i];
            index = i;
        }
    }

    return make_pair(index, maxElem);
}

template<typename T>
pair<int, T> findMin(SinglyLinkedList<T>& list)
{
    int minElem = list[0];
    int index = 0;

    for (int i = 0; i < list.getLength(); i++)
    {
        if (list[i] <= minElem)
        {
            minElem = list[i];
            index = i;
        }
    }

    return make_pair(index, minElem);
}

template<typename T>
void rearrangeElements(SinglyLinkedList<T>& list, int maxIndex, int minIndex)
{
    T elem1 = list[maxIndex];
    T elem2 = list[minIndex];

    list.insertElem(elem2, maxIndex);
    list.deleteElem(maxIndex + 1);

    list.insertElem(elem1, minIndex);
    list.deleteElem(minIndex + 1);
}


template<typename T>
Stack<T> loadStack(SinglyLinkedList<T>& list)
{
    Stack<T> stack;
    for (int i = 0; i < list.getLength(); i++)
    {
        stack.push(list[i]);
        cout << "The intermediate state of the stack" << endl;
        stack.print();
    }

    return stack;
}


template<typename T>
void sortList(SinglyLinkedList<T>& list)
{
    int temp, j;
    for (int i = 1; i < list.getLength(); i++)
    {
        j = i;
        temp = list[i];
        while (j > 0 && temp < list[j - 1])
        {
            list.insertElem(list[j - 1], j);
            list.deleteElem(j + 1);
            j--;
        }
        list.insertElem(temp, j);
        list.deleteElem(j + 1);
    }
}