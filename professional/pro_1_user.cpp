#define ALPHABET_CNT 26
#define MAXN 500001 // 글자수 50 * 종류 25000개

struct Trie;
Trie *tAlloc();
void mstrcpy(char dst[], const char src[]);
int mstrlen(const char str[]);
int mstrcmp(const char str1[], const char str2[]);

struct Trie {
    Trie *_children[ALPHABET_CNT];
    int child;
    char parent;
    bool finish;
    int callCnt;
    bool banned;

    void add(const char *word, char _parent) {
        child++;
        this->parent = _parent;
        if (*word == 0) {
            finish = true;
            callCnt++;
            return;
        }
        if (_children[*word - 'a'] == nullptr) _children[*word - 'a'] = tAlloc();
        _children[*word - 'a']->add(word + 1, *word);
    }

    void ban(const char *word) {
        //child++;
        if (*word == 0) {
            finish = true;
            banned = false;
            return;
        }
        if (_children[*word - 'a'] == nullptr) _children[*word - 'a'] = tAlloc();
        _children[*word - 'a']->ban(word + 1);
    }

    Trie *get(const char *word) {
        if (*word != 0) {
            if (_children[*word - 'a'] != nullptr) return _children[*word - 'a']->get(word + 1);
            return nullptr;
        }
        return this;
    }

    char saveWord[20];

    bool search(const char *word) {
        if (*word != 0) {
            if (_children[*word - 'a'] != nullptr) return _children[*word - 'a']->search(word + 1);
            return false;
        }
        return true;
    }

    void save(char c, int idx) {
        saveWord[idx] = c;
        for(int i = 0; i < ALPHABET_CNT; i++) {
            if(_children[i] != nullptr) {
                _children[i]->save(i+'a', idx+1);
            }
        }
    }

    void clear() {
        for (int i = 0; i < ALPHABET_CNT; i++) {
            _children[i] = nullptr;
        }
    }

    void init() {
        child = 0;
        finish = false;
        banned = false;
        parent = '-';
        callCnt = 0;
        saveWord[0] = {0,};
    }
};

int nodeCnt = 0;
Trie Node[MAXN];
Trie *root;

Trie *tAlloc() {
    Trie *newNode = &Node[nodeCnt++];
    newNode->clear();
    newNode->init();
}

void init() {
    nodeCnt = 0;
    root = tAlloc();
}

void inputWord(char mWord[20]) {
    root->add(mWord,'-');
}

int recommend(char mUser[20], char mAnswer[20]) {
    mstrcpy(mAnswer, mUser);
    Trie* tmp = root->get(mUser);
    if(tmp) { // 이걸로 시작단어가 있을때
        return mstrlen(mAnswer);
    }
    else { // 시작 단어가 없을때
        return mstrlen(mUser);
    }
}

void banWord(char mWord[20]) {
    root->ban(mWord);
}

void mstrcpy(char dst[], const char src[]) {
    int c = 0;
    while ((dst[c] = src[c]) != 0)
        ++c;
}

int mstrlen(const char str[]) {
    int ret = 0;
    while (str[ret])
        ++ret;
    return ret;
}

int mstrcmp(const char str1[], const char str2[]) {
    int c = 0;
    while (str1[c] != 0 && str1[c] == str2[c])
        ++c;
    return str1[c] - str2[c];
}