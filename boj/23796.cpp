#include <iostream>
#include <vector>
using namespace std;
#define ll long long

ll board[8][8];
ll ans[8][8];
char comm;
vector<ll> tmp[8];

void checkAns() {
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}

void merge(int i) {
    for(int j = 1; j < tmp[i].size(); j++) {
        if(tmp[i][j] == tmp[i][j-1]) {
            tmp[i][j-1] *= 2;
            tmp[i][j] = 0;
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            cin >> board[i][j];
        }
    }
    cin >> comm;
    if(comm == 'U') {
        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                if(board[j][i]) tmp[i].push_back(board[j][i]);
            }
            merge(i);
            int curIdx = 0;
            for(auto j : tmp[i]) {
                if(!j) continue;
                ans[curIdx++][i] = j;
            }
        }
    }
    else if(comm == 'D') {
        for(int i = 0; i < 8; i++) {
            for(int j = 7; j >= 0; j--) {
                if(board[j][i]) tmp[i].push_back(board[j][i]);
            }
            merge(i);
            int curIdx = 7;
            for(auto j : tmp[i]) {
                if(!j) continue;
                ans[curIdx--][i] = j;
            }
        }
    }
    else if(comm == 'R') {
        for(int i = 0; i < 8; i++) {
            for(int j = 7; j >= 0; j--) {
                if(board[i][j]) tmp[i].push_back(board[i][j]);
            }
            merge(i);
            int curIdx = 7;
            for(auto j : tmp[i]) {
                if(!j) continue;
                ans[i][curIdx--] = j;
            }
        }
    }
    else if(comm == 'L') {
        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                if(board[i][j]) tmp[i].push_back(board[i][j]);
            }
            merge(i);
            int curIdx = 0;
            for(auto j : tmp[i]) {
                if(!j) continue;
                ans[i][curIdx++] = j;
            }
        }
    }
    checkAns();

    return 0;
}

