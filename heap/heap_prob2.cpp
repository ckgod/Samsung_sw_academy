#include <iostream>
#include <queue>
using namespace std;
#define INF 1900000000

struct Pos{
    int x,y,w;
    bool operator<(const Pos p1) const {
        return p1.w < this->w;
    }
};

int n;
priority_queue<Pos> pq;
char board[101][101];
int dist[101][101];
int mx[] = {0,0,1,-1};
int my[] = {1,-1,0,0};

void init() {
    for(int i = 0; i < 101;i++) {
        for(int j = 0; j < 101; j++) {
            dist[i][j] = INF;
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    for(int tc= 1; tc <=T; tc++) {
        init();
        cin >> n;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> board[i][j];
            }
        }
        pq.push({0,0,0});
        while(!pq.empty()) {
            Pos cur = pq.top();
            pq.pop();
            int curX = cur.x;
            int curY = cur.y;
            int curCost = cur.w;

            if(dist[curX][curY] != INF) continue;
            dist[curX][curY] = curCost;

            for(int i = 0; i < 4; i++) {
                int nextX = curX + mx[i];
                int nextY = curY + my[i];
                if(nextX < 0 || nextY < 0 || nextX >= n || nextY >= n) continue;
                if(dist[nextX][nextY] != INF) continue;
                int nextCost = curCost + (board[nextX][nextY] - '0');
                pq.push({nextX,nextY,nextCost});
            }
        }
        cout << "#" << tc << " " << dist[n-1][n-1] << "\n";
    }
}