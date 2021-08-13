void mstrcpy(char dst[], const char src[]) {
    int c = 0;
    while ((dst[c] = src[c]) != 0)
        ++c;
}

int mstrlen(const char str[]) {
    int ret = 0;
    while (str[ret])
        ++ret;
    return ret;
}

int mstrcmp(const char str1[], const char str2[]) {
    int c = 0;
    while (str1[c] != 0 && str1[c] == str2[c])
        ++c;
    return str1[c] - str2[c];
}

char input_string[50001];
int n;

void init(int N, char init_string[]) {
    n = N;
    mstrcpy(input_string, init_string);
}

int change(char string_A[], char string_B[]) {
    int ret = 0;

    return ret;
}

void result(char ret[]) {

}