#include <iostream>
using namespace std;
#define MAX_N 10000

struct Queue {
    int a[MAX_N];
    int f, b;

    void clear() { f = b = 0; }
    void push(int x) { a[b++] = x; }
    void pop() { f++; }
    int front() { return a[f]; }
    int back() { return a[b - 1]; }
    int size() { return b - f; }
};

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);


    return 0;
}