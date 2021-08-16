#define TRIE_NUM 26

void mstrcpy(char dst[], const char src[]);
int mstrlen(const char str[]);
int mstrcmp(const char str1[], const char str2[]);

struct Trie;
Trie* trieAlloc();

struct Trie{
    Trie *_children[TRIE_NUM];
    bool finish;

    void add(const char *word) {
        if(*word == 0) {
            finish = true;
            return;
        }
        if(_children[*word -'a'] == nullptr) _children[*word -'a'] = trieAlloc();
        _children[*word -'a']->add(word+1);
    }

};

/*
void mstrcpy(char dst[], const char src[])
{
	int c = 0;
	while ((dst[c] = src[c]) != 0)
		++c;
}

int mstrlen(const char str[])
{
	int ret = 0;
	while (str[ret])
		++ret;
	return ret;
}

int mstrcmp(const char str1[], const char str2[])
{
	int c = 0;
	while (str1[c] != 0 && str1[c] == str2[c])
		++c;
	return str1[c] - str2[c];
}
*/

void init()
{

}

void inputWord(char mWord[20])
{

}

int recommend(char mUser[20], char mAnswer[20])
{
    return 0;
}

void banWord(char mWord[20])
{

}