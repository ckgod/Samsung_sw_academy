#include <iostream>
using namespace std;
#define MAX_POOL 10000
#define MAX_NODE 10000

struct ListNode{
    int id;
    ListNode *prev;
} listPool[MAX_POOL];

struct TreeNode {
    int parent;
    ListNode *child;
} treeNode[MAX_NODE];

int memPoolCnt = 0;

void init() {
    memPoolCnt = 0;
    for(register int i = 0; i < MAX_NODE; i++) {
        treeNode[i].parent = -1;
        treeNode[i].child = nullptr;
    }
}

void addParentAtChild(int pa, int ci) {
    treeNode[ci].parent = pa;
    ListNode *list = &listPool[memPoolCnt++];
    list->id = ci;
    list->prev = treeNode[pa].child;
    treeNode[pa].child = list;
}

int findRoot(int n) {
    while(treeNode[n].parent != -1)
        n = treeNode[n].parent;
    return n;
}

void traverse(int cur) {
    cout << cur << " ";
    for(ListNode* l = treeNode[cur].child; l != nullptr; l = l->prev) {
        traverse(l->id);
    }
}


int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    return 0;
}