#include <iostream>
#include <cstdio>
using namespace std;
const int N = 55;
int son[N][26], cnt[N], idx = 0;
int n;
void add(char str[]) {
	int p = 0;
	int cur;
	for (int i = 0; str[i]; i++) {
		cur = str[i] - 'a';
		// ע�⣺���ڵ㲻�ܴ涫������������idxҪô��
		// 1��ʼ��Ҫô�Ƚ������� 
		if (!son[p][cur]) son[p][cur] = ++idx;
		p = son[p][cur];
	}
	cnt[p]++;
}
int findWord(char str[]) {
	int p = 0;
	int cur;
	for (int i = 0; str[i]; i++) {
		cur = str[i] - 'a';
		if (!son[p][cur]) return 0;
		p = son[p][cur];
	}
	return cnt[p];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d", &n);
	char str[N];
	char op[2];
	while (n--) {
		scanf("%s%s", &op, &str);
		if (op[0] == 'I') add(str);
		else cout << findWord(str) << endl;
	}
	return 0;
}
