#include <iostream
using namespace std;

int memPoolCnt;

struct Node {
    int value;
    Node* prev;
} node[50000];

struct User {
    Node* data;
} user[100000];

int main() {
    // 첫 번째 데이터 추가
    Node* tmp1 = &node[memPoolCnt++]; // 메모리 풀에서 가져옴
    tmp1 -> value = 1;
    tmp1 -> prev = user[0].data;
    user[0].data = tmp1;

    // 두 번째 데이터 추가
    Node* tmp2 = &node[memPoolCnt++]; // 메모리 풀에서 가져옴
    tmp2 -> value = 2;
    tmp2 -> prev = user[0].data;
    user[0].data = tmp2;

    return 0;
}