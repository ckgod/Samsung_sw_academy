#include <iostream>
#include <vector>
using namespace std;
#define CONNECT_CORE 3
#define WIRE 2
#define INF 21222222

int board[12][12];
int coreN = 0;
int n;
vector<pair<int,int>> coreV;
int maxCoreCnt = 0;
int minWireLen = INF;

int checkCoreCnt = 0;
int checkWireLen = 0;

// 오, 왼, 하, 상
int mx[] = {0,0,1,-1};
int my[] = {1,-1,0,0};

void init() {
    maxCoreCnt = 0;
    minWireLen = INF;
    coreV.clear();
    coreN = 0;
    checkCoreCnt = 0;
    checkWireLen = 0;
}

int connect_possible(int dir, int x, int y) {
    vector<pair<int,int>> tmp;
    int curX = x;
    int curY = y;
    while(true) {
        if(curX == 0 || curY == 0 || curX == n-1 || curY == n-1) break;
        int nextX = curX + mx[dir];
        int nextY = curY + my[dir];
        if(board[nextX][nextY] == 1 || board[nextX][nextY] == WIRE || board[nextX][nextY] == CONNECT_CORE) {
            for(auto p : tmp) {
                board[p.first][p.second] = 0;
            }
            return 0;
        }
        board[nextX][nextY] = WIRE;
        tmp.push_back({nextX,nextY});
        curX = nextX;
        curY = nextY;
    }
    board[x][y] = CONNECT_CORE;
    checkCoreCnt++;
    checkWireLen += tmp.size();
    return tmp.size();
}

void resetConnect(int dir, int x, int y, int len) {
    int curX = x;
    int curY = y;
    board[curX][curY] = 1;
    checkCoreCnt--;
    checkWireLen -= len;
    while(true) {
        if(curX == 0 || curY == 0 || curX == n-1 || curY == n-1) break;
        int nextX = curX + mx[dir];
        int nextY = curY + my[dir];
        board[nextX][nextY] = 0;
        curX = nextX;
        curY = nextY;
    }
}

void dfs(int cur) {
    if(cur == coreN) {
        if(maxCoreCnt < checkCoreCnt) {
            maxCoreCnt = checkCoreCnt;
            minWireLen = checkWireLen;
        }
        else if(maxCoreCnt == checkCoreCnt) {
            minWireLen = min(minWireLen,checkWireLen);
        }
        return;
    }
    for(int i = 0; i < 4; i++) {
        int tmp = connect_possible(i,coreV[cur].first,coreV[cur].second);
        if(tmp) { // 연결을 했을때만 지워줌
            dfs(cur + 1);
            resetConnect(i, coreV[cur].first, coreV[cur].second, tmp);
        }
    }
    dfs(cur + 1); // 연결 안됐을때도 고려
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
                if(board[i][j]) {
                    if(i != 0 && j != 0 && i != n-1 && j != n-1) {
                        coreV.push_back({i,j});
                    }
                    else {
                        board[i][j] = CONNECT_CORE;
                        checkCoreCnt++;
                    }
                }
            }
        }
        coreN = coreV.size();
        dfs(0);

//        cout << maxCoreCnt << "\n";
        cout << "#" << tc << " " << minWireLen << "\n";
    }


    return 0;
}