#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Query{
    int Q,x,y;
};

int n,q;
int parent[200001];
int tree[200001];
vector<bool> ansList;
vector<Query> qList;

int find(int n) {
    if(parent[n] == n) return n;
    else return parent[n] = find(parent[n]);
}

void merge(int n1, int n2) {
    n1 = find(n1);
    n2 = find(n2);
    if(n1 != n2) {
        parent[n2] = n1;
    }
}

void init() {
    for(int i = 0; i < 200001; i++) {
        parent[i] = i;
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    init();
    cin >> n >> q;
    for(int i = 2; i <= n; i++) {
        int t; cin >> t;
        tree[i] = t;
    }
    for(int i = 0; i < n-1+q; i++) {
        int Q; cin >> Q;
        if(Q == 1) { // 경로 존재여부
            int x,y; cin >> x >> y;
            qList.push_back({1,x,y});
        }
        else if(Q == 0) { // 끊을때
            int x; cin >> x;
            qList.push_back({0,x,0});
        }
    }
    for(int i = qList.size()-1; i >= 0; i--) {
        if(qList[i].Q == 1) { // 여부
            if(find(qList[i].x) == find(qList[i].y)) {
                ansList.push_back(true);
            }
            else ansList.push_back(false);
        }
        else if(qList[i].Q == 0) { // 역순이니까 다시 잇는다
            merge(qList[i].x, tree[qList[i].x]);
        }
    }
    for(int i = ansList.size()-1; i >= 0; i--) {
        if(ansList[i]) cout << "YES\n";
        else cout << "NO\n";
    }



    return 0;
}