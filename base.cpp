#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int n;

struct Trie{
    map<string,Trie*> _children;
    int depth;

    Trie() {
        depth = -1;
    }

    Trie(int _depth) {
        depth = _depth;
    }

    void add(vector<string> &word, int idx) {
        if(idx == word.size()) return;
        if(_children.find(word[idx]) == _children.end()) _children[word[idx]] = new Trie(idx);
        _children[word[idx]]->add(word, idx+1);
    }

    void print() {
        for(auto& c : _children) {
            for(int j = 0; j < c.second->depth; j++) cout << "--";
            cout << c.first << "\n";
            c.second->print();
        }
    }
};

Trie* root;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    root = new Trie();
    cin >> n;
    for(int i = 0; i < n; i++) {
        int t; cin >> t;
        vector<string> v;
        while(t--) {
            string str; cin >> str;
            v.push_back(str);
        }
        root->add(v, 0);
    }
    root->print();

    return 0;
}