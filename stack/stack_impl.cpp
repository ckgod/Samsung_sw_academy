#include <iostream>
using namespace std;
#define MAX_N 10000

struct Stack {
    int a[MAX_N];
    int n;

    void clear() { n = 0; }
    void push(int x) { a[++n] = x; }
    void pop() { n--; }
    int top() { return a[n]; }
    int size() { return n; }
};


int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);


    return 0;
}