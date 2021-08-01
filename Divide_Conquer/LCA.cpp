#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<pair<int, int>> tree[100001];
bool visit[100001];
int depth[100001];
int dp[100001][21];
int dist[100001][21];
queue<int> q;

void dfs(int cur, int dept) {
    visit[cur] = true;
    depth[cur] = dept;
    for (int i = 0; i < tree[cur].size(); i++) {
        int next = tree[cur][i].first;
        int dis = tree[cur][i].second;
        if (visit[next]) continue;
        dp[next][0] = cur;
        dist[next][0] = dis;
        dfs(next, dept + 1);
    }
}

void initDP() {
    for (int i = 1; i < 21; i++) {
        for (int j = 1; j <= n; j++) {
            dp[j][i] = dp[dp[j][i - 1]][i - 1];
            dist[j][i] = dist[j][i - 1] + dist[dp[j][i - 1]][i - 1];
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
    int a, b;
    cin >> a >> b;
    int commonP = lca(a, b);
    int aDC = depth[a] - depth[commonP];
    int bDC = depth[b] - depth[commonP];
    int disA = 0;
    int disB = 0;
    for (int i = 20; i >= 0; i--) {
        if (aDC >= (1 << i)) {
            disA += dist[a][i];
            a = dp[a][i];
            aDC -= (1 << i);
        }
        if (bDC >= (1 << i)) {
            disB += dist[b][i];
            b = dp[b][i];
            bDC -= (1 << i);
        }
    }
    return disA + disB;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    for(int tc = 1; tc <= T; tc++) {
        cin >> n;
        for(int i = 2; i < n+2; i++) {
            int t; cin >> t;
            tree[i].push_back({t,1});
            tree[t].push_back({i,1});
        }
        dfs(1,0);
        initDP();
        q.push(1);
        visit[1] = true;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            for

        }


    }


    return 0;
}