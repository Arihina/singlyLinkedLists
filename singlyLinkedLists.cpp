#include <iostream>
#include "singlyLinkedList.h"

using namespace std;

int main()
{
    SinglyLinkedList<int> l;
    l.appendElem(5);
    l.appendElem(6);
    l.appendElem(7);
    l.appendElem(8);


    l.insertElem(100, 0);
    

    cout << "len " << l.getLength() << endl;

    l.deleteElem(1);

    l.appendElem(4);

    for (int i = 0; i < l.getLength(); i++)
    {
        cout << l[i] << " ";
    }
    l.clear();

}
