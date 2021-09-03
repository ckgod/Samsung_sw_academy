#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
#include <tuple>
using namespace std;
#define INF 1900000000

char board[103][103];
int dist[103][103];
int dist1[103][103];
int dist2[103][103];
bool visit[103][103];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int n,m;
vector<pair<int,int>> start;

void init() {
    start.clear();
    memset(board,false,sizeof(board));
    memset(dist,false,sizeof(dist));
    memset(dist1,false,sizeof(dist1));
    memset(dist2,false,sizeof(dist2));
    memset(visit,false,sizeof(visit));
}

void bfs(int sx, int sy, int type) {
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
    pq.push({0,sx,sy});
    visit[sx][sy] = true;
    while(!pq.empty()) {
        int curx = get<1>(pq.top());
        int cury = get<2>(pq.top());
        int curCost = get<0>(pq.top());
        if(type == 0) curCost = dist[curx][cury];
        else if(type == 1) curCost = dist1[curx][cury];
        else if(type == 2) curCost = dist2[curx][cury];
        pq.pop();
        for(int i = 0; i < 4; i++) {
            int nextX = curx + dx[i];
            int nextY = cury + dy[i];
            int nextCost = curCost;
            int value = 0;
            if(nextX < 0 || nextY < 0 || nextX > n + 1 || nextY > m + 1) continue;
            if(visit[nextX][nextY]) continue;
            if(board[nextX][nextY] == '*') continue;
            if(board[nextX][nextY] == '#') {
                value = 1;
                nextCost += 1;
            }
            if(type == 0) dist[nextX][nextY] = nextCost;
            else if(type == 1) dist1[nextX][nextY] = nextCost;
            else if(type == 2) dist2[nextX][nextY] = nextCost;
            pq.push({nextCost, nextX, nextY});
            visit[nextX][nextY] = true;
        }
    }
    if(type == 0 || type == 1) {
        memset(visit,false,sizeof(visit));
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        init();
        cin >> n >> m;
        start.emplace_back(0,0);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cin >> board[i][j];
                if(board[i][j] == '$') {
                    start.emplace_back(i,j);
                }
            }
        }
        for(int i = 0; i < 3; i++) {
            bfs(start[i].first, start[i].second, i);
        }

        for(int i = 0; i < n+2; i++) {
            for(int j = 0; j < m+2; j++) {
                dist[i][j] += dist1[i][j];
                dist[i][j] += dist2[i][j];
            }
        }

        int ans = INF;
        for(int i = 0; i < n+2; i++) {
            for(int j = 0; j < m+2; j++) {
                if(board[i][j] == '*') continue;
                if(!visit[i][j]) continue;
                if(board[i][j] == '#') ans = min(ans, dist[i][j] - 2);
                else ans = min(ans, dist[i][j]);
            }
        }
        cout << ans << "\n";
    }


    return 0;
}
