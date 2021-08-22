#include <iostream>
using namespace std;
#define MAXN 100000

struct Node {
    Node *prev;
    Node *next;
    int val;
    Node *alloc(Node *_p = 0, Node *_n = 0, int _v = 0) {
        prev = _p;
        next = _n;
        val = _v;
        return this;
    }
};

int _node_cnt = 0;
Node _node[MAXN];
struct List {
    Node * head;
    Node * tail;
    int n;

    void clear() {
        head = _node[_node_cnt++].alloc();
        tail = _node[_node_cnt++].alloc(head);
        head->next = tail;
        n = 0;
    }
    Node * insert(Node * pos, int x) {
        n++;
        return pos->prev = pos->prev->next = _node[_node_cnt++].alloc(pos->prev, pos, x);
    }
    Node * erase(Node * pos) {
        pos->prev->next = pos->next;
        pos->next->prev = pos->prev;
        n--;
        return pos->prev;
    }

    int size() { return n; }
    Node * begin() { return head->next; }
    Node * end() { return tail; }

    void push_back(int x) { insert(tail, x); }
    void pop_back() { erase(tail->prev); }
    void push_front(int x) { insert(head->next, x); }
    void pop_front() { erase(head->next); }
};


int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    List li;
    li.clear();

    while(1) {
        int t; cin >> t;
        if(t == 0) break;
        li.push_back(t);
        li.push_front(t);
    }

    for(Node * it  = li.begin(); li.end() != it; it = it->next) {
        cout << it->val << " ";
    }



    return 0;
}