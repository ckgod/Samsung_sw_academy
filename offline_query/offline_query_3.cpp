#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
vector<int> graph[200001];
int check[200001];
int parent[200001];
vector<int> qList;
vector<int> ansList;

int find(int n) {
    if(parent[n] == n) return n;
    else return parent[n] = find(parent[n]);
}

void merge(int n1, int n2){
    n1 = find(n1);
    n2 = find(n2);
    if(n1 != n2) {
        parent[n2] = n1;
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) parent[i] = i;
    for(int i = 0; i < m; i++) {
        int a,b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i = 0; i < n; i++) {
        int t; cin >> t;
        qList.push_back(t);
    }
    int group = 0;
    for(int i = qList.size()-1; i>=0; i--) {
        group++;
        for(auto j : graph[qList[i]]) {
            if(check[j]) {
                if(find(j) != find(qList[i])) {
                    merge(j, qList[i]);
                    group--;
                }
            }
        }
        check[qList[i]] = true;
        if(group == 1) ansList.push_back(true);
        else ansList.push_back(false);
    }
    for(int i = ansList.size()-1; i >=0; i--) {
        if(ansList[i]) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}