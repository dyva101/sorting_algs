#include <iostream>
#include <cstdlib>
#include <ctime>
#include "lists.h"
#include "bubbleSort.h"
#include "bucketSort.h"
#include "selectionSort.h"
#include "insertionSort.h"

using namespace std;

int main() {
    srand(time(nullptr));

    // Gerar e exibir uma lista aleatória para o teste do Selection Sort
    Node<int>* selectionSortList = generateRandomList<int>(1000);
    cout << "\nOriginal List for Selection Sort:\n" << endl;
    displayList(selectionSortList);

    // Ordenar a lista usando selection sort
    selectionSort(selectionSortList);

    // Exibir a lista ordenada
    cout << "\nSorted List with Selection Sort:\n" << endl;
    displayList(selectionSortList);

    // Liberar memória
    deleteAll(selectionSortList);

    // Gerar e exibir uma lista aleatória para o teste do Bubble Sort
    Node<int>* bubbleSortList = generateRandomList<int>(1000);
    cout << "\nOriginal List for Bubble Sort:\n" << endl;
    displayList(bubbleSortList);

    // Ordenar a lista usando bubble sort
    bubbleSort(bubbleSortList);

    // Exibir a lista ordenada
    cout << "\nSorted List with Bubble Sort:\n" << endl;
    displayList(bubbleSortList);

    // Liberar memória
    deleteAll(bubbleSortList);

    // Gerar e exibir uma lista aleatória para o teste do Bucket Sort
    Node<int>* bucketSortList = generateRandomList<int>(1000);
    cout << "\nOriginal List for Bucket Sort:\n" << endl;
    displayList(bucketSortList);

    // Ordenar a lista usando bucket sort
    bucketSortList = bucketSort(bucketSortList);

    // Exibir a lista ordenada
    cout << "\nSorted List with Bucket Sort:\n" << endl;
    displayList(bucketSortList);

    // Liberar memória
    deleteAll(bucketSortList);

    // Gerar e exibir uma lista aleatória para o teste do Insertion Sort
    Node<int>* insertionSortList = generateRandomList<int>(1000);
    cout << "\nOriginal List for Insertion Sort:\n" << endl;
    displayList(insertionSortList);

    // Ordenar a lista usando insertion sort
    insertionSort(insertionSortList);

    // Exibir a lista ordenada
    cout << "\nSorted List with Insertion Sort:\n" << endl;
    displayList(insertionSortList);

    // Liberar memória
    deleteAll(insertionSortList);

    return 0;
}