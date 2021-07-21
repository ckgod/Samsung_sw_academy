#define MAX_NODE 10000

struct Node {
    int data;
    Node *next;
} node[MAX_NODE];

int nodeCnt;
Node* head;

Node *getNode(int data) {
    node[nodeCnt].data = data;
    node[nodeCnt].next = nullptr;
    return &node[nodeCnt++];
}

void init() {
    nodeCnt = 0;
    head = getNode(-1);
}

void addNode2Head(int data) {
    Node* newNode = getNode(data);
    newNode->next = head->next;

    head->next = newNode;
}

void addNode2Tail(int data) {
    Node* ptr = head;
    Node* newNode = getNode(data);
    while(ptr->next) {
        ptr = ptr->next;
    }
    ptr->next = newNode;
}

void addNode2Num(int data, int num) {
    Node* ptr = head;
    for(int i = 0; i < num - 1; i++) {
        ptr = ptr->next;
    }
    Node* newNode = getNode(data);
    newNode->next = ptr->next;
    ptr->next = newNode;
}

void removeNode(int data) {
    Node* ptr = head;
    while(ptr->next) {
        if(ptr->next->data == data) break;
        ptr = ptr->next;
    }
    if(ptr->next == nullptr) return;
    ptr->next = ptr->next->next;
}

int getList(int output[MAX_NODE]) {
    Node* ptr = head;
    int idx = 0;
    while(ptr->next) {
        output[idx++] = ptr->next->data;
        ptr = ptr->next;
    }
    return idx;
}