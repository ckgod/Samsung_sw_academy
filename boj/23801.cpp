#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
#define MAX_N 100001
#define ll long long
#define INF 1900000000000

int n, m, x, z, p;
bool visit[MAX_N];
vector<pair<int,ll>> graph[MAX_N];
vector<int> wayPoint;
ll dist[MAX_N], dist_rev[MAX_N];
priority_queue<pair<ll,int>> pq;
ll ans;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        dist[i] = INF; dist_rev[i] = INF;
    }
    for(int i = 0; i < m; i++) {
        int a,b,c; cin >> a >> b >> c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    cin >> x >> z >> p;
    for(int i = 0; i < p; i++) {
        int t; cin >> t;
        wayPoint.push_back(t);
    }

    pq.push({0,x});
    dist[x] = 0;

    while(!pq.empty()) {
        int cur = pq.top().second;
        ll curCost = -pq.top().first;
        pq.pop();
        if(visit[cur]) continue;
        dist[cur] = curCost;
        visit[cur] = true;

        for(int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i].first;
            ll nextCost = curCost + graph[cur][i].second;
            if(dist[next] <= nextCost) continue;
            dist[next] = nextCost;
            pq.push({-nextCost, next});
        }
    }
    memset(visit,false, sizeof(visit));
    pq.push({0,z});
    dist_rev[z] = 0;

    while(!pq.empty()) {
        int cur = pq.top().second;
        ll curCost = -pq.top().first;
        pq.pop();
        if(visit[cur]) continue;
        dist_rev[cur] = curCost;
        visit[cur] = true;

        for(int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i].first;
            ll nextCost = curCost + graph[cur][i].second;
            if(dist_rev[next] <= nextCost) continue;
            dist_rev[next] = nextCost;
            pq.push({-nextCost, next});
        }
    }

    ans = 3800000000000;
    for(auto i : wayPoint) {
        ans = min(ans, (dist[i] + dist_rev[i]));
    }
    if(ans > INF) cout << -1;
    else cout << ans;

    return 0;
}