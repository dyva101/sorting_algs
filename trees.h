#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

typedef struct Node
{
    int iPayload;
    Node* ptrLeft;
    Node* ptrRight;
} Node;

typedef struct ListNode
{
    int data;
    ListNode* next;
} ListNode;

typedef struct QueueNode
{
    Node* treeNode;
    QueueNode* next;
} QueueNode;

class Queue
{
private:
    QueueNode* front;
    QueueNode* rear;
public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(Node* newNode)
    {
        QueueNode* newQueueNode = new QueueNode{newNode, nullptr};
        if (rear == nullptr) {
            front = rear = newQueueNode;
        } else {
            rear->next = newQueueNode;
            rear = newQueueNode;
        }
    }

    Node* dequeue()
    {
        if (front == nullptr) return nullptr;
        QueueNode* temp = front;
        Node* treeNode = front->treeNode;
        front = front->next;
        if (front == nullptr) rear = nullptr;
        delete temp;
        return treeNode;
    }

    bool isEmpty()
    {
        return front == nullptr;
    }
};

Node* createNode(int);
Node* insertNode(Node*, int);
void bfsTraversal(Node*);
void dfsTraversal(Node*);
int treeHeight(Node*);

int main(){

    return 0;
}
Node* createNode(int iValue)
{
    Node* tmp = (Node*) malloc(sizeof(Node));

    if (tmp == nullptr)
    {
        cerr << "Erro em createNode: malloc" << endl;
        exit(1);
    }

    tmp->iPayload = iValue;
    tmp->ptrLeft = nullptr;
    tmp->ptrRight = nullptr;

    return tmp;
}

Node* insertNode(Node* startingNode, int iData)
{
    if(startingNode == nullptr)
    {
        return createNode(iData);
    }

    if(iData < startingNode->iPayload)
    {
        startingNode->ptrLeft = insertNode(startingNode->ptrLeft, iData);
    }
    else
    {
        startingNode->ptrRight = insertNode(startingNode->ptrRight, iData);
    }

    return startingNode;
}
void bfsTraversal(Node* startingNode)
{
    if (startingNode == nullptr) return;

    Queue queue;
    queue.enqueue(startingNode);

    while (!queue.isEmpty())
    {
        Node* currentNode = queue.dequeue();
        // Comentário removido: cout << currentNode->iPayload << " ";

        if (currentNode->ptrLeft != nullptr)
        {
            queue.enqueue(currentNode->ptrLeft);
        }

        if (currentNode->ptrRight != nullptr)
        {
            queue.enqueue(currentNode->ptrRight);
        }
    }
}
