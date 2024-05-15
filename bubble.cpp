#define bubble

struct Node 
{
    int iPayload;
    Node* ptrNext;
};

//Prototipagem das funções de sorting com bubble
void bubblesort(Node* head);
void optimizedBubblesort(Node* head);

//Prototipagem das funções para doubly linked list
void trocaValor(Node*, Node*);
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