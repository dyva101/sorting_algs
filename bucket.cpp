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
void bubblesort(Node* head);
void optimizedBubblesort(Node* head);
void trocaValor(Node*, Node*);


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

void bucketSort(Node* head)
{
    Node** buckets;

    buckets = (Node**)malloc(sizeof(Node*)*10);

    for (i = 0; i < 10; i++)
    {
        buckets[i] = NULL;
    }

    for (int i=0; i < 100; i++)
    { //FILL THE BUCKETS :P
        Node* current;
        Node* element = head;

        int pos = (element->iPayload)/10;

        current = (Node*)malloc(sizeof(Node));
        current->iPayload = element->iPayload;
        buckets[pos] = current;
    }

    for (int i = 0; i < 10; i++)
    {
        optimizedBubblesort(buckets[i]);
    }

    for (int j = 0, i = 0; i < 10; ++i)
    {
        Node* node;
        node = buckets[i];

        while (node) 
        {
            Node* element = head;
            element->iPayload = node->iPayload;
            node = node->ptrNext;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        Node* node;
        node = buckets[i];
        while (node)
        {
            Node* temp;
            temp = node;
        }
    }
}

void bubblesort(Node* head) 
{
    if (head == nullptr || head->ptrNext == nullptr) 
    {
        return;
    }
    
    Node* lastNode = nullptr;
    Node* firstNode = head;
    while (firstNode->ptrNext != nullptr) 
    {
        Node* current = head;
        while (current->ptrNext != lastNode) 
        {
            if (current->iPayload > current->ptrNext->iPayload) 
            {
                trocaValor(current, current->ptrNext);
            }
            current = current->ptrNext;
        }
        firstNode = firstNode->ptrNext;
        lastNode = current;
    }
}

void optimizedBubblesort(Node* head) 
{
    if (head == nullptr || head->ptrNext == nullptr) 
    {
        return;
    }
    bool unordered = false;
    Node* lastNode = nullptr;
    do 
    {
        unordered = false;
        Node* current = head;
        while (current->ptrNext != lastNode) 
        {
            if (current->iPayload > current->ptrNext->iPayload) 
            {
                trocaValor(current, current->ptrNext);
                unordered = true;
            }
            current = current->ptrNext;
        }
        lastNode = current;
    } while (unordered);
}

void trocaValor(Node* node1, Node* node2) 
{
    int temp = node1->iPayload;
    node1->iPayload = node2->iPayload;
    node2->iPayload = temp;
}