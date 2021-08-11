#include <iostream>
#include <algorithm>
using namespace std;
#define ALPHABET_CNT 26
#define MAXN 1000000 // 대략 90만개정도 필요

struct Trie;
Trie *myAlloc();
int searchTime = 0;

struct Trie {
    Trie* _children[ALPHABET_CNT];
    bool lastLetter = false;
    int child = 0;
    int idx = -1;

    void add(const char *word, int idx) {
        child++;
        if(*word == 0) {
            lastLetter = true;
            this->idx = idx;
            return;
        }
        if(_children[*word - 'a'] == nullptr) _children[*word -'a'] = myAlloc();
        _children[*word - 'a']->add(word+1, idx);
    }

    Trie* get(const char *word) {
        if(*word != 0) {
            if(_children[*word -'a'] != nullptr) return _children[*word-'a']->get(word+1);
            return nullptr;
        }
        return this;
    }

    void search(const char *word) {
        searchTime += child;
        if(*word == 0) {
            return;
        }
        if(_children[*word - 'a'] == nullptr) return;
        _children[*word -'a']->search(word+1);
    }

    void clear() {
        for(int i = 0; i < ALPHABET_CNT; i++) {
            _children[i] = nullptr;
        }
    }

};

int nodeCnt = 0;
Trie Node[MAXN];
int n, ans;
Trie *root;

Trie* myAlloc() {
    Trie* ret = &Node[nodeCnt++];
    ret->lastLetter = false;
    ret->child = 0;
    ret->clear();
    return ret;
}

void init() {
    ans = 0;
    nodeCnt = 0;
    root = myAlloc();
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    for(int tc = 1; tc <= T; tc++) {
        init();
        cin >> n;
        for(int i = 0; i < n; i++) {
            char str[31];
            cin >> str;
            root->add(str, i);
        }
        cin >> n;
        for(int i = 0; i < n; i++) {
            char str[31];
            cin >> str;
            searchTime = 0;
            Trie* tmp = root->get(str);
            int findIdx = -1;
            if(tmp) {
                cout << "find idx : " << tmp->idx << "\n";
                findIdx = tmp->idx;
            }
            root->search(str);
            ans += searchTime;
            cout << "searchTime : " << searchTime << "\n";
        }
        cout << "#" << tc << " " << ans << "\n";
    }

    return 0;
}