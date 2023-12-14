#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

#include "singlyLinkedList.h"
#include "Stack.h"
#include "prototypes.h"

using namespace std;


int main()
{
    while (true)
    {
        int userInput;
        cout << "Select a task" << endl;
        cout << "1 - merging two ordered lists" << endl;
        cout << "2 - rearranging the maximum and minimum list items" << endl;
        cout << "3 - load singly linked list in stack" << endl;
        cout << "4 - sorting singly linked list" << endl;
        cout << "5 - traversing the graph in depth" << endl;
        cout << "6 - traversing the graph in width" << endl;
        cout << "7 - topological sorting" << endl;
        cout << "0 - Exit" << endl;

        cin >> userInput;

        if (userInput == 0)
        {
            cout << "Exit";
            break;
        }
        else if (userInput == 1)
        {
            cout << "Merging two ordered lists" << endl;

            int start1, stop1, step1;
            int start2, stop2, step2;

            cout << "Enter the beginning of the filling range of the first list ";
            cin >> start1;

            cout << "Enter the ending of the filling range of the first list ";
            cin >> stop1;

            cout << "Enter the step of the filling range of the first list ";
            cin >> step1;

            SinglyLinkedList<int> list1;
            fillIntOrderList(start1, stop1, step1, list1);

            cout << "Enter the beginning of the filling range of the second list ";
            cin >> start2;

            cout << "Enter the ending of the filling range of the second list ";
            cin >> stop2;

            cout << "Enter the step of the filling range of the second list ";
            cin >> step2;

            SinglyLinkedList<int> list2;
            fillIntOrderList(start2, stop2, step2, list2);

            cout << "List 1" << endl;
            printList(list1);
            cout << "List 2" << endl;
            printList(list2);

            SinglyLinkedList<int> list3;
            mergeLists(list1, list2, list3);

            cout << "List 3 (merging list 1 with list 2)" << endl;
            printList(list3);

            cout << endl;
            cout << endl;
        }
        else if (userInput == 2)
        {
            cout << "Rearranging the maximum and minimum list items" << endl;
            SinglyLinkedList<int> list;

            int size;
            cout << "Enter the size of list ";
            cin >> size;

            fillRandomList(list, size);
            printList(list);

            pair<int, int> max = findMax(list);
            cout << "Max elem in list = " << max.second << " with index " << max.first << endl;
            pair<int, int> min = findMin(list);
            cout << "Min elem in list = " << min.second << " with index " << min.first << endl;

            rearrangeElements(list, max.first, min.first);
            cout << "List with rearrange max and min elements" << endl;
            printList(list);

            cout << endl;
            cout << endl;
        }
        else if (userInput == 3)
        {
            cout << "Load singly linked list in stack" << endl;
            char newUserInput;
            cout << "Using class Stack from STL? y / n" << endl;
            cin >> newUserInput;

            if (newUserInput != 'y' && newUserInput != 'n')
            {
                cout << "Invalid input" << endl;
                continue;
            }

            int size;
            cout << "Enter the size of list ";
            cin >> size;

            SinglyLinkedList<int> list;
            fillRandomList(list, size);
            printList(list);

            if (newUserInput == 'y')
            {
                stack<int> stlStack;

                for (int i = 0; i < size; i++)
                {
                    stlStack.push(list[i]);
                    cout << "Stack contains ";
                    for (stack<int> dump = stlStack; !dump.empty(); dump.pop())
                    {
                        cout << dump.top() << " ";
                    }
                    cout << endl;
                }

                cout << "Top element in stack " << stlStack.top() << endl;

                cout << endl;
                cout << endl;
            }
            else if (newUserInput == 'n')
            {

                cout << "Load elements from list in stack" << endl;
                Stack<int> stack;
                loadStack(list, stack);
                cout << "Top element in stack " << stack.getTop() << endl;

                cout << endl;
                cout << endl;
            }
        }
        else if (userInput == 4)
        {
            cout << "Sorting singly linked list (size of list = 100)" << endl;

            SinglyLinkedList<int> list;
            fillRandomList(list, 100);

            cout << "List before sort" << endl;
            printList(list);
            sortList(list);
            cout << "List after sort" << endl;
            printList(list);

            cout << endl;
            cout << endl;
        }
        else if (userInput == 5)
        {
            cout << "Traversing the adjacency matrix in depth" << endl;

            int size;
            cout << "Enter the size of matrix ";
            cin >> size;

            matrix matrix1 = fillRandomSymmetricMatrix(size);
            cout << "Symmetric adjacency matrix" << endl;
            printMatrix(matrix1);
            bypassMatrixDepth(matrix1, 0);

            cout << endl;
            cout << endl;
        }
        else if (userInput == 6)
        {
            cout << "Traversing the adjacency matrix in width" << endl;

            int size;
            cout << "Enter the size of matrix ";
            cin >> size;

            matrix matrix1 = fillRandomSymmetricMatrix(size);
            cout << "Symmetric adjacency matrix" << endl;
            printMatrix(matrix1);
            bypassMatrixWidth(matrix1, 0);

            cout << endl;
            cout << endl;
        }
        else if (userInput == 7)
        {
            cout << "Topological sorting" << endl;

            int size;
            cout << "Enter the size of matrix ";
            cin >> size;

            matrix matrix1 = fillRandomASymmetricMatrix(size);
            cout << "Asymmetric adjacency matrix" << endl;
            printMatrix(matrix1);
            for (int i = 0; i < matrix1.size(); i++)
            {
                cout << "Topological sorting for node " << i << endl;
                topologicalSort(matrix1, i);
                cout << endl;
            }

            cout << endl;
            cout << endl;
        }
        else
        {
            cout << "Invalid input" << endl;
            cout << endl;
            cout << endl;
        }
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

void fillIntOrderList(int leftLim, int rightLim, int step, SinglyLinkedList<int>& list){

    for (int i = leftLim; i < rightLim; i+= step)
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


void fillRandomList(SinglyLinkedList<int>& list, int size)
{
    for (int i = 0; i < size; i++)
    {
        list.appendElem(rand() % 100);
    }
}