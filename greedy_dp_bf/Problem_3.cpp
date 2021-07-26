#include <iostream>
#include <algorithm>
using namespace std;

int duplicate[401];
int n;
int ans = 0;

void init() {
    for(int i = 0; i < 401; i++) {
        duplicate[i] = 0;
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t; cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        init();
        cin >> n;
        for(int i = 0; i < n; i++) {
            int a,b; cin >> a >> b;
            if(a > b) swap(a,b);

            if(a % 2 == 0) a-=1;
            if(b % 2 == 1) b+=1;

            for(int j = a; j <= b; j++) {
                duplicate[j]++;
            }
        }
        for(int i = 0; i <= 400; i++) {
            ans = max(ans, duplicate[i]);
        }
//        ans = *max_element(duplicate, duplicate+401);
        cout << "#" << tc << " " << ans << "\n";
        ans = 1;
    }
    return 0;
}