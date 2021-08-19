#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

ll n; int k,q;
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> k >> q;
    while(q--) {
        ll a,b; cin >> a >> b;
        if(k == 1) cout << abs(a-b) << "\n";
        else {
            ll dis = 0;
            while(a != b) {
                ll maxAB = max(a,b);
                a = min(a,b);
                b = (maxAB - 2) / k+1;
                dis++;
            }
            cout << dis << "\n";
        }
    }
    return 0;
}