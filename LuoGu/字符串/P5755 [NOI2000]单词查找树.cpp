#include <iostream>
using namespace std;

// 裸的字典树题目，这个题要统计节点数，其实想一想Trie树建立节点的过程，即对于每个字符，如果没有出现，建立一个新
// 节点，否则就从已有节点进行扩展，那么有多少个字符没有出现过，那就会建立多少个节点 

// 只用建树统计节点数就行 
const int N = 1e5 + 10;
int son[N][26], idx = 0;
void add(string str) {
	int p = 0, sLen = str.size();
	for (int i = 0; i < sLen; i++) {
		int cur = str[i] - 'A';
		if (!son[p][cur]) son[p][cur] = ++idx;
		p = son[p][cur];
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	string str;
	while (cin >> str) {
		add(str);
	}  
	// 包括根节点 
	cout << idx + 1;
	return 0;
}
/*
int e[M], ex[M], head[M], idx = 0;
void add(int k, int v) {
	e[idx] = v, ex[idx] = head[k], head[k] = idx++;
}
void dijkstra(int sx) {
	dist[sx] = 0;
	que.push(PII(sx, 0));
	while (!que.empty()) {
		PII now = que.top();que.pop();
		int x = now.x, v;
		for (int i = 0; i != -1; i = head[x]) {
			
		]
	}
}
*/
