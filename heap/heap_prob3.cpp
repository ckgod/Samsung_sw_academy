#include <iostream>
#include <queue>
using namespace std;

struct Object {
    int cnt, leftNum;
    bool operator<(const Object o1) const {
        return o1.cnt < this->cnt;
    }
};

int A[11];
int n,k;
int ans;
priority_queue<Object> pq;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    for(int tc = 1; tc <= T; tc++) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> A[i];
        }
        cin >> k;
        pq.push({0,k});
        while(1) {
            if(pq.top().leftNum == 0) break;
            if(pq.empty()) break;
            Object cur = pq.top();
            pq.pop();
            for(int i = 0; i < n; i++) {
                pq.push({cur.cnt + cur.leftNum % A[i], cur.leftNum / A[i]});
            }
        }
        ans = pq.top().cnt;
        cout << "#" << tc << " " << ans << "\n";

        while(!pq.empty()) {
            pq.pop();
        }
    }
    return 0;
}