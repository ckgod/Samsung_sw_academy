#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> graph[100001];
int n, m;
int order[100001];
vector<pair<int,int>> ansList;
int cnt = 1;

int dfs(int cur, int _prev) {
    order[cur] = cnt++;
    int ret = order[cur];

    for (int i = 0; i < graph[cur].size(); i++) {
        int next = graph[cur][i];
        if (next == _prev) continue;

        if (order[next]) {
            ret = min(ret, order[next]);
            continue;
        }

        int prev = dfs(next, cur);
        // 아직 방문안한 노드의 순서가 현재 순서보다 클경우 단절선
        if (prev > order[cur]) {
            ansList.push_back({ min(cur,next), max(cur,next) });
        }

        ret = min(ret, prev);
    }
    return ret;
}


int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (!order[i]) dfs(i, 0);
    }

    sort(ansList.begin(), ansList.end());
    cout << ansList.size() << "\n";
    for (auto i : ansList) cout << i.first << " " << i.second << "\n";

    return 0;
}