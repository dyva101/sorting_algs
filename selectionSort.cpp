#include "selectionSort.h"

template<typename T>
void selectionSort(Node<T>* head) {
    if (head == nullptr || head->ptrNext == nullptr) {
        return;
    }

    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* start = current->ptrNext;
        while (start != nullptr) {
            if (current->iPayload > start->iPayload) {
                std::swap(current->iPayload, start->iPayload);
            }
            start = start->ptrNext;
        }
        current = current->ptrNext;
    }
}

template<typename T>
void optimizedSelectionSort(Node<T>* head) {
    if (head == nullptr || head->ptrNext == nullptr) {
        return;
    }
    Node<T>* current = head;
    while (current->ptrNext != nullptr) {
        Node<T>* minNode = current;
        Node<T>* temp = current->ptrNext;
        while (temp != nullptr) {
            if (temp->iPayload < minNode->iPayload) {
                minNode = temp;
            }
            temp = temp->ptrNext;
        }
        std::swap(current->iPayload, minNode->iPayload);
        current = current->ptrNext;
    }
}