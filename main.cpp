#include <iostream>
#include <string>
using namespace std;
int n,m; string str;
long long dp[10001][1<<4];
bool v[1<<4];

int main() {
    int t; cin >> t;
    for(int tc = 1; tc <=t; ++tc){
        for(int i = 0; i < 10001; i++) {
            for(int j = 0; j < (1<<4); j++) {
                dp[i][j] = 0;
            }
        }
        string str; cin >> str;
        int cnt = 0; int p = 1;
        p |= (1 << (str[0] = 'A'));
        for(int i = 0; i < 16; i++) {
            dp[1][p | i] = 1;
        }
        for(int i = 2; i <= str.length(); i++) {
            for(int j = 0; j < 16; j++) {
                if(dp[i-1][j]) {
                    for(int k = 0; k < 16; k++) {
                        int t = k | (1 << (str[i-1] - 'A'));
                        if(t & j && !v[t]) {
                            dp[i][t] += dp[i-1][j];
                            dp[i][t] %= 1000000007;
                            v[t] = true;
                        }
                    }
                    for(int k = 0; k < 16; k++) v[k] = false;
                }
            }
        }
        for(int i = 0; i < 16; i++) {
            cnt += dp[str.length()][i];
            cnt %= 1000000007;
        }
        cout << "#" << tc << " " << cnt << "\n";
    }
}