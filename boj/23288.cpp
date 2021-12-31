#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
#define BOTTOM 6

int n,m,k,ans;
int dice[7] = {0,1,2,3,4,5,6};
int board[21][21];
bool visit[21][21];
int curX = 1, curY = 1, curDir = 1;
int dirX[] = {0,0,1,0,-1};
int dirY[] = {0,1,0,-1,0};

void moveD(int move);

bool canMove(int x, int y, int dir) {
    int nextX = x + dirX[dir];
    int nextY = y + dirY[dir];
    if(nextX < 1 || nextY < 1 || nextX > n || nextY > m) return false;
    return true;
}
int reverseDir(int dir) {
    if(dir == 1) return 3;
    else if(dir == 3) return 1;
    else if(dir == 2) return 4;
    else if(dir == 4) return 2;
}

int getScore(int x, int y, int num) {
    memset(visit,false,sizeof(visit));
    queue<pair<int,int>> q;
    int cnt = 1;
    q.push({x,y});
    visit[x][y] = true;
    while(!q.empty()) {
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        for(int i = 1; i <= 4; i++) {
            int nextx = curx + dirX[i];
            int nexty = cury + dirY[i];
            if(nextx < 1 || nexty < 1 || nextx > n || nexty > m) continue;;
            if(visit[nextx][nexty]) continue;
            if(board[nextx][nexty] != num) continue;
            cnt++;
            visit[nextx][nexty] = true;
            q.push({nextx,nexty});
        }
    }
    return cnt;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> board[i][j];
        }
    }
    for(int moveCnt = 0; moveCnt < k; moveCnt++) {
        if(!canMove(curX, curY, curDir)) {
            curDir = reverseDir(curDir);
        }
        int nextX = curX + dirX[curDir];
        int nextY = curY + dirY[curDir];
        moveD(curDir);
        int A = dice[BOTTOM];
        int B = board[nextX][nextY];
        int C = getScore(nextX, nextY, B);
        ans += B * C;

        if(A > B) { // 시계방향
            if(++curDir == 5) curDir = 1;
        }
        else if(A < B) { // 반시계 방향
            if(!--curDir) curDir = 4;
        }
        curX = nextX;
        curY = nextY;
    }
    cout << ans;
    return 0;
}

void moveD(int move) {
    if(move == 1) { // 동
        int tmp = dice[3];
        dice[3] = dice[1]; dice[1] = dice[4]; dice[4] = dice[6];
        dice[6] = tmp;
    }
    else if(move == 2) { // 남
        int tmp = dice[2];
        dice[2] = dice[6]; dice[6] = dice[5]; dice[5] = dice[1];
        dice[1] = tmp;
    }
    else if(move == 3) { // 서
        int tmp = dice[4];
        dice[4] = dice[1]; dice[1] = dice[3]; dice[3] = dice[6];
        dice[6] = tmp;
    }
    else if(move == 4) { // 북
        int tmp = dice[2];
        dice[2] = dice[1]; dice[1] = dice[5]; dice[5] = dice[6];
        dice[6] = tmp;
    }
}