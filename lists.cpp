#include "lists.h"
#include <iostream>
#include <cstdlib>

template<typename T>
Node<T>* createNode(T iPayload) {
    Node<T>* temp = new Node<T>;
    temp->iPayload = iPayload;
    temp->ptrNext = nullptr;
    temp->ptrPrev = nullptr;
    return temp;
}

template<typename T>
void insertFront(Node<T>*& head, T iPayload) {
    Node<T>* newNode = createNode(iPayload);
    if (head == nullptr) {
        head = newNode;
    } else {
        newNode->ptrNext = head;
        head = newNode;
    }
}

template<typename T>
void displayList(Node<T>* head) {
    Node<T>* temp = head;
    while (temp != nullptr) {
        std::cout << temp->iPayload << " ";
        temp = temp->ptrNext;
    }
    std::cout << std::endl;
}

template<typename T>
Node<T>* generateRandomList(int size) {
    Node<T>* head = nullptr;
    for (int i = 0; i < size; ++i) {
        insertFront(head, rand() % 100 + 1);
    }
    return head;
}

template<typename T>
void deleteAll(Node<T>*& head) {
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* temp = current->ptrNext;
        delete current;
        current = temp;
    }
    head = nullptr;
}

template<typename T>
Node<T>* mergeLists(Node<T>* list1, Node<T>* list2) {
    if (list1 == nullptr) return list2;
    if (list2 == nullptr) return list1;

    Node<T>* mergedList = nullptr;
    Node<T>** ptr = &mergedList;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->iPayload <= list2->iPayload) {
            *ptr = list1;
            list1 = list1->ptrNext;
        } else {
            *ptr = list2;
            list2 = list2->ptrNext;
        }
        ptr = &(*ptr)->ptrNext;
    }

    if (list1 != nullptr) {
        *ptr = list1;
    } else {
        *ptr = list2;
    }

    return mergedList;
}
