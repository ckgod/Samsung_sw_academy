#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
bool visit[30001];
int dp[30001][21];
int dep[30001];
vector<int> tree[30001];
int ans;

void dfs(int cur, int d) {
    visit[cur] = true;
    dep[cur] = d;
    for(int i = 0; i < tree[cur].size(); i++) {
        int next = tree[cur][i];
        if(visit[next]) continue;
        dp[next][0] = cur;
        dfs(next, d+1);
    }
}

void setDp() {
    for(int i = 1; i < 21; i++) {
        for(int j = 1; j <=n; j++) {
            dp[j][i] = dp[dp[j][i-1]][i-1];
        }
    }
}

int lca(int n1, int n2) {
    if(dep[n1] > dep[n2]) {
        swap(n1,n2);
    }
    for(int i = 20; i >=0; i--) {
        if(dep[n2] - dep[n1] >= (1 << i)) {
            n2 = dp[n2][i];
        }
    }
    if(n1 == n2) return n1;
    for(int i = 20; i >= 0; i--) {
        if(dp[n1][i] != dp[n2][i]) {
            n1 = dp[n1][i];
            n2 = dp[n2][i];
        }
    }
    return dp[n1][0];
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n-1; i++) {
        int a,b; cin >> a >> b;
        tree[a].emplace_back(b);
        tree[b].emplace_back(a);
    }
    dfs(1, 0);
    setDp();
    cin >> m;
    int curP = 1;
    while(m--) {
        int dest; cin >> dest;
        int cp = lca(curP, dest);
        int dis = (dep[curP] + dep[dest]) - dep[cp]*2;
        curP = dest;
        ans += dis;
    }
    cout << ans;
    return 0;
}