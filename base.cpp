#include <iostream>
using namespace std;
int n,x;
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> x;
    while(n--) {
        int t; cin >> t;
        if(t < x) cout << t << " ";
    }
    return 0;
}