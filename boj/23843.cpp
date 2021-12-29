#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n,m,ans;
priority_queue<int, vector<int>, greater<int>> pq;
vector<int> v;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int t; cin >> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end(), greater<int>());
    int idx = 0;
    for(int i = 0; i < m; i++) {
        pq.push(v[idx++]);
        if(idx == n) break;
    }
    for(int i = idx; i < n; i++) {
        int t = pq.top() + v[i];
        pq.pop();
        pq.push(t);
    }
    while(!pq.empty()) {
        ans = max(pq.top(), ans);
        pq.pop();
    }
    cout << ans;
    return 0;
}