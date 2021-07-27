#include <iostream>
using namespace std;
#define MAXN 1000000

int arr[MAXN + 10];

void qsort(int l, int r) {
    int s = l; int e = r;
    int pivot = arr[(l+r)/2];

    if(l >= r) return;
    while(s <= e) {
        while(arr[s] < pivot) s++;
        while(arr[e] > pivot) e--;
        if(s <= e) {
            int temp = arr[s];
            arr[s] = arr[e];
            arr[e] = temp;
            s++; e--;
        }
    }
    qsort(l,e);
    qsort(s,r);
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    qsort(0,n-1);
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}