#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

vector<int> tree[10001];
bool visit[10001];
int dep[10001];
int dp[10001][21];

void init() {
    memset(visit, 0, sizeof(visit));
    memset(dp,0,sizeof(dp));
    memset(dep, 0 , sizeof(dep));
    for(int i = 0; i < 10001; i++) {
        tree[i].clear();
    }
}

void dfs(int cur, int d) {
    visit[cur] = true;
    dep[cur] = d;
    for (int i = 0; i < tree[cur].size(); i++) {
        int next = tree[cur][i];
        if (visit[next]) continue;
        dp[next][0] = cur;
        dfs(next, d + 1);
    }
}

void func(int n) {
    for (int i = 1; i < 21; i++) {
        for (int j = 1; j <= n; j++) {
            dp[j][i] = dp[dp[j][i - 1]][i - 1];
        }
    }
}

int lca(int n1, int n2) {
    if (dep[n1] > dep[n2]) {
        swap(n1, n2);
    }
    for (int i = 20; i >= 0; i--) {
        if (dep[n2] - dep[n1] >= (1 << i)) {
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

int counting_tree(int root) {
    int ret = 1;
    for(auto i : tree[root]) {
        if(dep[i] <= dep[root]) continue;
        ret += counting_tree(i);
    }
    return ret;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    for(int tc = 1; tc <= T; tc++) {
        init();
        int v,e,a,b; cin >> v >> e >> a >> b;
        for(int i = 0; i < e; i++) {
            int p,c; cin >> p >> c;
            tree[p].push_back(c);
            tree[c].push_back(p);
        }
        dfs(1, 0);
        func(v);

        int lca_num = lca(a,b);
        int lca_cnt = counting_tree(lca_num);

        cout << "#" << tc << " " << lca_num << " " << lca_cnt << "\n";
    }

    return 0;
}