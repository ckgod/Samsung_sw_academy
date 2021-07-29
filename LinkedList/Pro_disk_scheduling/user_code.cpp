const int MAX = 100000;
#define MAXN (1 << 15) // Add 함수 초대 호출 수
#define MAXB (1 << 10) // 전체 bucket의 크기
#define DIV 10 // 개별 bucket에 들어가는 숫자 개수, 2^10개

struct Node{
    int val, idx;
    Node *prev;
    Node *next;

    Node *alloc(int _val, int _idx, Node *_prev, Node *_next) {
        this->val = _val;
        this->idx = _idx;
        this->prev = _prev;
        this->next = _next;

        if(next) {
            next->prev = this;
        }
        return this;
    }
} buf[MAXN], bucket[MAXB];

int bcnt, bucketCnt[MAXB];

void init();
void add(int data);
int remove(int index);
int access(int index);
Node *getNode(int index);

void init(int track_size, int head){
    // TO DO
}

void request(int track){
    add(track);
}

int fcfs(){
    int track_no = -1;	// TO DO : Need to be changed

    return track_no;
}

int sstf(){
    int track_no = -1;	// TO DO : Need to be changed

    return track_no;
}

int look(){
    int track_no = -1;	// TO DO : Need to be changed

    return track_no;
}

int clook(){
    int track_no = -1;	// TO DO : Need to be changed

    return track_no;
}


void initBucket() {
    bcnt = 0;
    for(int i = 0; i < MAXB; i++) {
        bucketCnt[i] = 0;
        bucket[i].next = 0; // head->next --> null
    }
}

Node *getNode(int index) {
    int sum = 0, i = 0;
    // bucket cnt의 누적합 -> index --> break;
    while(sum + bucketCnt[i] < index) {
        sum += bucketCnt[i];
        i++;
    }
    // bucket[i]는 index 번째 숫자가 존재하는 Linked List
    // bucket[i](head) --> node_1 --> node_2 --> ... --> null
    Node *ptr = &bucket[i];
    while(ptr->next) {
        sum++;
        ptr = ptr->next;
        if(index == sum) break;
    }
    return ptr;
}

void add(int data) {
    Node *ptr;
    int index = data >> DIV;
    ptr = &bucket[index];
    bucketCnt[index]++;

    while(ptr -> next) {
        if(ptr -> next ->val >= data) break;
        ptr = ptr->next;
    }
    ptr->next = buf[bcnt++].alloc(data,index,ptr,ptr->next);
}

int remove(int index) {
    Node *ptr = getNode(index + 1);
    ptr->prev->next = ptr->next;
    if(ptr->next) ptr->next->prev = ptr->prev;
    bucketCnt[ptr->idx]--;
    return ptr->val;
}

int access(int index) {
    Node *ptr = getNode(index + 1);
    return ptr->val;
}

