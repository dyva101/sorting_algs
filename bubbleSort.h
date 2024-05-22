#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "lists.h"

template<typename T>
void bubbleSort(Node<T>*& head);

template<typename T>
void optimizedBubbleSort(Node<T>* head);

#include "bubbleSort.cpp"
#endif // BUBBLESORT_H

