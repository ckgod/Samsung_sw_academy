#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n,m,s,e,ans;
vector<pair<int,int>> graph[10001];
vector<pair<int,int>> revGraph[10001];
int ind[10001], dist[10001];
bool visit[10001];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0 ; i < m; i++) {
        int a,b,c; cin >> a >> b >> c;
        graph[a].push_back({b,c});
        revGraph[b].push_back({a,c});
        ind[b]++;
    }
    cin >> s >> e;
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(auto next : graph[cur]) {
            int nextV = next.first;
            int nextCost = next.second + dist[cur];
            if(dist[nextV] < nextCost) {
                dist[nextV] = nextCost;
            }
            if(!--ind[nextV]) q.push(nextV);
        }
    }
    q.push(e);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        if(visit[cur]) continue;
        visit[cur] = true;
        for(auto prev : revGraph[cur]) {
            int prevV = prev.first;
            int prevCost = prev.second;
            if(dist[cur] == dist[prevV] + prevCost) {
                ans++;
//                cout << "추가된 도로 : " << prevV << " -> " << cur << "\n";
                q.push(prevV);
            }
        }
    }
    cout << dist[e] << "\n" << ans;

    return 0;
}