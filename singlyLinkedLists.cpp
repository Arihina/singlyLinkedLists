#include <iostream>
#include <vector>
#include <algorithm>

#include "singlyLinkedList.h"
#include "Stack.h"
#include "prototypes.h"

using namespace std;


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
    cout << endl;

    // demonstration work with stack (load Singly Linked List in Stack)
    cout << "Load elements from list 3 in stack" << endl;
    Stack<int> stack = loadStack(list3);
    stack.print();
    cout << "Top element in stack " << stack.getTop() << endl;

    cout << endl;
    cout << endl;

    // demonstration of sorting
    cout << "List 3 before sort" << endl;
    printList(list3);
    sortList(list3);
    cout << "List 3 after sort" << endl;
    printList(list3);

    cout << endl;
    cout << endl;


    // demonstration of graph traversal in depth
    cout << "Traversing the adjacency matrix in depth" << endl;
    matrix matrix1 = fillRandomSymmetricMatrix(6);
    cout << "Symmetric adjacency matrix" << endl;
    printMatrix(matrix1);
    bypassMatrixDepth(matrix1, 0);

    cout << endl;
    cout << endl;

    // demonstration of graph traversal in width
    cout << "Traversing the adjacency matrix in width" << endl;
    matrix matrix2 = fillRandomSymmetricMatrix(6);
    cout << "Symmetric adjacency matrix" << endl;
    printMatrix(matrix2);
    bypassMatrixWidth(matrix1, 0);

    cout << endl;
    cout << endl;

    // demonstration topological sorting
    cout << "Topological sorting" << endl;
    matrix matrix3 = fillRandomASymmetricMatrix(6);
    cout << "Asymmetric adjacency matrix" << endl;
    printMatrix(matrix3);
    for (int i = 0; i < matrix3.size(); i++)
    {
        cout << "Topological sorting for node " << i << endl;
        topologicalSort(matrix3, i);
        cout << endl;
    }
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


matrix fillRandomSymmetricMatrix(int size)
{
    matrix matrix(size, vector<int>(size, 0));

    for (int i = 0; i < size; i++)
    {
        vector<int> row(size, 0);
        for (int j = 0; j < size; j++)
        {
            int num = rand() % 2;
            if (i < j)
            {
                row[j] = num;
            }
        }
        matrix[i] = row;;
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i > j)
            {
                matrix[i][j] = matrix[j][i];
            }
        }
    }

    return matrix;
}

matrix fillRandomASymmetricMatrix(int size)
{
    matrix matrix(size, vector<int>(size, 0));

    for (int i = 0; i < size; i++)
    {
        vector<int> row(size, 0);
        for (int j = 0; j < size; j++)
        {
            int num = rand() % 2;
            row[j] = num;
        }
        matrix[i] = row;;
    }

    return matrix;
}

void printMatrix(matrix matrix) 
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}


void depthFirstSearch(int* visited, int node, matrix matrix)
{
    cout << node << " ";
    visited[node] = 1;

    for (int i = 0; i < matrix[node].size(); i++)
    {
        if (matrix[node][i] == 1 && visited[i] == 0)
        {
            depthFirstSearch(visited, i, matrix);
        }
    }
}

void bypassMatrixDepth(matrix matrix, int startNode)
{
    if (startNode >= matrix.size())
    {
        cout << "The node with this number is not defined" << endl;
        return;
    }

    int* visited = new int[matrix.size()];

    for (int i = 0; i < matrix.size(); i++)
    {
        visited[i] = 0;
    }

    cout << "Path: " << endl;
    depthFirstSearch(visited, startNode, matrix);

    delete[] visited;
}


void breadthFirstSearch(int* visited, int node, matrix matrix)
{
    vector<int> nodes;
    nodes.push_back(node);
    visited[node] = 1;

    int visitNode;
    while (!nodes.empty())
    {
        visitNode = nodes[0];

        cout << visitNode << " ";
        nodes.erase(nodes.begin());

        for (int i = 0; i < matrix[visitNode].size(); i++)
        {
            if (matrix[visitNode][i] == 1 && visited[i] == 0)
            {
                nodes.push_back(i);
                visited[i] = 1;
            }
        }
    }
}

void bypassMatrixWidth(matrix matrix, int startNode)
{
    if (startNode >= matrix.size())
    {
        cout << "The node with this number is not defined" << endl;
        return;
    }

    int* visited = new int[matrix.size()];

    for (int i = 0; i < matrix.size(); i++)
    {
        visited[i] = 0;
    }

    cout << "Path: " << endl;
    breadthFirstSearch(visited, startNode, matrix);

    delete[] visited;
}


void sort(matrix matrix, int node, int* visited, vector<int>& path)
{
    visited[node] = 1;

    for (int i = 0; i < matrix[node].size(); i++)
    {
        if (visited[matrix[node][i]] == 0)
        {
            sort(matrix, matrix[node][i], visited, path);
        }
    }

    path.push_back(node);
}

void topologicalSort(matrix matrix, int node)
{
    if (node >= matrix.size())
    {
        cout << "The node with this number is not defined" << endl;
        return;
    }

    int* visited = new int[matrix.size()];

    for (int i = 0; i < matrix.size(); i++)
    {
        visited[i] = 0;
    }

    vector<int> path;
    sort(matrix, node, visited, path);

    reverse(path.begin(), path.end());

    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i] << " ";
    }

    delete[] visited;
}