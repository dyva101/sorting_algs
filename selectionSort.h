#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include "lists.h"

template<typename T>
void selectionSort(Node<T>* head);

template<typename T>
void optimizedSelectionSort(Node<T>* head);

#include "selectionSort.cpp"
#endif // SELECTIONSORT_H