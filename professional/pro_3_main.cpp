#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <iostream>
using namespace std;
#define CMD_INIT 1
#define CMD_ACCESS 2
#define CMD_USAGE 3

static int run() {
    int q;
    cin >> q;

    int n, fileId, fileSize;
    int cmd, ans, ret = 0;
    bool okay = false;

    for (int i = 0; i < q; ++i) {
        cin >> cmd;
        switch (cmd) {
            case CMD_INIT:
                cin >> n;
                break;
            case CMD_ACCESS:
                cin >> fileId >> fileSize >> ans;
                break;
            case CMD_USAGE:
                cin >> ans;
                break;
            default:
                okay = false;
                break;
        }
    }
    return q;
}

int main() {
    setbuf(stdout, NULL);
    freopen("sample_25_input.txt", "r", stdin);

    int T, MARK;
    cin >> T >> MARK;

    for (int tc = 1; tc <= T; tc++) {
        int score = run();
        cout << "#" << tc << " " << score << "\n";
    }

    return 0;
}