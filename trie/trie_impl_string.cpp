#include <string>
#include <iostream>
#include <vector>
using namespace std;

const int NUM_ALPHABETS = 26;
int toIndex(char ch) { return ch - 'a'; }

struct TrieNode {
    TrieNode* children[NUM_ALPHABETS];
    // unordered_map<string, TrieNode*> children;
    bool isEnd;

    TrieNode() : children(), isEnd(false) {}

    void Insert(string& key, int index) {
        if (index == key.length() - 1)
            isEnd = true;
        else {
            int next = toIndex(key[index]);
            if (children[next] == nullptr)
                children[next] = new TrieNode;
            children[next]->Insert(key, index + 1);
        }
    }

    bool Find_1(string& key, int depth) {   // 접두사로서 검색 되더라도 true 를 리턴하게끔 한 함수
        if (depth == key.length() - 1)
            return true;
        int next = toIndex(key[depth]);
        if (children[next] == nullptr)
            return false;
        return children[next]->Find_1(key, depth + 1);
    }

    bool Find_2(string& key, int depth) {  // 완전히 일치하는 단어 단위로만 찾고 true 를 리턴하게끔 한 함수
        if (depth == key.length() - 1 && isEnd)
            return true;
        if (depth == key.length() - 1 && !isEnd)
            return false;
        int next = toIndex(key[depth]);
        if (children[next] == nullptr)
            return false;
        return children[next]->Find_2(key, depth + 1);
    }
};

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    vector<string> words = { "what", "when", "yours", "apple", "her", "his", "you" };

    TrieNode root;
    for (string word : words)
        root.Insert(word, 0);

    string search = "wh";

    if (root.Find_1(search, 0)) cout << search << "가 검색 결과에 있습니다." << '\n';
    else cout << search << "가 검색 결과에 없습니다." << '\n';

    if (root.Find_2(search, 0)) cout << search << "가 검색 결과에 있습니다." << '\n';
    else cout << search << "가 검색 결과에 없습니다." << '\n';
    return 0;
}