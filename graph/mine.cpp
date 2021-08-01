#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define OPEN (-2)

char board[301][301];
int ansBoard[301][301];
bool visit[301][301];
int n;

int ax[] = {0,0,1,-1,1,1,-1,-1};
int ay[] = {1,-1,0,0,1,-1,-1,1};

int ans = 0;

void init() {
    memset(visit,false,sizeof(visit));
    memset(ansBoard,false,sizeof(ansBoard));
    ans = 0;
}

void setAround(int x,int y) {
    for(int i = 0; i < 8; i++) {
        int cx = x+ax[i];
        int cy = y+ay[i];
        if(cx < 0 || cy < 0 || cx > n-1 || cy > n-1) continue;
        if(board[cx][cy] != '*') {
            ansBoard[cx][cy]++;
        }
    }
    ansBoard[x][y] = -1;
}

void bfs(int x, int y) {
    queue<pair<int,int>> q;
    q.push({x,y});
    visit[x][y] = true;
    while(!q.empty()) {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();
        for(int i = 0; i < 8; i++) {
            int nextX = curX + ax[i];
            int nextY = curY + ay[i];
            if(nextX < 0 || nextY < 0 || nextY > n-1 || nextX > n-1) continue;
            if(ansBoard[nextX][nextY]) {
                ansBoard[nextX][nextY] = OPEN;
            }
            else {
                if(visit[nextX][nextY]) continue;
                q.push({nextX,nextY});
                visit[nextX][nextY] = true;
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    for(int tc = 1; tc <= T; tc++) {
        init();
        cin >> n;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> board[i][j];
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == '*') setAround(i,j);
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n ; j++) {
                if(!ansBoard[i][j] && !visit[i][j]) {
                    bfs(i,j);
                    ans++;
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n ; j++) {
                if(ansBoard[i][j] != 0 && ansBoard[i][j] != OPEN && board[i][j] != '*') {
                    ans++;
                }
            }
        }

        cout << "#" << tc << " " << ans << "\n";
    }

    return 0;
}