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
    Node* root = nullptr;

    // Parte 5: Monitorar o desempenho de criação de árvores
    auto start = high_resolution_clock::now();
    for (int i = 0; i < 1000000; ++i) {
        root = insertNode(root, rand() % 1000000);
    }
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();
    cout << "Tempo de criação da árvore: " << duration << " microssegundos" << endl;

    // Parte 3: Monitorar o desempenho de busca em árvore utilizando DFS e BFS
    start = high_resolution_clock::now();
    dfsTraversal(root);
    end = high_resolution_clock::now();
    auto durationDFS = duration_cast<microseconds>(end - start).count();
    cout << "Tempo de execução DFS: " << durationDFS << " microssegundos" << endl;

    start = high_resolution_clock::now();
    bfsTraversal(root);
    end = high_resolution_clock::now();
    auto durationBFS = duration_cast<microseconds>(end - start).count();
    cout << "Tempo de execução BFS: " << durationBFS << " microssegundos" << endl;

    // Parte 4: Monitorar o desempenho de criação de listas
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    start = high_resolution_clock::now();

    for (int i = 0; i < 1000000; ++i) {
        ListNode* newNode = new ListNode{i, nullptr};
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start).count();
    cout << "Tempo de criação da lista: " << duration << " microssegundos" << endl;

    // Limpeza da lista para evitar vazamento de memória
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
    
    cout << "Altura da árvore: " << treeHeight(root) << endl;
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
void dfsTraversal(Node* ptrStartingNode)
{
    if (ptrStartingNode != nullptr)
    {
        // Comentário removido: cout << ptrStartingNode->iPayload << " ";
        dfsTraversal(ptrStartingNode->ptrLeft);
        dfsTraversal(ptrStartingNode->ptrRight);
    }
}

int treeHeight(Node* startingNode)
{
    if (startingNode == nullptr) return 0;
    else
    {
        int iLeftHeight = treeHeight(startingNode->ptrLeft);
        int iRightHeight = treeHeight(startingNode->ptrRight);

        return max(iLeftHeight, iRightHeight) + 1;
    }
}