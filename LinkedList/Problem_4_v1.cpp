#include <iostream>
#include <queue>
using namespace std;
#define MAX_M 1100001
#define MAX_N 50001
#define INF 190000111

struct Edge{
    int w;
    int s, e;
    Edge *next;

    bool operator<(const Edge edg) const {
        return this->w > edg.w;
    }
} edge[MAX_M];

struct Room{
    Edge* head;
} room[MAX_N];

int memPoolCnt = 0;
int n,m,x,ans;
Room re_room[MAX_N];
int x_to_i[MAX_N];
int i_to_x[MAX_N];
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
    for(int i = 1; i <= n; i++) {
        room[i].head = getEdge(i,i,0);
        re_room[i].head = getEdge(i,i,0);
        x_to_i[i] = INF;
        i_to_x[i] = INF;
    }
}

void list_push_back(int s, int e, int w) {
    Edge* newEdge = getEdge(s,e,w);
    newEdge->next = room[s].head->next;
    room[s].head->next = newEdge;
}

void reverse_list_push_back(int s, int e, int w) {
    Edge* newEdge = getEdge(s,e,w);
    newEdge->next = re_room[s].head->next;
    re_room[s].head->next = newEdge;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    for(int tc = 1; tc <= T; tc++) {
        cin >> n >> m >> x;
        init(n);
        x_to_i[x] = 0;
        i_to_x[x] = 0;
        for(int i = 0; i < m; i++) {
            int s,e,t; cin >> s >> e >> t;
            list_push_back(s,e,t);
            reverse_list_push_back(e,s,t);
        }
        pq.push(*room[x].head);
        while(!pq.empty()) {
            Edge curEdge = pq.top();
            int curRoom = curEdge.e;
            int curCost = curEdge.w;
            pq.pop();
            if(x_to_i[curRoom] < curCost) continue;
            Edge* ptr = room[curRoom].head;
            while(ptr->next) {
                int nextRoom = ptr->next->e;
                int nextCost = ptr->next->w + curCost;
                if(x_to_i[nextRoom] > nextCost) {
                    Edge tmp = {nextCost,curRoom,nextRoom,nullptr};
                    x_to_i[nextRoom] = nextCost;
                    pq.push(tmp);
                }
                ptr = ptr->next;
            }
        }
//        for(int i = 1; i<=n; i++) {
//            cout << x_to_i[i] << " ";
//        }
//        cout << "\n";
        pq.push(*re_room[x].head);
        while(!pq.empty()) {
            Edge curEdge = pq.top();
            int curRoom = curEdge.e;
            int curCost = curEdge.w;
            pq.pop();
            if(i_to_x[curRoom] < curCost) continue;
            Edge* ptr = re_room[curRoom].head;
            while(ptr->next) {
                int nextRoom = ptr->next->e;
                int nextCost = ptr->next->w + curCost;
                if(i_to_x[nextRoom] > nextCost) {
                    Edge tmp = {nextCost, curRoom, nextRoom, nullptr};
                    i_to_x[nextRoom] = nextCost;
                    pq.push(tmp);
                }
                ptr = ptr->next;
            }
        }
//        for(int i = 1; i<=n; i++) {
//            cout << i_to_x[i] << " ";
//        }
//        cout << "\n";
        for(int i = 1; i <= n; i++) {
            if(x_to_i[i] != INF && i_to_x[i] != INF) {
                int cost = x_to_i[i] + i_to_x[i];
                ans = (ans < cost ? cost : ans);
            }
        }

        cout << "#" << tc << " " << ans << "\n";
    }
    return 0;
}
