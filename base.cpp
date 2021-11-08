#include <iostream>
using namespace std;

// stack, queue, List, vector, quick sort, merge sort

struct Vector{
    int * a;
    int n, Capacity;
    Vector() {
        a = new int[Capacity = 2];
        n = 0;
    }
    void resize(int _Capacity) {
        int *b = a;
        a = new int[Capacity = _Capacity];
        for(int i = 0; i < n; i++) {
            a[i] = b[i];
        }
        delete[] a;
    }
    void push_back(int x) {
        a[n] = x;
        n++;
        if(n == Capacity) resize(Capacity << 1);
    }
    void pop_back() {
        n--;
        if(n == Capacity >> 2) resize(Capacity >> 1);
    }
};

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    return 0;
}