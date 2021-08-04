#include <iostream>
#include <string>
#include <stack>
#include <cstring>
using namespace std;
#define ll long long

struct Node{
    int val;
    int left;
    int right;
};

Node tree[3001];
int n;
int ans;
int postOrder(int idx) {
    if(idx <= n) {
        if(tree[idx].val == -1 || tree[idx].val == -2 || tree[idx].val == -3 || tree[idx].val == -4) {
            int left = postOrder(tree[idx].left);
            int right = postOrder(tree[idx].right);
            if(tree[idx].val == -1) {
                return left - right;
            }
            else if(tree[idx].val == -2) {
                return left + right;
            }
            else if(tree[idx].val == -3) {
                return left * right;
            }
            else if(tree[idx].val == -4) {
                return left / right;
            }
        }
        else return tree[idx].val;
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    for(int tc = 1; tc <= 10; tc++) {
        memset(tree, false, sizeof(tree));
        cin >> n;
        for(int i = 1; i <= n; i++) {
            int t; cin >> t;
            string c; cin >> c;
            if(c == "-") tree[t].val = -1;
            else if(c == "+") tree[t].val = -2;
            else if(c == "*") tree[t].val = -3;
            else if(c == "/") tree[t].val = -4;
            else tree[t].val = stoi(c);
            if(tree[t].val == -1 || tree[t].val == -2 || tree[t].val == -3 || tree[t].val == -4) {
                int lef, rig; cin >> lef >> rig;
                tree[t].left = lef;
                tree[t].right = rig;
            }
        }
        ans = postOrder(1);
        cout << "#" << tc << " " << ans << "\n";
    }

    return 0;
}