#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int n,m;
vector<pair<int,int>> graph[1001];
int path[1001], dist[1001], ind[1001];
vector<int> ans;

void find(int cur) {
    ans.push_back(cur);
    if(path[cur] != 1) {
        find(path[cur]);
    }
    else {
        ans.push_back(1);
        return;
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a,b,c; cin >> a >> b >> c;
        graph[a].push_back({b,c});
        ind[b]++;
    }

    priority_queue<pair<int,int>> q;
    q.push({0,1});
    while(!q.empty()) {
        int cur = q.top().second;
        int curCost = q.top().first;
        q.pop();
        for(auto next : graph[cur]) {
            int nextCost = next.second + curCost;
            int nextV = next.first;
            ind[nextV]--;
            if(dist[nextV] < nextCost) {
                dist[nextV] = nextCost;
                path[nextV] = cur;
            }
            if(nextV != 1 && !ind[nextV]) q.push({dist[nextV], nextV});
        }
    }
    find(1);
    cout << dist[1] << "\n";
    for(int i = ans.size()-1; i >= 0; i--) {
        cout << ans[i] << " ";
    }

    return 0;
}