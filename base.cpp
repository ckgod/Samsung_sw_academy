#include <iostream>
#include <cstring>
using namespace std;

char s[101];
int arr[26];
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    memset(arr, -1, sizeof(arr));
    cin >> s;

    for(int i = 0; i < strlen(s); i++) {
        if(arr[s[i] - 'a'] == -1) {
            arr[s[i] -'a'] = i;
        }
    }
    for(int i = 0; i < 26; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}