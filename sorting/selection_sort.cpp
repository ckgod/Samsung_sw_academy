#include <iostream>
#include <algorithm> // swap
using namespace std;
#define INF 1231212412
int arr[10001];

void selectionSort(int s, int e) {
    for(int startIdx = s; startIdx < e; startIdx++) {
        int curMin = arr[startIdx];
        int curMinIdx = startIdx;
        for(int curIdx = startIdx; curIdx < e; curIdx++) {
            if(curMin > arr[curIdx]) {
                curMin = arr[curIdx];
                curMinIdx = curIdx;
            }
        }
        swap(arr[curMinIdx], arr[startIdx]);
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    for(int i = 101; i >= 0; i--) {
        arr[i] = 101-i;
    }
    for(int i = 0; i < 102; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    selectionSort(0, 102);
    for(int i = 0; i < 102; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}