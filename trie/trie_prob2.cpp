#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

int k; string str;
vector<string> v;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    for(int tc = 1; tc <= T; tc++) {
        cin >> k;
        cin >> str;
        string tmp = "";
        for(int i = str.length()-1; i >= 0; i--) {
            tmp = str[i] + tmp;
            v.push_back(tmp);
        }
        sort(v.begin(), v.end());
        cout << "#" << tc << " " << v[k-1] << "\n";
        v.clear();
    }


    return 0;
}