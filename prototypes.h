#pragma once

#include "singlyLinkedList.h"
#include "Stack.h"
#include <vector>

typedef vector<vector<int>> matrix;

matrix fillRandomSymmetricMatrix(int);

matrix fillRandomASymmetricMatrix(int);

void printMatrix(matrix);

template<typename T>
void printList(SinglyLinkedList<T>&);

void fillIntOrderList(int, int, int, SinglyLinkedList<int>&);

template<typename T>
void mergeLists(SinglyLinkedList<T>&, SinglyLinkedList<T>&, SinglyLinkedList<T>&);

template<typename T>
void rearrangeElements(SinglyLinkedList<T>&, int, int);

template<typename T>
pair<int, T> findMax(SinglyLinkedList<T>&);

template<typename T>
pair<int, T> findMin(SinglyLinkedList<T>&);

template<typename T>
void loadStack(SinglyLinkedList<T>&, Stack<T>&);

template<typename T>
void sortList(SinglyLinkedList<T>&);

void bypassMatrixDepth(matrix, int);

void bypassMatrixWidth(matrix, int);

void depthFirstSearch(int*, int, matrix);

void breadthFirstSearch(int*, int, matrix);

void topologicalSort(matrix, int);

void sort(matrix, int, int*, vector<int>&);

void fillRandomList(SinglyLinkedList<int>&, int);
