#include <iostream>
#include <queue>
using namespace std;
#define MAX_M 1150001
#define MAX_N 50001

struct Edge {
    int w;
    int s, e;
    Edge* next;

    bool operator<(const Edge edg) const {
        return this->w > edg.w;
    }
} edge[MAX_M];

struct Room {
    Edge* data;
} room[MAX_N];

int memPoolCnt = 0;
int n, m, x, ans;
Room re_room[MAX_N];
int x_to_i[20][MAX_N];
int i_to_x[20][MAX_N];
priority_queue<Edge> pq;

Edge* getEdge(int _s, int _e, int _w) {
    edge[memPoolCnt].s = _s;
    edge[memPoolCnt].e = _e;
    edge[memPoolCnt].w = _w;
    edge[memPoolCnt].next = nullptr;
    return &edge[memPoolCnt++];
}

void init(int n) {
    memPoolCnt = 0;
    ans = 0;
}

void list_push_back(int s, int e, int w) {
    Edge* newEdge = getEdge(s, e, w);
    newEdge->next = room[s].data;
    room[s].data = newEdge;
}

void reverse_list_push_back(int s, int e, int w) {
    Edge* newEdge = getEdge(s, e, w);
    newEdge->next = re_room[s].data;
    re_room[s].data = newEdge;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 50001; j++) {
            x_to_i[i][j] = -1;
            i_to_x[i][j] = -1;
        }
    }

    int T; cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> n >> m >> x;
        init(n);
        for (int i = 0; i < m; i++) {
            int s, e, t; cin >> s >> e >> t;
            list_push_back(s, e, t);
            reverse_list_push_back(e, s, t);
        }
        //if (tc == 19) {
        //    cout << "#19 test\n";
        //    return 0;
        //}
        Edge start = { 0,x,x, nullptr };
        pq.push(start);
        while (!pq.empty()) {
            Edge curEdge = pq.top();
            int curRoom = curEdge.e;
            int curCost = curEdge.w;
            pq.pop();
            if (x_to_i[tc][curRoom] != -1) continue;
            x_to_i[tc][curRoom] = curCost;
            Edge* ptr = room[curRoom].data;
            while (ptr) {
                int nextRoom = ptr->e;
                int nextCost = ptr->w + curCost;
                if (x_to_i[tc][nextRoom] == -1) {
                    Edge tmp = { nextCost,curRoom,nextRoom, nullptr };
                    pq.push(tmp);
                }
                ptr = ptr->next;
            }
        }
        pq.push(start);
        while (!pq.empty()) {
            Edge curEdge = pq.top();
            int curRoom = curEdge.e;
            int curCost = curEdge.w;
            pq.pop();
            if (i_to_x[tc][curRoom] != -1) continue;
            i_to_x[tc][curRoom] = curCost;
            Edge* ptr = re_room[curRoom].data;
            while (ptr) {
                int nextRoom = ptr->e;
                int nextCost = ptr->w + curCost;
                if (i_to_x[tc][nextRoom] == -1) {
                    Edge tmp = { nextCost, curRoom, nextRoom, nullptr };
                    pq.push(tmp);
                }
                ptr = ptr->next;
            }
        }
        for (int i = 1; i <= n; i++) {
            int cost = x_to_i[tc][i] + i_to_x[tc][i];
            ans = (ans < cost ? cost : ans);
            room[i].data = nullptr;
            re_room[i].data = nullptr;
        }
        cout << "#" << tc << " " << ans << "\n";
    }
    return 0;
}