//void mstrcpy(char dst[], const char src[]) {
//	int c = 0;
//	while ((dst[c] = src[c]) != 0) ++c;
//}

//int mstrcmp(const char str1[], const char str2[]) {
//	int c = 0;
//	while (str1[c] != 0 && str1[c] == str2[c]) ++c;
//	return str1[c] - str2[c];
//}
#define ALPHABET_CNT 26
#define MAXN 100001

struct Trie;
Trie* tAlloc();

struct Node{
    int uid;
    int gid;
    Node* prev;
    Node* next;
} NodeMem[MAXN];

// 트라이 안에 그룹 배열

struct Trie{
    Trie* _children[ALPHABET_CNT];
    int isFinish;
    Node* group[100];

    void add(const char *word) {

    }

    void clear() {
        for(int i = 0; i < ALPHABET_CNT; i++) {
            _children[i] = nullptr;
        }
        for(int i = 0; i < 100; i++) {
            group[i] = nullptr;
        }
    }
};

int nodeCnt = 0;
Trie* tAlloc() {

}

void init() {
}

void addEvent(int uid, char ename[], int groupid) {
}

int deleteEvent(int uid, char ename[]) {
    return 0;
}

int changeEvent(int uid, char ename[], char cname[]) {
    return 0;
}

int getCount(int uid) {
    return 0;
}