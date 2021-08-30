//#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;
#define MAXN 51000
#define EMPTY -100
#define HEADTAIL -200

struct Node{
    Node* prev;
    Node* next;
    int fileId;
    int fileSize;
    int address;
    Node* alloc(Node* _p = 0, Node*_n = 0, int _v = HEADTAIL, int _fs = 0, int _add = 0) {
        prev = _p;
        next = _n;
        fileId = _v;
        fileSize = _fs;
        address = _add;
        return this;
    }
};

int nodeCnt = 0;
Node node[MAXN];

struct List{
    Node* head;
    Node* tail;
    int sz;
    int usage;
    unordered_map<int,int> fileIdx;

    void clear() {
        head = node[nodeCnt++].alloc();
        tail = node[nodeCnt++].alloc(head);
        head->next = tail;
        sz = 0;
        usage = 0;
        fileIdx.clear();
    }
    Node *insert(Node* pos, int x, int fileSize, int add) {
        sz++;
        return pos->prev = pos->prev->next = node[nodeCnt++].alloc(pos->prev, pos, x, fileSize, add);
    }

    int size() {return sz;}
    int getUse() {return usage;}
    Node* begin() {return head->next;}
    Node* end() {return tail;}
    void push_front(int x, int fileSize, int add) {insert(head->next, x, fileSize, add);}

    bool fileExist(int fileId) {
        if(fileIdx.find(fileId) == fileIdx.end()) return false;
        else return true;
    }
    void addFileMap(int fileId, int idx) {
        fileIdx[fileId] = idx;
    }
    void removeFile(int fileId) {
        for(Node* it = head->next; it != tail; it = it->next) {
            if(it->fileId == fileId) {
                usage -= it->fileSize;
                if (it->prev->fileId == EMPTY && it->next->fileId == EMPTY) {
                    Node* empty = it->prev;
                    empty->fileSize += it->fileSize + it->next->fileSize;
                    empty->next = it->next->next;
                    it->next->next->prev = empty;
                    break;
                }
                else if(it->prev->fileId == EMPTY && it->next->fileId != EMPTY) {
                    Node* empty = it->prev;
                    Node* tmp = it;
                    empty->fileSize += it->fileSize;
                    empty->next = tmp->next;
                    tmp->next->prev = empty;
                    break;
                }
                else if(it->prev->fileId != EMPTY && it->next->fileId == EMPTY) {
                    Node* empty = it;
                    Node* tmp = it->next;
                    empty->fileId = EMPTY;
                    empty->fileSize += it->next->fileSize;
                    empty->next = tmp->next;
                    tmp->next->prev = empty;
                    break;
                }
                else {
                    it->fileId = EMPTY;
                    break;
                }
            }
        }
    }

};

List cacheList;
int curTime;
unordered_map<int,int> timeTable;

//void debugFile() {
//    cout << "\ndebug ------------------\n";
//    for(Node* it = cacheList.begin(); it != cacheList.end(); it = it->next) {
//        if(it->fileId == EMPTY) {
//            cout << "EMPTY SPACE --- size : " << it->fileSize << ", idx : " << it->address << "\n";
//        }
//        else {
//            cout << "file Id : " << it->fileId << ", size : " << it->fileSize << ", idx : " << it->address << "\n";
//        }
//    }
//}

int insertFile(int fileId, int fileSize) {
    for(Node* it = cacheList.begin(); it != cacheList.end(); it = it->next) {
        if(it->fileId == EMPTY) {
            if(it->fileSize > fileSize) {
                Node* empty = it;
                Node* file = node[nodeCnt++].alloc(0,0,fileId,fileSize,it->address);
                empty->prev->next = file;
                file->prev = empty->prev;
                empty->prev = file;
                file->next = empty;
                empty->fileSize -= fileSize;
                empty->address = file->address + fileSize;

                cacheList.addFileMap(fileId, file->address);
                cacheList.usage += fileSize;
                curTime++;
                timeTable[fileId] = curTime;

                int ret = file->address;
                return ret;
            }
            else if(it->fileSize == fileSize) {
                Node* file = it;
                it->fileId = fileId;

                cacheList.addFileMap(fileId, file->address);
                cacheList.usage += fileSize;
                curTime++;
                timeTable[fileId] = curTime;

                int ret = file->address;
                return ret;
            }
            else {
                continue;
            }
        }
    }
    return -1;
}

void init(int N) {
    curTime = 0;
    nodeCnt = 0;
    cacheList.clear();
    cacheList.push_front(EMPTY, N, 0); // N만큼 빈공간
    timeTable.clear();
    return;
}

int access(int fileId, int fileSize) {
//    debugFile();
    // 파일이 이미 있을때
    if(cacheList.fileExist(fileId)) { // 해당 파일의 첫 인덱스반환하고 LRU업데이트
        int ret = cacheList.fileIdx[fileId];
        curTime++;
        timeTable[fileId] = curTime;
        return ret;
    }
    else { // 파일이 없을때
        while(1) {
            int ret = insertFile(fileId, fileSize);
            if(ret == -1) { // 빈공간이 없을때
                int minTime = 30000;
                int minId = EMPTY;
                for(auto m : timeTable) {
                    if(minTime > m.second) {
                        minId = m.first;
                        minTime = m.second;
                    }
                }
                if(minId == EMPTY) {
                    return -1;
                }
                cacheList.removeFile(minId);
                cacheList.fileIdx.erase(minId);
                timeTable.erase(minId);
            }
            else return ret;
        }
    }
}

int usage() {
    return cacheList.getUse();
}
