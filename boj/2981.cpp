#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m;
int arr[101];
set<int> s;

int gcd(int a, int b) {
    if(!b) return a;
    else return gcd(b, a % b);
}

int absol(int a) {
    if(a < 0) return -a;
    else return a;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for(int i = 1; i < n; i++) {
        m = gcd(absol(arr[i] - arr[i-1]), m);
    }
    for(int i = 1; i*i <= m; i++) {
        if(m % i == 0) {
            s.insert(i);
            s.insert(m/i);
        }
    }
    for(auto i : s) {
        if(i != 1) cout << i << " ";
    }
    return 0;
}