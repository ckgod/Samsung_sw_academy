#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> dp[501];
int m[501];
int n;
int x;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        dp[i].push_back(0);
        for (int j = 1; j <= i; j++) {
            cin >> x;
            if(n == 1) {
                cout << x;
                return 0;
            }
            dp[i].push_back(x);
        }
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == 1) {
                dp[i][j] += dp[i - 1][j];
                m[i] = max(dp[i][j], m[i]);
            } else if (j == i) {
                dp[i][j] += dp[i - 1][j - 1];
                m[i] = max(dp[i][j], m[i]);
            } else {
                dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
                m[i] = max(dp[i][j], m[i]);
            }
        }
    }

    cout << m[n];


    return 0;
}