#include <iostream>
using namespace std;

// ����ֵ�����Ŀ�������Ҫͳ�ƽڵ�������ʵ��һ��Trie�������ڵ�Ĺ��̣�������ÿ���ַ������û�г��֣�����һ����
// �ڵ㣬����ʹ����нڵ������չ����ô�ж��ٸ��ַ�û�г��ֹ����ǾͻὨ�����ٸ��ڵ� 

// ֻ�ý���ͳ�ƽڵ������� 
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
	// �������ڵ� 
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
