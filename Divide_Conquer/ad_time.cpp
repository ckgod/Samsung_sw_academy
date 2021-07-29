#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 1000001
int n,p;
bool arr[MAXN];

int solve(int p) {
    int ret = 0;
    int s = 0,e = 0;
    int check_cnt = p;
    while(e != MAXN) {
        if(arr[e]) {
            e++;
            ret = max(e-s, ret);
        }
        else {
            if(!check_cnt) { // 체크다함
                ret = max(ret, e-s);
                if(!arr[s]) check_cnt++;
                s++;
            }
            else {
                check_cnt--;
                e++;
            }
        }
    }
    return ret;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    for(int tc = 1; tc <= T; tc++) {
        memset(arr,0,sizeof(arr));
        cin >> n >> p;
        for(int i = 0; i < n; i++) {
            int t; cin >> t;
            arr[t] = true;
        }

        cout << "#" << tc << " " << solve(p) << "\n";
    }
    return 0;
}