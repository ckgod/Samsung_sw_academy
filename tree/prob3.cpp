#include <iostream>
#include <string>
using namespace std;

int tree[201];
int n,ans;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    for(int tc = 1; tc <= 10; tc++) {
        cin >> n;
        ans = 1;
        for(int i = 1; i <= n; i++) {
            int t; cin >> t;
            string c; cin >> c;
            if(c == "-") tree[t] = -1;
            else if(c == "+") tree[t] = -2;
            else if(c == "*") tree[t] = -3;
            else if(c == "/") tree[t] = -4;
            else tree[t] = stoi(c);
            if(i * 2 <= n) {
                int lef; cin >> lef;
            }
            if(i*2+1 <= n) {
                int rig; cin >> rig;
            }
        }
        for(int i = 1; i <= n; i++) {
            if(i <= n/2) { // 다 연산자여야함
                if(!(tree[i] == -1 || tree[i] == -2 || tree[i] == -3 || tree[i] == -4)) ans = 0;
            }
            else { // 다 숫자여야함
                if(tree[i] == -1 || tree[i] == -2 || tree[i] == -3 || tree[i] == -4) ans = 0;
            }
        }

        cout << "#" << tc << " " << ans << "\n";
    }
    return 0;
}