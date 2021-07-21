#include<iostream>
using namespace std;
#define MAX_N 10000

struct Node {
    int data;
    Node *next;
    Node *prev;
} node[MAX_N];

int nodeCnt = 0;
int n, q;
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

void list_push_back(int data) {
    Node* newNode = getNode(data);
    newNode->prev = tail->prev;
    tail->prev->next = newNode;
    newNode->next = tail;
    tail->prev = newNode;
}

void funI(int x, int y, int s[MAX_N]) {
    Node* ptr = head;
    for(int i = 0; i < x; i++) {
        ptr = ptr->next;
    }
    for(int i = 0; i < y; i++) {
        Node* newNode = getNode(s[i]);
        newNode->next = ptr->next;
        ptr->next->prev = newNode;
        ptr->next = newNode;
        newNode->prev = ptr;
        ptr = ptr->next;
    }
}

void funD(int x, int y) {
    Node *ptr = head;
    for(int i = 0; i < x; i++) ptr = ptr->next;
    for(int i = 0; i < y; i++) {
        ptr->next->next->prev = ptr;
        ptr->next = ptr->next->next;
    }
}

void funA(int y, int s[MAX_N]) {
    for(int i = 0; i < y; i++) {
        list_push_back(s[i]);
    }
}

void print() {
    Node* ptr = head;
    while(ptr != tail->prev) {
        cout << ptr->next->data << " ";
        ptr = ptr->next;
    }
    cout << "\n";
}

int main() {
    for(int tc = 1; tc <= 10; tc++) {
        init();
        cin >> n;
        for(int i = 0; i < n; i++) {
            int t; cin >> t;
            list_push_back(t);
        }

        cin >> q;
        for(int i = 0; i < q; i++) {
            char cmd; cin >> cmd;
            int x,y; int s[MAX_N];
            switch(cmd) {
                case 'I':
                    cin >> x >> y;
                    for(int s_idx = 0; s_idx < y; s_idx++) cin >> s[s_idx];
                    funI(x,y,s);
//                    print();
                    break;
                case 'D':
                    cin >> x >> y;
                    funD(x,y);
//                    print();
                    break;
                case 'A':
                    cin >> y;
                    for(int s_idx = 0; s_idx < y; s_idx++) cin >> s[s_idx];
                    funA(y,s);
//                    print();
                    break;
                default:
                    break;
            }
        }

        cout << "#" << tc << " ";
        Node *ptr = head;
        for(int i = 0; i < 10; i++) {
            cout << ptr->next->data << " ";
            ptr = ptr->next;
        }
        cout << "\n";
    }
    return 0;
}