#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int k;
vector<string> v;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    for(int tc = 1; tc <= T; tc++) {
        v.clear();
        cin >> k;
        string str; cin >> str;
        for(int i = 0; i < str.length(); i++) {
            string tmp = "";
            for(int j = i; j < str.length(); j++) {
                tmp += str[j];
                v.push_back(tmp);
            }
        }
        sort(v.begin(), v.end());
        if(k >= v.size()) {
            cout << "#" << tc << " none\n";
            continue;
        }
        unique(v.begin(),v.end());
        cout << "#" << tc << " " << v[k-1] << "\n";
    }

    return 0;
}