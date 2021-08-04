#include <iostream>
#include <cmath>
using namespace std;
#define ll long long

ll n;
double ans = 1;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    ll sqrtN = sqrt(n);
    ans = n;
    for(ll i = 2; i <= sqrtN; i++) {
        if(n % i == 0) { // 소인수
            while(n % i == 0) {
                n /= i;
            }
            ans *= (1.0 - (1.0/(double)i));
        }
    }
    if(n != 1) { // n이 1이면 없어져버림
        ans *= (1.0 - (1.0/(double)n));
    }
    cout << (ll)ans;

    return 0;
}