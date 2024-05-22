#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include "lists.h"

template<typename T>
void insertionSort(Node<T>* head);

template<typename T>
void optimizedInsertionSort(Node<T>* head);

#include "insertionSort.cpp"
#endif // INSERTIONSORT_H
