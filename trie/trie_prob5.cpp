#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define ALPHABET_CNT 26
#define MAXN 1000000 // 대략 90만개정도 필요
#define ll long long

struct Trie;
Trie *myAlloc();
int searchTime = 0;

struct Query{
    char *word;
    int idx;
    int queryIdx;

    bool operator<(const Query q1) const {
        return this->idx < q1.idx;
    }
};

struct Dic{
    char *word;
    bool queryExist;
};


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
        if(lastLetter) return this;
        else return nullptr;
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
int n;
Trie *root;
vector<Query> existQuery;
vector<Query> nonExistQuery;
vector<Dic> dictionary;
char str2[30001][31];
char str1[30001][31];
ll ans[30001];
ll sum;

Trie* myAlloc() {
    Trie* ret = &Node[nodeCnt++];
    ret->lastLetter = false;
    ret->child = 0;
    ret->clear();
    return ret;
}

void init() {
    memset(ans,false,sizeof(ans));
    memset(str1,false,sizeof(str1));
    memset(str2,false,sizeof(str2));
    existQuery.clear();
    nonExistQuery.clear();
    dictionary.clear();
    nodeCnt = 0;
    sum = 0;
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
            cin >> str1[i];
            root->add(str1[i], i);
            dictionary.push_back({str1[i],false});
        }
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> str2[i];
            searchTime = 0;
            Trie* tmp = root->get(str2[i]);
            int findIdx = -1;
            if(tmp) findIdx = tmp->idx;
            if(findIdx == -1) { // 사전에 없을때
                nonExistQuery.push_back({str2[i],findIdx,i});
            }
            else { // 사전에 있을때
                existQuery.push_back({str2[i],findIdx, i});
                dictionary[findIdx].queryExist = true;
            }
        }
        sort(existQuery.begin(), existQuery.end());
        // 트라이 새로만들기
        nodeCnt = 0;
        root = myAlloc();
        int queryIdx = 0;
        for(int i = 0; i < dictionary.size(); i++) {
            root->add(dictionary[i].word, i);
            if(dictionary[i].queryExist) {
                searchTime = 0;
                root->search(existQuery[queryIdx].word);
                ans[existQuery[queryIdx].queryIdx] = searchTime;
                queryIdx++;
            }
        }
//
//        for(int i = 0; i < existQuery.size(); i++) { // 존재하는거 사전에 정렬된순서로
//            cout << existQuery[i].word << "\n";
//            root->add(existQuery[i].word, existQuery[i].idx);
//            searchTime = 0;
//            root->search(existQuery[i].word);
//            ans[existQuery[i].queryIdx] = searchTime;
//        }
        for(int i = 0; i < nonExistQuery.size(); i++) {
            searchTime = 0;
            root->search(nonExistQuery[i].word);
            ans[nonExistQuery[i].queryIdx] = searchTime;
        }
        for(int i = 0; i < n; i++) {
            sum += ans[i];
        }
        cout << "#" << tc << " " << sum << "\n";
    }

    return 0;
}