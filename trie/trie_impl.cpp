#include <iostream>
#include <string>
using namespace std;
#define ALPHABETS_CNT 26
#define MAXN 10000

struct Trie;
Trie* myAlloc();

struct Trie{
    Trie* _children[26];

    void add(const char* word) {
        if(*word != 0) {
            if(_children[*word - 'a'] == nullptr) _children[*word - 'a'] = myAlloc();
            _children[*word -'a']->add(word+1);
        }
    }

    Trie* get(const char* word) {
        if (*word != 0) {
            if (_children[*word - 'a'] != nullptr) return _children[*word - 'a']->get(word + 1);
            return nullptr;
        }
        return this;
    }

    void clear() {
        for(int i = 0; i < ALPHABETS_CNT; i++) {
            _children[i] = nullptr;
        }
    }
};

Trie Node[MAXN];
int nodeCnt = 0;
Trie* myAlloc() {
    Trie* ret = &Node[nodeCnt++];
    ret->clear();
    return ret;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    nodeCnt = 0;
    Trie* root = myAlloc();
    root->add("hello");
    root->add("hi");
    root->add("high");
    root->add("goodnight");

    string answer = root->get("goodbye") ? "exist" : "not exist";
    cout << answer;

    return 0;
}