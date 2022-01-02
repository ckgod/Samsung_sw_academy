#include <iostream>
#include <vector>
using namespace std;

int n,m,k;
vector<int> graph[100001]; // 안에 3개까지 밖에 안들어감
int ind[100001];
bool exist[100001];
int cnt[100001]; // 건물이 여러개 지어질 수 도 있다???
bool cheat = false;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++) {
        int a,b; cin >> a >> b;
        graph[a].push_back(b);
        ind[b]++;
    }
    for(int i = 0; i < k; i++) {
        int a,b; cin >> a >> b;
        if(a == 1) {
            if(!ind[b]) { // 건설 할 수 있음
                exist[b] = true;
                if(!cnt[b]++) { // 처음 지을 떄
                    for(auto next : graph[b]) {
                        ind[next]--;
                    }
                }
            }
            else {
                cheat = true;
                break;
            }
        }
        else {
            if(!exist[b]) { // 존재하지 않는다면
                cheat = true;
                break;
            }
            else {
                if(cnt[b] == 1) {
                    exist[b] = false;
                    for(auto next : graph[b]) {
                        ind[next]++;
                    }
                }
                cnt[b]--;
            }
        }
    }
    if(cheat) cout << "Lier!";
    else cout << "King-God-Emperor";

    return 0;
}