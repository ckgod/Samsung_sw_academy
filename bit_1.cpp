#include <iostream>
using namespace std;
int N;
int main(int argc, char **argv) {
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        cin >> N;
        unsigned int count = 0;
        int saveN = N;
        int mul = 2;
        bool end = false;
        int ans = 1;
        while(!end) {
            while (N) {
                int num = N % 10;
                N /= 10;
                count = count | (1 << num);
            }
            if(count == (1 << 10) - 1) {
                end = true;
            }
            else {
                N = saveN * mul;
                mul++;
                ans = N;
            }
        }
        cout << "#" << test_case << " " << ans << "\n";
    }
    return 0;
}