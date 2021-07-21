#define MAX_NODE 10000

struct Node {
    int data;
    Node *prev;
    Node *next;
};

Node node[MAX_NODE];
int nodeCnt;
Node *head, *tail;

Node *getNode(int data) {
    node[nodeCnt].data = data;
    node[nodeCnt].prev = nullptr;
    node[nodeCnt].next = nullptr;
    return &node[nodeCnt++];
}

void init() {
    nodeCnt = 0;
    head = getNode(-1);
    tail = getNode(-1);
    head->next = tail;
    tail->prev = head;
}

void addNode2Head(int data) {
    Node* newNode = getNode(data);
    newNode->next = head->next;
    head->next->prev = newNode;
    head->next = newNode;
    newNode->prev = head;
}

void addNode2Tail(int data) {
    Node* newNode = getNode(data);
    newNode->prev = tail->prev;
    tail->prev->next = newNode;
    newNode->next = tail;
    tail->prev = newNode;
}

void addNode2Num(int data, int num) {
    Node* ptr = head;
    Node* newNode = getNode(data);
    for(int i = 0; i < num-1; i++) {
        ptr = ptr->next;
    }
    newNode->next = ptr->next;
    ptr->next->prev = newNode;
    ptr->next = newNode;
    newNode->prev = ptr;
}

int findNode(int data) {
    Node* ptr = head;
    int ret = 1;
    while(ptr != tail) {
        if(ptr->next->data == data || ptr->next->data == -1) break;
        ptr = ptr->next;
        ret++;
    }
    return ret;
}

void removeNode(int data) {
    Node* ptr = head;
    while(ptr != tail->prev) {
        if(ptr->next->data == data) break;
        ptr = ptr->next;
    }
    if(ptr->next == tail) return;
    ptr->next->next->prev = ptr;
    ptr->next = ptr->next->next;
}

int getList(int output[MAX_NODE]) {
    Node* ptr = head;
    int idx = 0;
    while(ptr != tail->prev) {
        output[idx++] = ptr->next->data;
        ptr = ptr->next;
    }
    return idx;
}

int getReversedList(int output[MAX_NODE]) {
    Node* ptr = tail;
    int idx = 0;
    while(ptr != head->next) {
        output[idx++] = ptr->prev->data;
        ptr = ptr->prev;
    }
    return idx;
}