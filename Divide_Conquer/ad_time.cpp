#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int L,N,ans;
vector<pair<int,int>> peek;

int S[100001];
int A[100000], B[100000];

void b_search(int s, int e) {

    while(s <= e) {
        int m = (s+e)/2;


    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    for(int tc = 1; tc <= T; tc++) {
        cin >> L >> N;
        for(int i = 0; i < N; i++) {
            cin >> A[i] >> B[i];
            S[i+1] = S[i] + (B[i] - A[i]);
        }
        for(int i = 0; i <= N; i++) {
            cout << i << " : " << S[i] << "\n";
        }

    }
    return 0;
}