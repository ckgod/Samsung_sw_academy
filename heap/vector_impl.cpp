struct vector {
    int * a = 0;
    int n, N; //n은 size, N은 capacity

    void clear() {
        // 할당된 메모리가 있었다면 해제
        if (a != 0) delete[] a;
        // 초기 할당, N이 클수록 적은 원소 관리할 때 오버헤드가 줄어듭니다.
        a = new int[N = 2];
        n = 0;
    }

    void resize(int _N) {
        //기존 배열 포인터저장
        int * b = a;
        //N을 새로운_N으로 교체, _N 사이즈로 새로 할당받음
        a = new int[N = _N];
        //기존 배열 복사
        for (int i = 0; i < n; ++i)
            a[i] = b[i];
        //기존 배열 할당해제
        delete[] b;
    }

    void push_back(int x) {
        a[n] = x;
        //size를 증가시켰을때 capacity와 같아지면 resize
        if (++n == N) resize(N << 1);
    }

    void pop_back() {
        //size를 감소시켰을때 capacity/4 와 같다면 절반으로 resize
        if (--n == N >> 2) resize(N >> 1);

    }
};