#define MAX_N 100000

struct Pair{
    int x,y;
};

int front;
int rear;
Pair queue[MAX_N];

void queueInit() {
    front = 0;
    rear = 0;
}

int queueIsEmpty() {
    return (front == rear);
}

int q_push(Pair value) {
    queue[rear] = value;
    rear++;
    if (rear == MAX_N) {
        rear = 0;
    }
    return 1;
}

int q_pop() {
    if (queueIsEmpty()) return 0;
//    *value = queue[front];
    front++;
    if (front == MAX_N) {
        front = 0;
    }
    return 1;
}

int board[11][11];
bool visit[11][11];
int mx[] = {0,0,1,-1};
int my[] = {1,-1,0,0};
int dist[11][11];
int n;

void visit_init() {
    for(int i = 1; i < 11; i++) {
        for(int j = 1; j < 11; j++) {
            visit[i][j] = false;
            dist[i][j] = 0;
        }
    }
}

void bfs_init(int N, int map[10][10]) {
    n = N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i + 1][j + 1] = map[i][j];
            visit[i + 1][j + 1] = false;
        }
    }
}

int bfs(int x1, int y1, int x2, int y2) {
    visit_init();
    queueInit();
    Pair start = {x1,y1};
    q_push(start);
    visit[y1][x1] = true;
    while(!queueIsEmpty()) {
        Pair curPair = queue[front];
        int curX = curPair.x;
        int curY = curPair.y;
        q_pop();
        for(int i = 0; i < 4; i++) {
            int nextX = curX + mx[i];
            int nextY = curY + my[i];
            if(nextX >= 1 && nextY >=1 && nextX <= n && nextY <= n) { // 좌표안
                if(!visit[nextY][nextX]) { // 방문체크
                    if(board[nextY][nextX] == 0) { // 벽인지 확인
                        dist[nextY][nextX] = dist[curY][curX] + 1;
                        visit[nextY][nextX] = true;
                        q_push({nextX,nextY});
                    }
                }
            }
        }
    }

    if(dist[y2][x2] == 0) return -1;
    else return dist[y2][x2];
}
