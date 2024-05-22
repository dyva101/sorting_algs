#ifndef LISTS_H
#define LISTS_H

template<typename T>
struct Node {
    T iPayload;
    Node* ptrNext;
    Node* ptrPrev;
};

template<typename T>
Node<T>* createNode(T iPayload);

template<typename T>
void insertFront(Node<T>*& head, T iPayload);

template<typename T>
void displayList(Node<T>* head);

template<typename T>
Node<T>* generateRandomList(int size);

template<typename T>
void deleteAll(Node<T>*& head);

template<typename T>
Node<T>* mergeLists(Node<T>* list1, Node<T>* list2);

#include "lists.cpp"
#endif // LISTS_H