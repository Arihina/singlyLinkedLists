#include <iostream>
#include "singlyLinkedList.h"

using namespace std;

template<typename T>
void printList(SinglyLinkedList<T>&);

SinglyLinkedList<int> fillIntOrderList(int, int, int);

int main()
{
    SinglyLinkedList<int> list = fillIntOrderList(1, 6, 1);
    printList(list);

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
