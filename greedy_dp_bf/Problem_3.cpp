#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int c; string str;
int ans;
bool visit[1000000][11];

void shuffle(int idx, int shuffleCnt) {
    if(shuffleCnt == c) {
        ans = max(ans, stoi(str));
        return;
    }
    for(int i = idx; i < str.length(); i++) {
        for(int j = i+1; j < str.length(); j++) {
            swap(str[i],str[j]);
            int tmp = stoi(str);
            if(!visit[tmp][shuffleCnt+1]) {
                visit[tmp][shuffleCnt+1] = true;
                shuffle(i, shuffleCnt+1);
            }
            swap(str[i],str[j]);
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    for(int tc = 1; tc <= T; tc++) {
        ans = 0;
        cin >> str >> c;
        shuffle(0,0);
        cout << "#" << tc << " " << ans << "\n";
        memset(visit, 0, sizeof(visit));
    }


    return 0;
}