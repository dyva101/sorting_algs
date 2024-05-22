#include "bubbleSort.h"

template<typename T>
void bubbleSort(Node<T>*& head) {
    if (head == nullptr || head->ptrNext == nullptr) {
        return;
    }

    bool swapped;
    Node<T>* end = nullptr;
    do {
        swapped = false;
        Node<T>** ptr = &head;
        while ((*ptr)->ptrNext != end) {
            Node<T>* current = *ptr;
            Node<T>* next = current->ptrNext;
            if (current->iPayload > next->iPayload) {
                current->ptrNext = next->ptrNext;
                next->ptrNext = current;
                *ptr = next;
                swapped = true;
            }
            ptr = &(*ptr)->ptrNext;
        }
        end = *ptr;
    } while (swapped);
}

template<typename T>
void optimizedBubbleSort(Node<T>* head) {
    if (head == nullptr || head->ptrNext == nullptr) {
        return;
    }

    bool unordered;
    Node<T>* lastNode = nullptr;
    do {
        unordered = false;
        Node<T>* current = head;
        while (current->ptrNext != lastNode) {
            if (current->iPayload > current->ptrNext->iPayload) {
                std::swap(current->iPayload, current->ptrNext->iPayload);
                unordered = true;
            }
            current = current->ptrNext;
        }
        lastNode = current;
    } while (unordered);
}
