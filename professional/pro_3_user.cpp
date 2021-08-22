#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;


void mstrcpy(char dst[], const char src[]) {
	int c = 0;
	while ((dst[c] = src[c]) != 0) ++c;
}

int mstrcmp(const char str1[], const char str2[]) {
	int c = 0;
	while (str1[c] != 0 && str1[c] == str2[c]) ++c;
	return str1[c] - str2[c];
}

struct Pair{
    char event[16];
    int gid;
};

char eventName[100][200][16];
int eventUid[100][200][5];
Pair userEvent[1000][100];

void init() {
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 200; j++) {
            eventName[i][j][0] = '\0';
        }
    }
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 200; j++) {
            for(int k = 0; k < 5; k++) {
                eventUid[i][j][k] = -1;
            }
        }
    }
    for(int i = 0; i < 1000; i++) {
        for(int j = 0; j < 100; j++) {
            userEvent[i][j].event[0] = '\0';
            userEvent[i][j].gid = -1;
        }
    }


}

void addEvent(int uid, char ename[], int groupid) {

}

int deleteEvent(int uid, char ename[]) {
    return 0;
}

int changeEvent(int uid, char ename[], char cname[]) {
    return 0;
}

int getCount(int uid) {
    return 0;
}