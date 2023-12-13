#include <iostream>
#include "singlyLinkedList.h"

using namespace std;

template<typename T>
void printList(SinglyLinkedList<T>&);

SinglyLinkedList<int> fillIntOrderList(int, int, int);

template<typename T>
SinglyLinkedList<T> mergeLists(SinglyLinkedList<T>&, SinglyLinkedList<T>&);

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
