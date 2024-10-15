struct Node {
    int data;
    Node* next;
};

struct Queue {
    Node* front;
    Node* rear;
};

void initQueue(Queue &q) {
    q.front = q.rear = nullptr;
}

void InQueue(Queue& q, int element) {
    Node* newNode = new Node;
    newNode->data = element;
    newNode->next = nullptr;
    if (q.rear == nullptr) {
        q.front = q.rear = newNode;
    } else {
        q.rear->next = newNode;
        q.rear = newNode;
    }
}

int Front(Queue& q) {
    if (q.front != nullptr) {
        return q.front->data;
    }
    return -1; //coda vuota
}

void DeQueue(Queue& q) {
    if (q.front != nullptr) {
        Node* temp = q.front;
        q.front = q.front->next;
        if (q.front == nullptr) {
            q.rear = nullptr;
        }
        delete temp;
    }
}

bool EmptyQueue(Queue& q) {
    return q.front == nullptr;
}
