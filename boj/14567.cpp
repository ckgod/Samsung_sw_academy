#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<int> graph[1001];
int ind[1001];
int order[1001];
queue<int> q;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a,b; cin >> a >> b;
        graph[a].push_back(b);
        ind[b]++;
    }
    for(int i = 1; i <= n; i++) {
        if(!ind[i]) {
            q.push(i);
            order[i] = 1;
        }
    }
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(auto next : graph[cur]) {
            ind[next]--;
            if(!ind[next]) {
                q.push(next);
                order[next] = order[cur]+1;
            }
        }
    }
    for(int i = 1; i <= n; i++) cout << order[i] << " ";

    return 0;
}