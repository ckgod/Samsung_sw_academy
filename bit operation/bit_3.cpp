#include <iostream>
#include <string>
using namespace std;
#define mod 1000000007
#define ll long long
string str;
ll dp[10001][1<<4];
bool visit[1<<4];

void init(){
    for(int i = 0; i < 10001; i++) {
        for(int j = 0; j < (1<<4); j++) {
            dp[i][j] = 0;
        }
    }
}
void initV() {
    for(int i = 0; i < (1<<4); i++) {
        visit[i] = false;
    }
}

int main(int argc, char **argv) {
    int T; cin >> T;
    for (int test_case = 1; test_case <= T; ++test_case) {
        init();
        cin >> str;
        int cnt = 0;
        int preStatus = 1;
        preStatus |= (1 << (str[0] - 'A'));

        for(int i = 0; i < (1<<4); i++) {
            dp[1][preStatus | i] = 1;
        }

        for(int i = 2; i <= str.length(); i++) {
            for(int j = 0; j < (1<<4); j++) {
                if(dp[i-1][j]) {
                    for(int k = 0; k < (1<<4); k++) {
                        int t = k | (1 << (str[i-1] - 'A'));
                        if(t & j) {
                            if(!visit[t]) {
                                dp[i][t] += dp[i-1][j];
                                dp[i][t] %= mod;
                                visit[t] = true;
                            }
                        }
                    }
                    initV();
                }
            }
        }
        for(int i = 0; i < (1<<4); i++) {
            cnt += dp[str.length()][i];
            cnt %= mod;
        }

        cout << "#" << test_case << " " << cnt << "\n";
    }
    return 0;
}