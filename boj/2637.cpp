#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m;
int ind[101], reverseInd[101], cost[101];
vector<pair<int,int>> reverseGraph[101];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    cost[n] = 1;
    for(int i = 0; i < m; i++) {
        int a,b,c; cin >> a >> b >> c;
        // a를 만드는데 b가 c개 필요함
        reverseGraph[a].push_back({b,c});
        ind[a]++;
        reverseInd[b]++;
    }
    queue<int> q;
    q.push(n);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(auto next : reverseGraph[cur]) {
            int nextV = next.first;
            int cnt = next.second;
            cost[nextV] += cost[cur] * cnt;
            if(!--reverseInd[nextV]) {
                q.push(nextV);
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        if(!ind[i]) cout << i << " " << cost[i] << "\n";
    }

    return 0;
}