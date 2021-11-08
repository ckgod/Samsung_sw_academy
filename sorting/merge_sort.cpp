#include <iostream>
using namespace std;
#define MAXN 1000000
// Merge Sort
int A[MAXN + 10];
int sorted[MAXN + 10];

void merge(int left, int mid, int right) {
    int leftArrIdx, rightArrIdx, sortedArrIdx;
    leftArrIdx = left;
    rightArrIdx = mid+1;
    sortedArrIdx = left;

    while(leftArrIdx <= mid && rightArrIdx <= right) { // 쪼개진 왼쪽 배열과 오른쪽 배열을 비교하면서 정렬
        if(A[leftArrIdx] <= A[rightArrIdx]) {
            sorted[sortedArrIdx++] = A[leftArrIdx++];
        }
        else {
            sorted[sortedArrIdx++] = A[rightArrIdx++];
        }
    }
    if(leftArrIdx > mid) { // 아직 정렬되지 않은 애들 넣어주기
        while(rightArrIdx <= right) {
            sorted[sortedArrIdx++] = A[rightArrIdx++];
        }
    }
    else {
        while(leftArrIdx <= mid) {
            sorted[sortedArrIdx++] = A[leftArrIdx++];
        }
    }
    for(int i = left; i <= right; i++) { // 원래 배열에 복사
        A[i] = sorted[i];
    }
}

void mergeSort(int l, int r) { // 배열을 반씩 계속 쪼개줌
    int m;
    if(l < r) {
        m = (l + r) / 2;
        mergeSort(l,m);
        mergeSort(m+1, r);
        merge(l,m,r); // 쪼개진걸 합침
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