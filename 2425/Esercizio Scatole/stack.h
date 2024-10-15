struct StackNode {
    int data;
    StackNode* next;
};

struct Stack {
    StackNode* top;
};

void initStack(Stack &s) {
    s.top = nullptr;
}

void Push(Stack& s, int element) {
    StackNode* newNode = new StackNode;
    newNode->data = element;
    newNode->next = s.top;
    s.top = newNode;
}

int Top(Stack& s) {
    if (s.top != nullptr) {
        return s.top->data;
    }
    return -1; //pila vuota
}

void Pop(Stack& s) {
    if (s.top != nullptr) {
        StackNode* temp = s.top;
        s.top = s.top->next;
        delete temp;
    }
}

bool EmptyStack(Stack& s) {
    return s.top == nullptr;
}
