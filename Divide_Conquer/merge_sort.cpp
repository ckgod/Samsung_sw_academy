#include <iostream>
using namespace std;
#define MAXN 1000000
// Merge Sort
int A[MAXN + 10];
int sorted[MAXN + 10];

void merge(int l, int m, int r) {
    int i,j,k;
    i = l; j = m+ 1; k =l;
    while(i <= m && j <= r) {
        if(A[i] <= A[j]) {
            sorted[k++] = A[i++];
        }
        else {
            sorted[k++] = A[j++];
        }
    }
    if(i > m) {
        while(j <= r) {
            sorted[k++] = A[j++];
        }
    }
    else {
        while(i <= m) {
            sorted[k++] = A[i++];
        }
    }
    for(i = l; i <= r; i++) {
        A[i] = sorted[i];
    }
}

void mergeSort(int l, int r) {
    int m;
    if(l < r) {
        m = (l + r) / 2;
        mergeSort(l,m);
        mergeSort(m+1, r);
        merge(l,m,r);
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }
    mergeSort(0, n-1);
    for(int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    return 0;
}