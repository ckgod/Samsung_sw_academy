#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define MAXN 1000000 // 대략 90만개정도 필요
#define ll long long

struct Trie;
Trie *myAlloc();
ll sum;

struct Trie {
    vector<pair<int,Trie*>> _children;
    bool lastLetter = false;
    int child;
    int ret;

    void add(const char *word,int _idx,int _ret) {
        child++;
        _ret += child;
        if(*word == 0) {
            lastLetter = true;
            this->ret = _ret;
            return;
        }
        bool isFind = false;
        for(auto& c : _children) {
            if(c.first == *word-'a') {
                isFind = true;
                c.second->add(word+1,_idx,_ret);
                break;
            }
        }
        if(!isFind) {
            Trie* tmp = myAlloc();
            _children.emplace_back(*word-'a',tmp);
            tmp->add(word+1,_idx,_ret);
        }
    }

    void clear() {
        _children.clear();
    }

};

int nodeCnt = 0;
Trie Node[MAXN];
int n;
Trie *root;

void init() {
    nodeCnt = 0;
    root = myAlloc();
    sum = 0;
}

Trie* myAlloc() {
    Trie* ret = &Node[nodeCnt++];
    ret->lastLetter = false;
    ret->child = 0;
    ret->ret = -1;
    ret->clear();
    return ret;
}

int searchTime(const char *word) {
    Trie* ptr = root;
    int cnt = 0;
    bool none = false;
    for(int i = 0; word[i]; i++) {
        cnt += ptr->child;
        bool isFind = false;
        for(auto& c : ptr->_children) {
            if(c.first == word[i]-'a') {
                isFind = true;
                ptr = c.second;
                continue;
            }
        }
        if(!isFind) {
            none = true;
            break;
        }
    }
    if(none) return cnt;
    if(!ptr->lastLetter) return cnt + ptr->child;
    return ptr->ret;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    for(int tc = 1; tc <= T; tc++) {
        init();
        cin >> n;
        for(int i = 0; i < n; i++) {
            char str[31]; cin >> str;
            root->add(str,i,0);
        }
        cin >> n;
        for(int i = 0; i < n; i++) {
            char str[31];
            cin >> str;
            sum += searchTime(str);
        }
        cout << "#" << tc << " " << sum << "\n";
    }

    return 0;
}