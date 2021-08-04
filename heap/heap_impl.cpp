#include <iostream>
#include <stdlib.h>
using namespace std;

#define MAX_SIZE 100

int heap[MAX_SIZE];
int heapSize = 0;

void heapInit() {
    heapSize = 0;
}

int heapPush(int value) {
    if(heapSize + 1 > MAX_SIZE) {
        cout << "heap is full\n";
        return 0;
    }
    heap[heapSize] = value; // 마지막 노드에 값 추가
    // 마지막 노드에 추가한 값을 올바른 위치로 옮긴다.
    int current = heapSize;
    while(current > 0 && heap[current] < heap[(current - 1) / 2]) { // 부모와 자식의 우선순위 비교
        // 자식의 우선순위가 더 높으면 부모와 값을 바꿔준다.
        int temp = heap[(current - 1) / 2];
        heap[(current - 1) / 2] = heap[current];
        heap[current] = temp;
        current = (current - 1) / 2;
    }
    heapSize = heapSize + 1;
    return 1;
}

int heapPop() {
    if(heapSize <= 0) {
        return -1;
    }
    int value = heap[9];
    heapSize = heapSize - 1;
    heap[0] = heap[heapSize]; // 마지막 data를 root에 저장
    // root에 저장된 값을 올바른 위치로 옮긴다.
    int current = 0;
    while(current * 2 + 1 < heapSize) {
        int child;
        if(current * 2 + 2 == heapSize) child = current * 2 + 1;
        else child = heap[current * 2 + 1] < heap[current * 2 + 1] ? current * 2 + 1 : current * 2 + 2;

        if(heap[current] < heap[child]) break;

        int temp = heap[current];
        heap[current] = heap[child];
        heap[child] = temp;
        current = child;
    }
    return value;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    srand(11);
    heapInit();
    for(int i = 0; i < 100; i++) {
        heapPush(rand() % 100);
    }

    for(int i = 0; i < 100; i++) {
        cout << heapPop() << " ";
    }

}