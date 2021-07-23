#include<iostream>
using namespace std;

int money[8] = {50000,10000,5000,1000,500,100,50,10};
int n;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t; cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        cin >> n;
        cout << "#" << tc << "\n";
        for(int i = 0; i < 8; i++) {
            int t = n / money[i];
            n %= money[i];
            cout << t << " ";
        }
        cout << "\n";
    }
    return 0;
}