#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> graph[30001];
int n, m;
int order[30001];
vector<int> ansList;
int cnt = 1;
bool isFind = false;

void init(int sz) {
    ansList.clear();
    for (int i = 1; i <= sz; i++) {
        graph[i].clear();
        order[i] = 0;
    }
    cnt = 1;
    isFind = false;
}

int dfs(int cur, bool root) {
    order[cur] = cnt++;
    int ret = order[cur];
    int child = 0;
    for (int i = 0; i < graph[cur].size(); i++) {
        int next = graph[cur][i];
        if (order[next]) {
            ret = min(ret, order[next]);
            continue;
        }
        child++;
        int prev = dfs(next, false);
        if (!root && prev >= order[cur]) {
            isFind = true;
        }
        ret = min(ret, prev);
    }
    if (root && child > 1) {
        isFind = true;
    }
    return ret;
}


int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    while (tc--) {
        cin >> n >> m;
        init(n);
        for (int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for (int i = 1; i <= n; i++) {
            if (!order[i]) {
                dfs(i, true);
            }
        }
        if (isFind) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}