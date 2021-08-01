#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

struct Land{
    ll x,y;
};

struct Edge{
    ll w;
    ll s,e;
};

bool compare(Edge e1, Edge e2) {
    return e1.w < e2.w;
}

int parent[1001];
ll A[1001], B[1001];
int n;
Land land[1001];
double E;
vector<Edge> eList;
ll ans;

void init() {
    ans = 0;
    eList.clear();
    for(int i = 1; i <= 1000; i++) {
        parent[i] = i;
    }
}

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

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    for(int tc = 1; tc <= T; tc++) {
        init();
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> A[i];
        }
        for(int i = 1; i <= n; i++) {
            cin >> B[i];
            land[i].x = A[i]; land[i].y = B[i];
        }
        cin >> E;
        for(int i = 1; i <= n; i++) {
            for(int j = i+1; j <= n; j++) {
                ll L = ((land[i].x - land[j].x) * (land[i].x - land[j].x)) + ((land[i].y - land[j].y) * (land[i].y - land[j].y));
                eList.push_back({L,i,j});
            }
        }
        sort(eList.begin(), eList.end(), compare);
        for(auto road : eList) {
            if(find(road.s) != find(road.e)) {
                merge(road.s, road.e);
                ans += road.w;
            }
        }
        cout << "#" << tc << " " << llround(ans*E) << "\n";
    }

    return 0;
}