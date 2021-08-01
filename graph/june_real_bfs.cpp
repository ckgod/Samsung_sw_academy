#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
#define ll long long

int n;
ll ans;
vector<int> tree[100001];
bool dfs_visit[100001];
bool visit[100001];

int depth[100001];
int dp[100001][21];
queue<int> q;

void init() {
    memset(dfs_visit,false,sizeof(dfs_visit));
    memset(visit,false,sizeof(visit));
    memset(dp,false,sizeof(dp));
    ans = 0;
    for(int i = 0; i < 100001; i++) {
        tree[i].clear();
    }
}

void initDP() {
    queue<pair<int,int>> dpq;
    dpq.push({1,0});
    dfs_visit[1] = true;
    while(!dpq.empty()) {
        int cur = dpq.front().first;
        int dep = dpq.front().second;
        dpq.pop();
        depth[cur] = dep;
        for(int i = 0; i < tree[cur].size(); i++) {
            int next = tree[cur][i];
            if(dfs_visit[next]) continue;
            dfs_visit[next] = true;
            dp[next][0] = cur;
            dpq.push({next,dep+1});
        }
    }
    for (int i = 1; i < 21; i++) {
        for (int j = 1; j <= n; j++) {
            dp[j][i] = dp[dp[j][i - 1]][i - 1];
        }
    }
}

int lca(int n1, int n2) {
    if (depth[n1] > depth[n2]) {
        swap(n1, n2);
    }
    for (int i = 20; i >= 0; i--) {
        if (depth[n2] - depth[n1] >= (1 << i)) {
            n2 = dp[n2][i];
        }
    }
    if (n1 == n2) return n1;
    for (int i = 20; i >= 0; i--) {
        if (dp[n1][i] != dp[n2][i]) {
            n1 = dp[n1][i];
            n2 = dp[n2][i];
        }
    }
    return dp[n1][0];
}

int getDist(int a, int b) {
    int commonP = lca(a, b);
    int aDC = depth[a] - depth[commonP];
    int bDC = depth[b] - depth[commonP];
    return aDC + bDC;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    for(int tc = 1; tc <= T; tc++) {
        init();
        cin >> n;
        for(int i = 2; i < n+1; i++) {
            int t; cin >> t;
            tree[i].push_back(t);
            tree[t].push_back(i);
        }
        for(int i = 1; i <= n; i++) {
            sort(tree[i].begin(), tree[i].end());
        }
        initDP();
        q.push(1);
        visit[1] = true;
        int realPos = 1;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            for(int i = 0; i < tree[cur].size(); i++) {
                int next = tree[cur][i];
                if(visit[next]) continue;
                visit[next] = true;
                if(next != 1) {
                    ans += getDist(realPos, next);
                }
                realPos = next;
                q.push(next);
            }
        }
        cout << "#" << tc << " " << ans << "\n";
    }


    return 0;
}