#include "insertionSort.h"

template<typename T>
void insertionSort(Node<T>* head) {
    if (head == nullptr || head->ptrNext == nullptr) {
        return;
    }

    Node<T>* current = head->ptrNext;
    while (current != nullptr) {
        T key = current->iPayload;
        Node<T>* prev = current->ptrPrev;
        while (prev != nullptr && prev->iPayload > key) {
            prev->ptrNext->iPayload = prev->iPayload;
            prev = prev->ptrPrev;
        }
        if (prev == nullptr) {
            head->iPayload = key;
        } else {
            prev->ptrNext->iPayload = key;
        }
        current = current->ptrNext;
    }
}

template<typename T>
void optimizedInsertionSort(Node<T>* head) {
    if (head == nullptr || head->ptrNext == nullptr) {
        return;
    }

    Node<T>* sorted = nullptr;
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* next = current->ptrNext;
        if (sorted == nullptr || sorted->iPayload >= current->iPayload) {
            current->ptrNext = sorted;
            if (sorted != nullptr) {
                sorted->ptrPrev = current;
            }
            sorted = current;
            sorted->ptrPrev = nullptr;
        } else {
            Node<T>* temp = sorted;
            while (temp->ptrNext != nullptr && temp->ptrNext->iPayload < current->iPayload) {
                temp = temp->ptrNext;
            }
            current->ptrNext = temp->ptrNext;
            if (temp->ptrNext != nullptr) {
                temp->ptrNext->ptrPrev = current;
            }
            temp->ptrNext = current;
            current->ptrPrev = temp;
        }
        current = next;
    }
    // Copiando o sorted de volta para head
    while (sorted->ptrPrev != nullptr) {
        sorted = sorted->ptrPrev;
    }
    head = sorted;
}
