#include <iostream>
using namespace std;
int n,m;
int main(int argc, char **argv) {
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        cin >> n >> m;
        bool off = false;
        for(int i = 0; i < n; i++) {
            if(m & (1 << i)) continue;
            else {
                off = true; break;
            }
        }
        if(off) {
            cout << "#" << test_case << " OFF" << "\n";
        }
        else cout << "#" << test_case << " ON" << "\n";
    }
    return 0;
}