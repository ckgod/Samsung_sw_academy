#include <iostream>
#include <queue>
using namespace std;

int n;
priority_queue<int> pq;


int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    for(int tc= 1; tc <=T; tc++) {
        cin >> n;
        cout << "#" << tc << " ";
        for(int i = 0; i < n; i++) {
            int cmd; cin >> cmd;
            if(cmd == 1) {
                int t; cin >> t;
                pq.push(t);
            }
            else if(cmd == 2) {
                if(!pq.empty()) {
                    int t = pq.top();
                    pq.pop();
                    cout << t << " ";
                }
                else cout << "-1 ";
            }
        }
        while(!pq.empty()) {
            pq.pop();
        }
        cout << "\n";
    }
}