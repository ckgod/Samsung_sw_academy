#define ALPHABET_CNT 26
#define MAXN 1000000

struct Trie;
Trie* myAlloc();

struct Trie {
    Trie* _children[ALPHABET_CNT];
    bool lastLetter = false;
    int childCnt = 0;

    void add(const char* word) {
        childCnt++;
        if(*word == 0) {
            lastLetter = true;
            return;
        }
        if(_children[*word -'a'] == nullptr) _children[*word - 'a'] = myAlloc();
        _children[*word - 'a']->add(word+1);
    }

    Trie *get(const char *word) {
        if (*word != 0) {
            if (_children[*word - 'a'] != nullptr) return _children[*word - 'a']->get(word + 1);
            return nullptr;
        }
        return this;
    }

    int getChildCnt(const char* word) {
        if(*word == 0) return childCnt;
        else {
            if(_children[*word -'a'] != nullptr) return _children[*word -'a']->getChildCnt(word+1);
            return 0;
        }
    }

    void clear() {
        for(int i = 0; i < ALPHABET_CNT; i++) {
            _children[i] = nullptr;
        }
    }
};

int nodeCnt = 0;
Trie Node[MAXN];
Trie* root;

Trie* myAlloc() {
    Trie* ret = &Node[nodeCnt++];
    ret->lastLetter = 0;
    ret->childCnt = 0;
    ret->clear();
    return ret;
}


void init(void) {
    nodeCnt = 0;
    root = myAlloc();
}

void insert(int buffer_size, char *buf) {
    root->add(buf);
}

int query(int buffer_size, char *buf) {
    int ret = root->getChildCnt(buf);
    return ret;
}