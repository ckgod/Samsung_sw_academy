#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define MAXN 1000000 // 대략 90만개정도 필요
#define ll long long

struct Trie;
Trie *myAlloc();
int searchTime = 0;

struct Trie {
    vector<pair<int,Trie*>> _children;
    bool lastLetter = false;
    int child = 0;
    int ret;
    int idx = -1;

    void add(const char *word, int idx, int _ret) {
        child++;
        _ret += child;
        if(*word == 0) {
            lastLetter = true;
            this->ret = _ret;
            this->idx = idx;
            return;
        }
        bool isFind = false;
        for(auto& c : _children) {
            if(c.first == *word-'a') {
                isFind = true;
                c.second->add(word+1,idx,_ret);
                break;
            }
        }
        if(!isFind) {
            Trie* tmp = myAlloc();
            _children.emplace_back(*word-'a',tmp);
            tmp->add(word+1, idx, _ret);
        }
    }

    void search2(const char *word, int _ret) {
        searchTime += child;
        if(*word == 0) {
            searchTime = this->ret;
        }
        for(auto& c : _children) {
            if(c.first == *word-'a') {
                c.second->search2(word+1,_ret);
                break;
            }
        }
    }

    Trie* get(const char *word) {
        if(*word != 0) {
            for(auto& c : _children) {
                if(c.first == *word -'a') return c.second->get(word+1);
            }
            return nullptr;
        }
        if(lastLetter) return this;
        else return nullptr;
    }

    void search(const char *word) {
        searchTime += child;
        if(*word == 0) {
            return;
        }
        for(auto&c : _children) {
            if(c.first == *word -'a') {
                c.second->search(word+1);
                break;
            }
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
int ans[30001];

Trie* myAlloc() {
    Trie* ret = &Node[nodeCnt++];
    ret->lastLetter = false;
    ret->child = 0;
    ret->ret = -1;
    ret->clear();
    return ret;
}

void init() {
    memset(ans,false,sizeof(ans));
    nodeCnt = 0;
    root = myAlloc();
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    init();
    cin >> n;
    for(int i = 0; i < n; i++) {
        char str[31]; cin >> str;
        root->add(str, i, 0);
    }
    cin >> n;
    for(int i = 0; i < n; i++) {
        char str[31]; cin >> str;
        searchTime = 0;
        root->search2(str,0);
        cout << searchTime << "\n";
    }
    return 0;
}