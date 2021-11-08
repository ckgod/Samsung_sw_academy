#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(string s1, string s2) {
    if(s1.length() != s2.length()) return s1.length() < s2.length();
    else return s1 < s2;
}

vector<string> v;
vector<string> ans;
int n;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    for(int tc = 1; tc <= T; tc++) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            string str; cin >> str;
            v.push_back(str);
        }
//        sort(v.begin(), v.end());
        sort(v.begin(), v.end(), comp);
        string prev = v[0];
        ans.push_back(prev);
        for(int i = 1; i < v.size(); i++) {
            if(v[i] != prev) {
                ans.push_back(v[i]);
                prev = v[i];
            }
        }
        cout << "#" << tc << "\n";
        for(auto i : ans) {
            cout << i << "\n";
        }
        v.clear(); ans.clear();
    }

    return 0;
}