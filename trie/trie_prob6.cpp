#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct Trie;
Trie* root;
Trie* root2;
int check[2002];

struct Trie{
    vector<pair<char,Trie*>> _children;
    bool lastLetter;
    Trie() {
        _children.clear();
        lastLetter = false;
    }

    void add(const char *word) {
        if(*word == 0) {
            lastLetter = true;
            return;
        }
        bool isFind = false;
        for(auto& c : _children) {
            if(c.first == *word) {
                isFind = true;
                c.second->add(word+1);
                break;
            }
        }
        if(!isFind) {
            Trie* tmp = new Trie();
            _children.push_back({*word,tmp});
            tmp->add(word+1);
        }
    }

    void find(const char *word, int idx, bool type) {
        if(lastLetter) check[idx]++;
        if(*word == 0) return;
        for(auto& c : _children) {
            if(c.first == *word) {
                c.second->find(word+1, type ? idx + 1 : idx - 1, type);
                break;
            }
        }
    }
};

int c,n,q;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    root = new Trie();
    root2 = new Trie();
    cin >> c >> n;
    for(int i = 0; i < c; i++) {
        string color; cin >> color;
        root->add(color.c_str());
    }
    for(int i = 0; i < n; i++) {
        string name; cin >> name;
        reverse(name.begin(), name.end());
        root2->add(name.c_str());
    }
    cin >> q;
    while(q--) {
        bool isYes = false;
        memset(check, false, sizeof(check));
        string team; cin >> team;
        int len = team.length();
        root->find(team.c_str(),0,true);
        reverse(team.begin(),team.end());
        root2->find(team.c_str(),len,false);
        for(int i = 0; i < len; i++) {
//            if(check[i] == 0) cout << "-";
//            else cout << check[i];
            if(check[i] == 2) {
                isYes = true;
                break;
            }
        }
//        cout << "\n";
        if(isYes) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}