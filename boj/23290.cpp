#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int m, s, sharkX, sharkY, ans;
// 물고기 방향
int fishDirX[] = {0,0,-1,-1,-1,0,1,1,1};
int fishDirY[] = {0,-1,-1,0,1,1,1,0,-1};
// 상어 이동방향
int dx[] = {0,-1,0,1,0};
int dy[] = {0,0,-1,0,1};
int checkMaxFish[5][5][5];

struct Fish{
    int x,y;
    int dir;
    bool moveFlag;
    bool isDead;
};

struct FishSmell{
    int x,y;
    int practiceCnt;
};

struct Box{
    vector<Fish> fishList;
    vector<FishSmell> SmellList;
    int fishCnt = 0;
};

Box board[5][5];
bool visit[5][5];

bool checkMove(int x, int y) {
    // 범위 초과 체크
    if(x < 1 || y < 1 || x > 4 || y > 4) return false;
    // 상어 위치 체크
    if(x == sharkX && y == sharkY) return false;
    // 물고기 냄새 체크
    if(board[x][y].SmellList.size() > 0) return false;
    return true;
}

void initMoveFlag() {
    for(int i = 1; i < 5; i++) {
        for(int j = 1; j < 5; j++) {
            for(int k = 0; k < board[i][j].fishList.size(); k++) {
                board[i][j].fishList[k].moveFlag = false;
            }
        }
    }
}

void initFishCheck() {
    for(int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            for (int k = 1; k <= 4; k++) {
                checkMaxFish[i][j][k] = 0;
            }
        }
    }
}

