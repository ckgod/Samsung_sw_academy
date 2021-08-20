#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int sum = 0;
struct Trie {
    Trie* _children[26];
    int child;
    bool isFinish = false;

    Trie() {
        for (int i = 0; i < 26; i++) _children[i] = nullptr;
        child = 0;
        isFinish = false;
    }
    ~Trie() {
        for (int i = 0; i < 26; i++) if (_children[i]) delete _children[i];
    }

    void add(const char* word) {
        if (!*word) {
            isFinish = true;
            return;
        }
        if (_children[*word - 'a'] == nullptr) {
            _children[*word - 'a'] = new Trie();
            child++;
        }
        _children[*word - 'a']->add(word + 1);
    }

    void search(const char* word, int p, bool root) {
        if (!*word) {
            sum += p;
            return;
        }
        if (root) _children[*word - 'a']->search(word + 1, p, false);
        else {
            if (child == 1 && !isFinish) _children[*word - 'a']->search(word + 1, p, false);
            else _children[*word - 'a']->search(word + 1, p + 1, false);
        }
    }
};

Trie* root;
vector<string> v;

void init() {
    root = new Trie();
    v.clear();
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    while (cin >> n) {
        init();
        for (int i = 0; i < n; i++) {
            string str; cin >> str;
            root->add(str.c_str());
            v.push_back(str);
        }
        sum = 0;
        for (auto s : v) {
            root->search(s.c_str(), 1, true);
        }
        cout << fixed;
        cout.precision(2);
        cout << (double)sum / v.size() << '\n';
        delete root;
    }
    return 0;
}