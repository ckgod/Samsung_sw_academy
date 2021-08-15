#define MAX_NODE 111000
#define HASH_SIZE (1 << 18)
#define INF 109299

unsigned long djb2(const char *str) {
    unsigned long hash = 0;
    int c;
    while (c = *str++) {
        hash = (((hash << 5) + hash) + (c - 'a' + 1));
    }
    return hash % HASH_SIZE;
}

struct Node {
    int data;
    int myIndex;
    Node *next;
    Node *prev;
} indexList[MAX_NODE];


struct Ind {
    Node *head;
    Node *tail;
};

int nodeCnt;
Ind ind[HASH_SIZE];

Node *getNode(int data) {
    indexList[nodeCnt].data = data;
    indexList[nodeCnt].next = nullptr;
    indexList[nodeCnt].prev = nullptr;
    indexList[nodeCnt].myIndex = nodeCnt;
    return &indexList[nodeCnt++];
}

void push_back_list(int idx, int data) {
    Node *ptr = ind[idx].head->next;
    while (ptr != ind[idx].tail) {
        if (ptr->data > data) break;
        ptr = ptr->next;
    }
    Node *newNode = getNode(data);
    newNode->next = ptr;
    newNode->prev = ptr->prev;
    newNode->prev->next = newNode;
    ptr->prev = newNode;
}

void push_back_node(int idx, Node* node) {
    Node *ptr = ind[idx].head->next;
    while (ptr != ind[idx].tail) {
        if (ptr->data > node->data) break;
        ptr = ptr->next;
    }
    node->next = ptr;
    node->prev = ptr->prev;
    node->prev->next = node;
    ptr->prev = node;
}

void init_push_list(int idx, int data) {
    Node *newNode = getNode(data);
    newNode->prev = ind[idx].tail->prev;
    ind[idx].tail->prev->next = newNode;
    newNode->next = ind[idx].tail;
    ind[idx].tail->prev = newNode;
}

void removeNode(int idx, int data) {
    Node *ptr = ind[idx].head->next;
    while (ptr != ind[idx].tail) {
        if (ptr->data == data) break;
        ptr = ptr->next;
    }
    if (ptr == ind[idx].tail) return;
    ptr->next->prev = ptr->prev;
    ptr->prev->next = ptr->next;
}

Node* returnNode(int idx, int data) {
    Node *ptr = ind[idx].head->next;
    while (ptr != ind[idx].tail) {
        if (ptr->data == data) break;
        ptr = ptr->next;
    }
    if (ptr == ind[idx].tail) return nullptr;
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    return ptr;
}

void mstrcpy(char dst[], const char src[]);

int mstrlen(const char str[]);

int mstrcmp(const char str1[], const char str2[]);

char input_string[50001];
int saveIndex[50001];
int memPoolIdx[50001];
int n;

void init(int N, char init_string[]) {
    nodeCnt = 0;
    for (int i = 0; i < 30000; i++) {
        ind[i].head = getNode(-1);
        ind[i].tail = getNode(INF);
        ind[i].head->next = ind[i].tail;
        ind[i].tail->prev = ind[i].head;
    }
    n = N;
    mstrcpy(input_string, init_string);
    for (int i = 0; i < N - 2; i++) { // 해쉬 리스트 세팅
        char key[4] = {0,};
        key[0] = input_string[i];
        key[1] = input_string[i + 1];
        key[2] = input_string[i + 2];
        int index = djb2(key);
        init_push_list(index, i);
    }
}

int change(char string_A[], char string_B[]) {
//    cout << "\n---- call Change ----\n";
    int ret = 0;
    int keyA = djb2(string_A);
//    cout << "string B : " << string_B << "\n";
//    cout << "string A : " << string_A << "\n";

    Node *ptr = ind[keyA].head->next;
    int sIdx = 0;
    while (ptr != ind[keyA].tail) {
//            cout << ptr->next->data << " ";
        saveIndex[sIdx] = ptr->data;
        memPoolIdx[sIdx] = ptr->myIndex;
        sIdx++;
        ptr = ptr->next;
    }

//    cout << "\n";
    int prevIdx = 0;
    prevIdx = saveIndex[0];

    bool firstTry = true;
    for (int i = 0; i < sIdx; i++) {
//            cout << saveIndex[i] << " ";
        int index = saveIndex[i];
        if (index < prevIdx + 3 && !firstTry) {
            continue;
        }
        firstTry = false;
        prevIdx = index;
        ret++;
//            cout << "string A exist index : " << index << "\n";
//            cout << "prev string : " << input_string << "\n";
        Node* tmpNodeList[5];
        int tIdx= 0;
        for (int i = index - 2; i <= index + 2; i++) {
            if (i < 0 || i > n - 3) continue;
            char key[4] = {0,};
            key[0] = input_string[i];
            key[1] = input_string[i + 1];
            key[2] = input_string[i + 2];
            int tmpKey = djb2(key);
            tmpNodeList[tIdx++] = returnNode(tmpKey, i);
        }
        input_string[index] = string_B[0];
        input_string[index + 1] = string_B[1];
        input_string[index + 2] = string_B[2];
        tIdx = 0;
        for (int i = index - 2; i <= index + 2; i++) {
            if (i < 0 || i > n - 3) continue;
            char key[4] = {0,};
            key[0] = input_string[i];
            key[1] = input_string[i + 1];
            key[2] = input_string[i + 2];
            int tmpKey = djb2(key);
            push_back_node(tmpKey,tmpNodeList[tIdx++]);
        }
//            cout << "convert complete : " << input_string << "\n";
    }
//        cout << "\n";


    return ret;
}

void result(char ret[]) {
    mstrcpy(ret, input_string);
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
