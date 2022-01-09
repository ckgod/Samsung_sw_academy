#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, s, e, ans;
int parent[100001];

int find(int n) {
    if(parent[n] == n) return n;
    else return parent[n] = find(parent[n]);
}

void merge(int n1, int n2) {
    n1 = find(n1);
    n2 = find(n2);
    if(n1 != n2) {
        parent[n2] = n1;
    }
}

vector<pair<int, pair<int,int>>> v;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> m >> s >> e;
    for(int i = 1; i <= n; i++) parent[i] = i;
    for(int i = 0; i < m; i++) {
        int a,b,c; cin >> a >> b >> c;
        v.push_back({c,{a,b}});
    }
    sort(v.begin(),v.end());
    for(int i = v.size()-1; i >= 0; i--) {
        int n1 = v[i].second.first;
        int n2 = v[i].second.second;
        int w = v[i].first;
        if(find(n1) != find(n2)) {
            merge(n1,n2);
        }
        if(find(s) == find(e)) {
            ans = w;
            break;
        }
    }
    cout << ans;

    return 0;
}