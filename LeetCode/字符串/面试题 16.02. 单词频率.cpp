#include <iostream>
#include <map>
#include <vector>
using namespace std;

// 信心题...被上一道BFS题搞崩了w，不知道调了多长时间...
// map自然可以水过去，不过这里还是用trie做算了，毕竟这数据结构也就这用w 

// 又被LeetCode折磨了...首先是数组之类的东西可以开到类外面，因为之前把数组开在了
// 类里面，所以数组初始值不确定，然后坠毁w
// 后来改出去了，但是没有改idx，然后又坠毁了，迷惑的是改了之后粘贴数据又能过了..
// 用map水过去算了，OOP我... 

// 啊啊啊，首A，太艰辛了w 

int son[1000000][26], cnt[1000000];
int idx = 0;
class WordsFrequency {
public:
	map<string, int> mp;
	void add(string str) {
		int p = 0, sLen = str.size(), cur;
		for (int i = 0; i < sLen; i++) {
			cur = str[i] - 'a';
			if (!son[p][cur]) son[p][cur] = ++idx;
			p = son[p][cur];
		}
		cnt[p]++;
	}
	int fd(string str) {
		int p = 0, cur, sLen = str.size();
		for (int i = 0; i < sLen; i++) {
			cur = str[i] - 'a';
			if (!son[p][cur]) return 0;
			p = son[p][cur];
		}
		return cnt[p];
	}
    WordsFrequency(vector<string>& book) {
        int bLen = book.size();
        if (bLen == 0) return;
        for (int i = 0; i < bLen; i++) /*add(book[i])*/mp[book[i]]++;
    }
    
    int get(string word) {
		return mp[word];
    }
};

/**
 * Your WordsFrequency object will be instantiated and called as such:
 * WordsFrequency* obj = new WordsFrequency(book);
 * int param_1 = obj->get(word);
 */ 

int main() {
	return 0;
}
