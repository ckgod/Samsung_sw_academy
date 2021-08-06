//#include <iostream>
//using namespace std;

#define MAX_SIZE 100000

struct Pair{
    int val;
    int uId;

    bool operator<(const Pair p1) const {
        if(p1.val == this->val) return p1.uId > this->uId;
        else return p1.val < this->val;
    }
};

Pair heap[MAX_SIZE];
int heapSize = 0;

void heapInit() {
    heapSize = 0;
}

int heapPush(int value, int uId) {
    if (heapSize + 1 > MAX_SIZE) {
//        cout << "heap is full\n";
        return 0;
    }
    heap[heapSize].val = value; // 마지막 노드에 값 추가
    heap[heapSize].uId = uId;
    // 마지막 노드에 추가한 값을 올바른 위치로 옮긴다.
    int current = heapSize;
    while (current > 0 && heap[current] < heap[(current - 1) / 2]) { // 부모와 자식의 우선순위 비교
        // 자식의 우선순위가 더 높으면 부모와 값을 바꿔준다.
        Pair temp = heap[(current - 1) / 2];
        heap[(current - 1) / 2] = heap[current];
        heap[current] = temp;
        current = (current - 1) / 2;
    }
    heapSize = heapSize + 1;
    return 1;
}

Pair heapPop() {
    if (heapSize <= 0) {
        Pair tmp = {-1,-1};
        return tmp;
    }
    Pair value = heap[0];
    heapSize = heapSize - 1;
    heap[0] = heap[heapSize]; // 마지막 data를 root에 저장
    // root에 저장된 값을 올바른 위치로 옮긴다.
    int current = 0;
    while (current * 2 + 1 < heapSize) {
        int child;
        if (current * 2 + 2 == heapSize)
            child = current * 2 + 1;
        else
            child = heap[current * 2 + 1] < heap[current * 2 + 2] ? current * 2 + 1 : current * 2 + 2;

        if (heap[current] < heap[child]) break;

        Pair temp = heap[current];
        heap[current] = heap[child];
        heap[child] = temp;
        current = child;
    }
    return value;
}

void init() {
    heapInit();
}

void addUser(int uID, int income) {
    heapPush(income,uID);
}

int getTop10(int result[10]) {
    int ret = 0;
    Pair temp[10];
    for(int i = 0; i < 10; i++) {
        temp[ret] = heapPop();
        if(temp[ret].uId == -1) break;
        result[i] = temp[ret].uId;
        ret++;
//        cout << "result["  << i << "] : " << result[i] << ", " << temp[ret-1].val << "\n";
    }
    for(int i = 0; i < ret; i++) {
        heapPush(temp[i].val, temp[i].uId);
    }
//    cout << "ret : " << ret << "\n";
    return ret;
}