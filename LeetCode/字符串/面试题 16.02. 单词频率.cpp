#include <iostream>
#include <map>
#include <vector>
using namespace std;

// ������...����һ��BFS������w����֪�����˶೤ʱ��...
// map��Ȼ����ˮ��ȥ���������ﻹ����trie�����ˣ��Ͼ������ݽṹҲ������w 

// �ֱ�LeetCode��ĥ��...����������֮��Ķ������Կ��������棬��Ϊ֮ǰ�����鿪����
// �����棬���������ʼֵ��ȷ����Ȼ��׹��w
// �����ĳ�ȥ�ˣ�����û�и�idx��Ȼ����׹���ˣ��Ի���Ǹ���֮��ճ���������ܹ���..
// ��mapˮ��ȥ���ˣ�OOP��... 

// ����������A��̫������w 

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
