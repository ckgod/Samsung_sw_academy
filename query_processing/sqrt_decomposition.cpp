#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

#define ll long long
#define MAX_N 1000001
#define MAX_N_SQ 1001

ll arr[MAX_N];
ll bucket[MAX_N_SQ];
int n, m, k, sq;

void update(int idx, ll val) {
    arr[idx] = val;
    int id = idx / sq; //그룹 번호
    int s = (id * sq); //그룹의 시작점
    int e = s + sq; //그룹의 끝접 + 1
    bucket[id] = 0;
    for (int i = s; i < e; i++) bucket[id] += arr[i];
}

ll query(ll l, ll r) {
    ll ret = 0;
    while (l % sq != 0 && l <= r) ret += arr[l++]; //왼쪽 몇 개
    while ((r + 1) % sq != 0 && l <= r) ret += arr[r--]; //오른쪽 몇 개

    while (l <= r) { //그룹 전체
        ret += bucket[l / sq];
        l += sq;
    }

    return ret;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m >> k;
    sq = sqrt(n);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        bucket[i / sq] += arr[i]; // 그룹 번호 : 인덱스 / sqrt
    }

    for (int i = 0; i < m + k; i++) {
        int a, b; ll c;
        cin >> a >> b >> c;
        if (a == 1) update(b, c);
        else cout << query(b, c) << "\n";
    }
}