#include <iostream>
#include <cstdio>
using namespace std;

// 并不想用map水过去，写个Trie没有任何坏处 

int son[1000][26], cnt[100], idx = 0;
void add(char str[]) {
	int p = 0;
	// 将每个字符映射到Trie里 
	for (char i = 0; str[i]; i++) {
		// 给当前节点一个唯一的编号 
		if (!son[p][str[i] - 'a']) son[p][str[i] - 'a'] = ++idx;
		p = son[p][str[i] - 'a'];
	}
	cnt[p]++;
}
int cwords(char str[]) {
	int p = 0;
	// 找到叶子节点，叶子节点存放了这个字符串的出现次数 
	for (char i = 0; str[i]; i++) p = son[p][str[i] - 'a'];
	return cnt[p];
}
char str[100], names[100][100];
int main() {
	int n, minCnt = -1, t;
	string res;
	cin >> n;
	// 插入字符串以及对比字符串出现次数 
	for (int i = 1; i <= n; i++) scanf("%s", &names[i]), add(names[i]);
	for (int i = 1; i <= n; i++) t = cwords(names[i]), res = minCnt < t ? minCnt = t, names[i] : res;
	printf("%s\n", res.c_str());
	return 0;
}
