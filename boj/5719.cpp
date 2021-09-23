#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;
#define MAX_N 501
#define INF 1900000000

int n,m,st,ed;
vector<tuple<int,int,bool>> graph[MAX_N];
vector<int> track[MAX_N];
bool chk[MAX_N][MAX_N];
int visit[MAX_N];
queue<int> q;
priority_queue<pair<int,int>> pq;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    while(1) {
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        cin >> st >> ed;
        for(int i = 0; i < m; i++) {
            int a,b,c; cin >> a >> b >> c;
            graph[a].push_back({b,c,false});
        }
        for(int i = 0; i < n; i++) visit[i] = INF;
        visit[st] = 0;
        pq.push({0, st});
        while(!pq.empty()) {
            int cur = pq.top().second;
            int cost = -pq.top().first;
            pq.pop();
            for(int i = 0; i < graph[cur].size(); i++) {
                int next = get<0>(graph[cur][i]);
                int nextCost = cost + get<1>(graph[cur][i]);
                if(visit[next] >= nextCost) {
                    if(visit[next] > nextCost) {
                        visit[next] = nextCost;
                        track[next].clear();
                        track[next].push_back(cur);
                        pq.push({-nextCost, next});
                    }
                    else {
                        track[next].push_back(cur);
                    }
                }
            }
        }

        q.push(ed);
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            for(auto prev : track[cur]) {
                if(!chk[prev][cur]) {
                    for(auto &edge : graph[prev]) {
                        if(get<0>(edge) == cur) {
                            q.push(prev);
                            chk[prev][cur] = true;
                            get<2>(edge) = true;
                            break;
                        }
                    }
                }
            }
        }
        for(int i = 0; i < n; i++) visit[i] = INF;
        visit[st] = 0;
        pq.push({0, st});
        while(!pq.empty()) {
            int cur = pq.top().second;
            int cost = -pq.top().first;
            pq.pop();
            for(int i = 0; i < graph[cur].size(); i++) {
                if(!get<2>(graph[cur][i])) {
                    int next = get<0>(graph[cur][i]);
                    int nextCost = cost + get<1>(graph[cur][i]);
                    if(visit[next] > nextCost) {
                        visit[next] = nextCost;
                        pq.push({-nextCost, next});
                    }
                }
            }
        }
        if(visit[ed] == INF) cout << -1 <<"\n";
        else cout << visit[ed] << "\n";

        for(int i = 0; i < n; i++) {
            track[i].clear();
            graph[i].clear();
        }
        memset(chk, false, sizeof(chk));
    }

    return 0;
}