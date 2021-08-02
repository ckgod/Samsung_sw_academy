#include <iostream>
#include <string>
using namespace std;

char tree[101];
int n;
string ans;

void inOrder(int idx) {
    if(idx <= n) {
        inOrder(idx*2);
        ans += tree[idx];
        inOrder(idx*2 + 1);
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    for(int tc = 1; tc <= 10; tc++) {
        ans = "";
        cin >> n;
        for(int i = 1; i <= n; i++) {
            int t; cin >> t;
            char c; cin >> c;
            if(i * 2 <= n) {
                int lef; cin >> lef;
            }
            if(i*2+1 <= n) {
                int rig; cin >> rig;
            }
            tree[i] = c;
        }
        inOrder(1);
        cout << "#" << tc << " " << ans << "\n";
    }

    return 0;
}