#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int n,m;
int parent[200001];
int groupSize[200001];

int find(int n) {
    if(parent[n] == n) return n;
    else return parent[n] = find(parent[n]);
}

void merge(int n1, int n2) {
    n1 = find(n1);
    n2 = find(n2);

}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a,b; cin >> a >> b;

    }


    return 0;
}