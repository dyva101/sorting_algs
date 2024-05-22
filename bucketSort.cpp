#include "bucketSort.h"
#include "bubbleSort.h"

template<typename T>
Node<T>* bucketSort(Node<T>* head) {
    const int numBuckets = 10;
    Node<T>* buckets[numBuckets] = { nullptr };

    // Distribuir elementos em buckets
    Node<T>* current = head;
    while (current != nullptr) {
        int bucketIndex = current->iPayload / 10;
        Node<T>* nextNode = current->ptrNext;
        current->ptrNext = buckets[bucketIndex];
        buckets[bucketIndex] = current;
        current = nextNode;
    }

    // Ordenar cada bucket e mesclar de volta na lista original
    Node<T>* sortedList = nullptr;
    for (int i = 0; i < numBuckets; ++i) {
        bubbleSort(buckets[i]);
        sortedList = mergeLists(sortedList, buckets[i]);
    }

    return sortedList;
}