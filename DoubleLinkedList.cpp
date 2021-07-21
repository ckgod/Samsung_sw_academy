#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <iostream>
using namespace std;


#define MAX_N 1000
#define MAX_M 20

struct Result {
    int y, x;
};

extern void init(int N, int M, int Map[MAX_N][MAX_N]);
extern Result findConstellation(int stars[MAX_M][MAX_M]);

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

static int mSeed;
static int pseudo_rand(void)
{
    mSeed = mSeed * 431345 + 2531999;
    return mSeed & 0x7FFFFFFF;
}

static int Map[MAX_N][MAX_N];
static int Stars[MAX_M][MAX_M];


//1 100
// test case , ans 입력
//15 5 5
// N, M, K 입력

//0
//1
//0
//24579
//1034
//0
//21520
//16384
//176
//464
//21616
//20488
//19456
//1024
//0
// 여기까지가 Map 입력

// 여기부터 별자리 기준별 좌표 입력
//301413356 5 4 3
//655243746 6 8 7
//597006 9 11 12
//511081305 6 9 7
//950090227 7 7 14

static int run(int Ans)
{
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    // 15 5 5 K가 별자리 개수

    for (int i = 0; i < N; ++i) {
        int num;
        int cnt = N / 30;
        int idx = 0;
        for (int k = 0; k < cnt; ++k) {
            scanf("%d", &num);
            for (int m = 0; m < 30; ++m) {
                Map[i][idx++] = num & 0x01;
                num = num >> 1;
            }
        }

        if (N % 30) {
            scanf("%d", &num);
            for (int m = 0; m < (N % 30); ++m) {
                Map[i][idx++] = num & 0x01;
                num = num >> 1;
            }
        }
    }

//    for(int i = 0; i < N; i++) {
//        for(int j = 0; j < N; j++) {
//            cout << Map[i][j] << " ";
//        }
//        cout << "\n";
//    }

    // ------ 여기까지 거치면 Map 생성완료 --------

    init(N, M, Map);

    for (int t = 0; t < K; ++t) {
        int num, sy, sx;
        // seed 는 난수 발생수 num은 별 개수 sy,sx는 기준별 좌표
        scanf("%d %d %d %d", &mSeed, &num, &sy, &sx);

        for (int i = 0; i < M; ++i)
            for (int k = 0; k < M; ++k)
                Stars[i][k] = 0;

        int y = pseudo_rand() % M;
        int x = pseudo_rand() % M;
        Stars[y][x] = 9;
        for (int i = 1; i < num; ++i) {
            y = pseudo_rand() % M;
            x = pseudo_rand() % M;
            Stars[y][x] = 1;
        }

//        for(int i = 0; i < M; i++) {
//            for(int j = 0; j < M; j++) {
//                cout << Stars[i][j] << " ";
//            }
//            cout << "\n";
//        } // 별자리가 입력되는거임

        // findConstellation 에 별자리를 넣으면 이 별자리의 기준별의 좌표가 Map에 어디있는지 찾아서 return 시켜야함
        Result answer = findConstellation(Stars);
        cout << answer.y << " " << answer.x << "\n";
        if ((answer.y != sy) || (answer.x != sx))
            Ans = 0;
    }

    return Ans;
}

int main()
{
    setbuf(stdout, NULL);
    //freopen("sample_input.txt", "r", stdin);

    int T, Ans;
    scanf("%d %d", &T, &Ans);

    for (int tc = 1; tc <= T; tc++) {
        printf("#%d %d\n", tc, run(Ans));
    }

    return 0;
}