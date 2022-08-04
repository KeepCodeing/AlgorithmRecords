#include <iostream>
#include <cstdio>
using namespace std;

// 可以用Trie树记录是否有这个单词以及存放这个单词，但是其不知道怎么记录是否点过（无能）
// 或许是在查询的时候进行操作，但是实际上这个题也可以用map水...

// 用Trie树写，我认为这很好，没有任何坏处 
// 然而空间卡小直接RE，感觉这个空间大小和题目给的数据范围没什么关系，果然写这种题数组能开多大就开多大了... 

// 用map内存消耗更小，但是相对来说慢了点，总的来说能用STL就用STL罢（无能） 
const int N = 500010, M = 60;
int son[N][26], cnt[N], idx = 0;
void add(char str[]) {
	int p = 0;
	for (int i = 0; str[i]; i++) {
		int cur = str[i] - 'a';
		if (!son[p][cur]) son[p][cur] = ++idx;
		p = son[p][cur];
	}
	//cnt[p]++;
}
int findName(char str[]) {
	int p = 0;
	for (int i = 0; str[i]; i++) {
		int cur = str[i] - 'a';
		if (!son[p][cur]) return -1;
		p = son[p][cur];
	}
	cnt[p]++;
	return cnt[p] == 1 ? 1 : 2;
}
char str[M];
int main() {
	int n, m;
	scanf("%d", &n);
	while (n--) {
		scanf("%s", &str);
		add(str);
	}
	scanf("%d", &m);
	while (m--) {
		scanf("%s", &str);
		int res = findName(str);
		if (res == -1) printf("WRONG\n");
		else if (res == 2) printf("REPEAT\n");
		else printf("OK\n");
	}
	return 0;
} 
