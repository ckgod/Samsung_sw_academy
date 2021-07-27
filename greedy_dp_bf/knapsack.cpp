#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int dp[101][1001];
int w[101], v[101];

int n, k;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    for(int tc = 1; tc <= T; tc++) {
        memset(dp, 0, sizeof(dp));
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> w[i] >> v[i];
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                if (w[i] > j) {
                    dp[i][j] = dp[i - 1][j];
                    ans = max(ans, dp[i][j]);
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        cout << "#" << tc << " " << ans << "\n";
    }

    return 0;
}