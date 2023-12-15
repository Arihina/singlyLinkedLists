#pragma once


template<typename T>
void printList(SinglyLinkedList<T>& list) {
    for (int i = 0; i < list.getLength(); i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;
}

void fillIntOrderList(int leftLim, int rightLim, int step, SinglyLinkedList<int>& list) {

    for (int i = leftLim; i < rightLim; i += step)
    {
        list.appendElem(i);
    }

}


template<typename T>
void mergeLists(SinglyLinkedList<T>& list1, SinglyLinkedList<T>& list2, SinglyLinkedList<T>& list3) {

    int len1 = list1.getLength(), len2 = list2.getLength();
    int i = 0, j = 0;

    while (i < len1 && j < len2)
    {
        if (list1[i] <= list2[j])
        {
            list3.appendElem(list1[i++]);
        }
        else
        {
            list3.appendElem(list2[j++]);
        }
    }

    if (i < len1)
    {
        for (int k = i; k < len1; k++)
        {
            list3.appendElem(list1[k]);
        }
    }
    else if (j < len2)
    {
        for (int k = j; k < len2; k++)
        {
            list3.appendElem(list2[k]);
        }
    }
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
void loadStack(SinglyLinkedList<T>& list, Stack<T>& stack)
{
    for (int i = 0; i < list.getLength(); i++)
    {
        stack.push(list[i]);
        cout << "Stack contains ";
        stack.print();
    }
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

void fillRandomList(SinglyLinkedList<int>& list, int size)
{
    for (int i = 0; i < size; i++)
    {
        list.appendElem(rand() % 100);
    }
}