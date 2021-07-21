#define N 4
#define MAX 10000
#define NUMBER_CNT 5040

//#include <iostream>
//using namespace std;

typedef struct {
    int hit;
    int miss;
} Result;
// API
extern Result query(int guess[]);

bool check[MAX]; // 최대 숫자 9876
int used_number[NUMBER_CNT];
bool check_init = true;
int idx = 0;

void init(){
    if(check_init) {
        check_init = false;
        // 중복안되는 4자리 세팅
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                if(j == i) continue;
                for(int k = 0; k < 10; k++) {
                    if(i == k || j == k) continue;
                    for(int p = 0; p < 10; p++) {
                        if(i == p || j == p || k == p) continue;
                        used_number[idx] = i*1000 + j*100 + k*10 + p;
//                        cout << used_number[idx] << "\n";
                        idx++;
                    }
                }
            }
        }
    }
    for(int i = 0; i < idx; i++) {
        check[used_number[i]] = true;
    }
}

Result filtering(int failNum, int filteredNum) {
    Result ret = {0,0};
    int a[4], b[4];
    a[0] = failNum / 1000;
    a[1] = (failNum % 1000) / 100;
    a[2] = (failNum % 100) / 10;
    a[3] = (failNum % 10);
    b[0] = filteredNum / 1000;
    b[1] = (filteredNum % 1000) / 100;
    b[2] = (filteredNum % 100) / 10;
    b[3] = (filteredNum % 10);

    if(a[0] == b[0]) ret.hit++;
    if(a[1] == b[1]) ret.hit++;
    if(a[2] == b[2]) ret.hit++;
    if(a[3] == b[3]) ret.hit++;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(i == j) continue;
            if(b[i] == a[j]) ret.miss++;
        }
    }
    return ret;
}

void doUserImplementation(int guess[]) {
    init();

    // Implement a user's implementation function
    //
    // The array of guess[] is a return array that
    // is your guess for what digits[] would be.

    while(true) {
        int tmp = 0;
        for(int i = 0; i < NUMBER_CNT; i++) {
            if(check[used_number[i]]) {
                tmp = used_number[i];
                guess[0] = tmp / 1000;
                guess[1] = (tmp % 1000) / 100;
                guess[2] = (tmp % 100) / 10;
                guess[3] = (tmp % 10);
                break;
            }
        }
        Result query_resultA = query(guess);
        if(query_resultA.hit == 4) break;
        else check[tmp] = false;

        for(int i = 0; i < NUMBER_CNT; i++) {
            if(check[used_number[i]]) {
                int filtered = used_number[i];
                Result query_resultB = filtering(tmp, filtered);
                if(query_resultA.hit != query_resultB.hit) {
                    check[filtered] = false;
                }
                else if(query_resultA.miss != query_resultB.miss) {
                    check[filtered] = false;
                }
            }
        }
    }

}