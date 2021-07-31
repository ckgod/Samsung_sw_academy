#define MAXN 1000000

struct Node {
    int val;
    Node *prev;
    Node *next;
} node[MAXN];

struct Graph{
    Node *head;
    Node *tail;
} graph[100];

int nodeCnt;
int ans = -1;
bool visit[100];

Node *getNode(int data) {
    node[nodeCnt].val = data;
    node[nodeCnt].next = nullptr;
    node[nodeCnt].prev = nullptr;
    return &node[nodeCnt++];
}

void addTail(int num, int data) {
    Node *newNode = getNode(data);
    newNode->prev = graph[num].tail->prev;
    graph[num].tail->prev->next = newNode;
    newNode->next = graph[num].tail;
    graph[num].tail->prev = newNode;
}

void visit_init() {
    ans = -1;
    for(int i = 1; i < 100; i++) {
        visit[i] = false;
    }
}

void dfs_init(int N, int path[100][2]) {
    ans = -1;
    nodeCnt = 0;
    for(int i = 1; i < 100; i++) {
        visit[i] = false;
        graph[i].head = getNode(-1);
        graph[i].tail = getNode(-1);
        graph[i].head->next = graph[i].tail;
        graph[i].tail->prev = graph[i].head;
    }
    for(int i = 0; i < N-1; i++) {
        int p = path[i][0];
        int c = path[i][1];
        addTail(p,c);
    }
}

void fun_dfs(int k, int cur) {
    if(visit[cur]) return;
    visit[cur] = true;
    Node *ptr = graph[cur].head;
    while(ptr != graph[cur].tail->prev) {
        if(ptr->next->val > k) {
            if(ans == -1) {
                ans = ptr->next->val;
            }
            return;
        }
        fun_dfs(k,ptr->next->val);
        ptr = ptr->next;
    }
}

int dfs(int n) {
    visit_init();
    fun_dfs(n,n);
    return ans;
}
