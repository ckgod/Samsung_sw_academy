#include <iostream>
#include <algorithm>

using namespace std;
#define INF 1231212412
int arr[10001];

void insertion_sort(int s, int e) {
    for(int startIdx = s + 1; startIdx < e; startIdx++) {
        int key = arr[startIdx];
        for(int curIdx = startIdx - 1; curIdx >= s; curIdx--) {
            if(arr[curIdx] > key) {
                swap(arr[curIdx], arr[curIdx + 1]);
            }
            else break;
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    for (int i = 101; i >= 0; i--) {
        arr[i] = 101 - i;
    }
    for (int i = 0; i < 102; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    // TODO : sort
    insertion_sort(10, 30);

    for (int i = 0; i < 102; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}