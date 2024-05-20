#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime> 

using std::cin;
using std::cout;
using std::endl;
using std::string;

typedef struct Node {
    int iPayload;
    Node* ptrNext;
    Node* ptrPrev;
} Node;

Node* createNode(int);
void insertFront(Node**, int);
void insertEnd(Node**, int);
void displayList(Node*);
void deleteAll(Node*&);
Node* generateRandomList(int);

int main() 
{
    // Seed para números aleatórios
    srand(time(nullptr));

    // Gerar e exibir uma lista duplamente encadeada aleatória
    Node* largeRandomList = generateRandomList(1000);
}

Node* createNode(int iPayload) 
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->iPayload = iPayload;
    temp->ptrNext = nullptr;
    temp->ptrPrev = nullptr;
    return temp;
}

Node* generateRandomList(int size)
{
    Node* head = nullptr;
    for (int i = 0; i < size; ++i) {
        insertEnd(&head, rand() % 100 + 1); // Inserir números aleatórios entre 1 e 100
    }
    return head;
}

void insertFront(Node** head, int iPayload){
    Node* newNode = createNode(iPayload);
    if (*head != nullptr) {
        newNode->ptrPrev = nullptr;
        (*head)->ptrPrev = newNode;
        newNode->ptrNext = (*head);
        (*head) = newNode;
        return;
    }
    (*head) = newNode;
}

void insertEnd(Node** head, int iPayload) {
    Node* newNode = createNode(iPayload);
    if (*head == nullptr) {
        newNode->ptrPrev = nullptr;
        (*head) = newNode;
        return;
    }
    Node* temp = (*head);
    while (temp->ptrNext != nullptr) temp = temp->ptrNext;
    newNode->ptrPrev = temp;
    temp->ptrNext = newNode;
}