void initVisit() {
    for(int i = 1; i <= 4; i++) {
        for(int j = 1; j <=4; j++) {
            visit[i][j] = false;
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> m >> s;
    for(int i = 0; i < m; i++) {
        int a,b,c; cin >> a >> b >> c;
        board[a][b].fishList.push_back({a,b,c,false, false});
        board[a][b].fishCnt++;
    }
    cin >> sharkX >> sharkY;
    for(int curPractice = 0; curPractice < s; curPractice++) {
        // 1. 현재 물고기들 위치, 방향 저장
        vector<Fish> pasteFishList;
        for(int i = 1; i < 5; i++) {
            for(int j = 1; j < 5; j++) {
                for(auto f : board[i][j].fishList) {
                    if(!f.isDead) pasteFishList.push_back(f);
                }
            }
        }
        // 2. 물고기 이동
        for(int i = 1; i < 5; i++) {
            for(int j = 1; j < 5; j++) {
                for(vector<Fish>::iterator curFish = board[i][j].fishList.begin(); curFish != board[i][j].fishList.end();) {
                    if(!curFish->moveFlag && !curFish->isDead) {
                        int curDir = curFish->dir;
                        bool fishCanMove = false;
                        for(int k = 0; k < 8; k++) {
                            // 그 방향으로 이동할 수 있는지 확인
                            int nextX = curFish->x + fishDirX[curDir];
                            int nextY = curFish->y + fishDirY[curDir];
                            if(checkMove(nextX,nextY)) {
                                board[nextX][nextY].fishList.push_back({nextX, nextY, curDir, true, false});
                                board[nextX][nextY].fishCnt++;
                                fishCanMove = true;
                                break;
                            }
                            else {
                                curDir--;
                                if(!curDir) curDir = 8;
                            }
                        }
                        if(fishCanMove) { // 물고기가 이동할 수 있으면
                            curFish->isDead = true;
                            board[i][j].fishCnt--;
                        }
                        ++curFish;
                    }
                    else {
                        ++curFish;
                    }
                }
            }
        }
        initMoveFlag(); // 물고기 이동했다는 플래그 초기화

        // 3. 상어가 물고기 지우기
        int maxFishCnt = 0;
        for(int i = 1; i <= 4; i++) {
            for(int j = 1; j <= 4; j++) {
                for(int k = 1; k <= 4; k++) {
                    // i -> j -> k 순서로 이동
                    initVisit();
                    int fishCnt = 0;
                    int nextX = sharkX + dx[i];
                    int nextY = sharkY + dy[i];
                    if(nextX < 1 || nextY < 1 || nextX > 4 || nextY > 4) continue;
                    fishCnt += board[nextX][nextY].fishCnt;
                    visit[nextX][nextY] = true;
                    nextX += dx[j];
                    nextY += dy[j];
                    if(nextX < 1 || nextY < 1 || nextX > 4 || nextY > 4) continue;
                    if(!visit[nextX][nextY]) fishCnt += board[nextX][nextY].fishCnt;
                    visit[nextX][nextY] = true;
                    nextX += dx[k];
                    nextY += dy[k];
                    if(nextX < 1 || nextY < 1 || nextX > 4 || nextY > 4) continue;
                    if(!visit[nextX][nextY]) fishCnt += board[nextX][nextY].fishCnt;
                    visit[nextX][nextY] = true;
                    checkMaxFish[i][j][k] = fishCnt;
                    maxFishCnt = max(maxFishCnt, fishCnt);
                }
            }
        }
        bool removeFish = false;
        for(int i = 1; i <= 4; i++) {
            for (int j = 1; j <= 4; j++) {
                for (int k = 1; k <= 4; k++) {
                    if(maxFishCnt == checkMaxFish[i][j][k]) {
                        if(sharkX + dx[i] < 1 || sharkY + dy[i] < 1 || sharkX + dx[i] > 4 || sharkY + dy[i] > 4) continue;
                        if(sharkX + dx[i] + dx[j] < 1 || sharkY + dy[i] + dy[j] < 1 || sharkX + dx[i] + dx[j] > 4 || sharkY + dy[i] + dy[j] > 4) continue;
                        if(sharkX + dx[i] + dx[j] + dx[k] < 1 || sharkY + dy[i] + dy[j] + dy[k] < 1 || sharkX + dx[i] + dx[j] + dx[k] > 4 || sharkY + dy[i] + dy[j] + dy[k] > 4) continue;

                        sharkX += dx[i]; sharkY += dy[i];
                        if(board[sharkX][sharkY].fishCnt > 0) {
                            board[sharkX][sharkY].SmellList.push_back({sharkX,sharkY,curPractice});
                            board[sharkX][sharkY].fishList.clear();
                            board[sharkX][sharkY].fishCnt = 0;
                        }

                        sharkX += dx[j]; sharkY += dy[j];
                        if(board[sharkX][sharkY].fishCnt > 0) {
                            board[sharkX][sharkY].SmellList.push_back({sharkX,sharkY,curPractice});
                            board[sharkX][sharkY].fishList.clear();
                            board[sharkX][sharkY].fishCnt = 0;
                        }

                        sharkX += dx[k]; sharkY += dy[k];
                        if(board[sharkX][sharkY].fishCnt > 0) {
                            board[sharkX][sharkY].SmellList.push_back({sharkX,sharkY,curPractice});
                            board[sharkX][sharkY].fishList.clear();
                            board[sharkX][sharkY].fishCnt = 0;
                        }
                        removeFish = true;
                    }
                    if(removeFish) break;
                }
                if(removeFish) break;
            }
            if(removeFish) break;
        }
        initFishCheck();

        // 4. 물고기 냄새 지우기
        for(int i = 1; i <= 4; i++) {
            for (int j = 1; j <= 4; j++) {
                for(vector<FishSmell>::iterator smell = board[i][j].SmellList.begin(); smell != board[i][j].SmellList.end();) {
                    if(smell->practiceCnt == curPractice - 2) {
                        smell = board[i][j].SmellList.erase(smell);
                    }
                    else {
                        ++smell;
                    }
                }
            }
        }

        // 5. 처음에 저장한 물고기 복제
        for(auto f : pasteFishList) {
            board[f.x][f.y].fishList.push_back({f.x,f.y,f.dir,false});
            board[f.x][f.y].fishCnt++;
        }
    }

    for(int i = 1; i < 5; i++) {
        for(int j = 1; j < 5; j++) {
            ans += board[i][j].fishCnt;
        }
    }
    cout << ans;

    return 0;
}