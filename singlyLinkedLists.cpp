#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

#include "singlyLinkedList.h"
#include "Stack.h"
#include "prototypes.h"
#include "listFunctions.h"
#include "matrixFunctions.h"

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