#include <iostream>
#define MAX_STRING    1000000
#define MAX_WORD    1000

using namespace std;

char S[MAX_STRING + 1];
char W[MAX_WORD + 1];
int fail[MAX_WORD];
int result[MAX_WORD];
int N, M, R;

void getFailFunc() {
    M = 0;
    while (W[M]) M++;

    for (int i = 1, j = 0; i < M; i++) {
        while (j > 0 && W[i] != W[j]) j = fail[j - 1];

        if (W[i] == W[j]) {
            fail[i] = ++j;
        } else {
            fail[i] = 0;
        }
    }
}

void KMP() {
    getFailFunc();
    N = 0, R = 0;
    for (int i = 0; i < MAX_WORD; i++) result[i] = 0;
    while (S[N]) N++;

    for (int i = 1, j = 0; i < N; i++) {
        while (j > 0 && S[i] != W[j]) j = fail[j - 1];

        if (S[i] == W[j]) {
            if (j == M - 1) {
                result[R++] = i - M + 1;
                j = fail[j];
            } else j++;
        } else j = 0;
    }
}

int m_strcmp(const char *str1, const char *str2) {
    int i = 0, j = 0;

    while (str1[i] != '\0' || str2[j] != '\0') {
        if (str1[i] != str2[j]) return str1[i] - str2[j];
        else {
            i++;
            j++;
        }
    }

    return 0;
}

int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> S;

    while (true) {
        cin >> W;
        if (!m_strcmp(W, "q")) break;

        KMP();
        if (R == 0) cout << W << " 는 없는 단어입니다.\n";
        else
            for (int i = 0; i < R; i++) {
                cout << result[i] + 1 << "번째 위치에서 발견하였습니다.\n";
            }
    }

    return 0;
}