#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

typedef enum {
    INIT,
    ADD,
    DELETE,
    CHANGE,
    GETCOUNT
} COMMAND;

extern void init();

extern void addEvent(int uid, char ename[], int groupid);

extern int deleteEvent(int uid, char ename[]);

extern int changeEvent(int uid, char ename[], char cname[]);

extern int getCount(int uid);

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

static int mSeed;

static int pseudo_rand(void) {
    mSeed = mSeed * 431345 + 2531999;
    return mSeed & 0x7FFFFFFF;
}

static void make_string(char str[], int seed) {
    mSeed = seed;
    int length = 5 + pseudo_rand() % 10;
    for (int i = 0; i < length; ++i) {
        str[i] = 'a' + pseudo_rand() % 26;
    }
    str[length] = 0;
}

static int run() {
    int answer = 100;

    int cmd, p1, p2, p3, p4;
    char str1[15], str2[15];

    int N, ret, flag;
    scanf("%d %d %d", &cmd, &N, &flag);

    init();

    for (int i = 1; i < N; ++i) {
        scanf("%d", &cmd);
        switch (cmd) {
            case ADD:
                if (flag == 1) {
                    scanf("%d %s %d", &p1, str1, &p3);
                } else {
                    scanf("%d %d %d", &p1, &p2, &p3);
                    make_string(str1, p2);
                }
                addEvent(p1, str1, p3);
                break;

            case DELETE:
                if (flag == 1) {
                    scanf("%d %s %d", &p1, str1, &p3);
                } else {
                    scanf("%d %d %d", &p1, &p2, &p3);
                    make_string(str1, p2);
                }
                ret = deleteEvent(p1, str1);
                if (ret != p3)
                    answer = 0;
                break;

            case CHANGE:
                if (flag == 1) {
                    scanf("%d %s %s %d", &p1, str1, str2, &p4);
                } else {
                    scanf("%d %d %d %d", &p1, &p2, &p3, &p4);
                    make_string(str1, p2);
                    make_string(str2, p3);
                }
                ret = changeEvent(p1, str1, str2);
                if (ret != p4)
                    answer = 0;
                break;

            case GETCOUNT:
                scanf("%d %d", &p1, &p2);
                ret = getCount(p1);
                if (ret != p2)
                    answer = 0;
                break;

            default:
                break;
        }
    }

    return answer;
}

int main() {
    setbuf(stdout, NULL);
    //freopen("sample_input.txt", "r", stdin);

    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        printf("#%d %d\n", tc, run());
    }

    return 0;
}