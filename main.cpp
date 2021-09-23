#include<iostream>
#include<string>
#include<queue>
#include<utility>
using namespace std;


int n, m;
bool board[100][100];
bool visit[100][100];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };
int depth=0;


void bfs() {
    depth++;
    visit[0][0] = true;
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    while (!q.empty()) {
        bool find = false;
        pair<int, int> currentNode = q.front();
        q.pop();
        for (int move = 0; move < 4; move++) {
            int nx = currentNode.second+dx[move];
            int ny = currentNode.first+dy[move];
            if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                if (board[ny][nx]) {
                    if (!visit[ny][nx]) {
                        visit[ny][nx] = true;
                        find = true;
                        q.push(make_pair(ny, nx));
                    }
                }
            }
        }
        if (find) {
            depth++;
        }
        if (visit[n - 1][m - 1]){
            return;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        for (int j = 0; j < m; j++) {
            board[i][j] = temp[j] - '0';
        }
    }
    bfs();
    cout << depth << "\n";
}