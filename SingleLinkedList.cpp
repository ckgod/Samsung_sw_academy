#include <iostream>
using namespace std;
#define MAXN 1000

struct ListNode {
    int idx = -1; // list 의 key
    int data; // list 에 담긴 data
    ListNode* next; // 다음 node

    // 구조체 변수를 초기화하고 해당 변수의 주소를 반환
    ListNode* myAlloc(int _idx, int _data, ListNode* _next) {
        idx = _idx;
        data = _data;
        next = _next;
        return this; // 현재 구조체 변수의 주소 반환
    }
} buffer[MAXN];

int bufferCnt = 0; // Memory Pool

//ListNode *list;
ListNode head, tail;
// 리스트의 시작과 끝에 dummy 변수인 head 와 tail 을 둠
// 연결 리스트 순회가 늘 head->next 부터 tail 내에 이뤄지게 한다.
// segmentation fault 발생 방지

void init() {
    bufferCnt = 0;
    head.next = &tail;
}

ListNode* getNode(int _idx) {
    ListNode* ptr = &head;

    while(ptr->next) { // ptr->next 가 null 이 아니라면
        if(ptr->next->idx == _idx || ptr->next->idx == -1) break; // 동일한 idx를 발견하면 loop 종료
        ptr = ptr -> next; // ptr 은 다음 node 를 가리킨다.
    }

    // while loop 에서 ptr->next 를 쓰는 이유
    // 1. single linked list 는 이전 노드의 정보를 알 방법이 없다. 따라서 node 연결의 수정, 삭제가 필요한 경우 해당 node의 이전 node에서
    // 작업이 이뤄져야 한다.
    // 2. 다음 node가 null일 경우 loop를 끝내기 위함

    return ptr;
}

void update(ListNode* ptr, int _data) {
    ptr->next->data = _data;
    return;
}

void remove(ListNode* ptr) {
    ptr->next = ptr->next->next;
}

int main() {
    init();

    for(int i = 0; i < 10; i++) { // node 추가
        int idx, data;
        cin >> idx >> data;
        ListNode* ptr = getNode(idx);
        ptr->next = buffer[bufferCnt++].myAlloc(idx,data,ptr->next);
    }
    for(int i = 0; i < 10; i++) {
        int idx, newData;
        cin >> idx >> newData;
        ListNode* ptr = getNode(idx);
        if(ptr->next->idx == idx && ptr->next->idx != -1) update(ptr, newData);
    }
    for(int i = 0; i < 10; i++) {
        int idx;
        cin >> idx;
        ListNode* ptr = getNode(idx);
        if(ptr->next->idx == idx && ptr->next->idx != -1) remove(ptr);
    }

    return 0;
}