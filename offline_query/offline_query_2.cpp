#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
#define MAXN 300001
#define CYCLE -100

struct Query {
    int q,src,dest;
    int ans;
};

int n,m;
int graph[MAXN];
bool visit[MAXN];
vector<Query> qList;
int parent[MAXN];

int find(int n) {
    if(parent[n] == n) return n;
    else return parent[n] = find(parent[n]);
}


void merge(int dest, int src) {
    dest = find(dest);
    src = find(src);
    if(dest != src) {
        parent[src] = dest;
    }
}


int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <=n; i++) parent[i] = i;
    for (int i = 1; i <= n; i++) {
        int t; cin >> t;
        graph[i] = t;
    }
    cin >> m;
    for(int i = 0; i < m; i++) {
        int q, x; cin >> q >> x;
        if(q == 2) {
            qList.push_back({q,x,graph[x],-1});
            graph[x] = 0;
        }
        else {
            qList.push_back({q,x, -1,-1});
        }
    }
    for(int i =1; i <=n; i++) {
        if(graph[i] == 0) continue;
        if(find(graph[i]) == find(i)) {
            parent[i] = CYCLE;
        }
        else {
            merge(graph[i], i);
        }
    }
    for(int i = qList.size()-1; i >= 0; i--) {
        if(qList[i].q == 2) {
            if(find(qList[i].src) == find(qList[i].dest)) {
                parent[qList[i].src] = CYCLE;
            }
            else {
                merge(qList[i].dest, qList[i].src);
            }
        }
        else {
            int ret = find(qList[i].src);
            qList[i].ans = ret;
        }
    }
    for(int i = 0; i < qList.size(); i++) {
        if(qList[i].q == 1) {
            if(qList[i].ans == 0) {
                cout << "CIKLUS\n";
            }
            else {
                cout << qList[i].ans << "\n";
            }
        }
    }

    return 0;
}