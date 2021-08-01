#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long

struct Edge{
    ll s,e,c;
    bool operator<(const Edge e1) const {
        return e1.c > this->c;
    }
};

int n,m;
int parent[50001];
int groupSize[50001];
ll s,e,c;
vector<Edge> eList;
ll ans;

int find(int n) {
    if(parent[n] == n) return n;
    else return parent[n] = find(parent[n]);
}

void merge(int n1, int n2) {
    n1 = find(n1);
    n2 = find(n2);

    if(n1 != n2) {
        if(groupSize[n2] > groupSize[n1]) swap(n1,n2);
        parent[n2] = n1;
        groupSize[n1] += groupSize[n2];
        groupSize[n2] = 1;
    }
}

void init() {
    eList.clear();
    ans = 0;
    for(int i = 1; i <= 50000; i++) {
        parent[i] = i;
        groupSize[i] = 1;
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    for(int tc = 1; tc <= T; tc++) {
        cin >> n >> m;
        init();
        for(int i = 0; i < m; i++) {
             cin >> s >> e >> c;
             eList.push_back({s,e,c});
        }
        sort(eList.begin(),eList.end());
        for(auto road : eList) {
            if(find(road.s) != find(road.e)) {
                ans += road.c;
                merge(road.s, road.e);
            }
        }
        cout << "#" << tc << " " << ans << "\n";
    }

    return 0;
}