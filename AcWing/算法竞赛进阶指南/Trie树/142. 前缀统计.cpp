#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1000010;
int son[N][26], cnt[N], idx = 0;
void add(char str[]) {
	int p = 0;
	for (int i = 0; str[i]; i++) {
		int cur = str[i] - 'a';
		if (!son[p][cur]) son[p][cur] = ++idx;
		p = son[p][cur];
	} 
	cnt[p]++;
}
int findWord(char str[]) {
	// ˼·���Ǽ�¼·���������ַ����ֵĴ��� 
	int p = 0, res = 0;
	for (int i = 0; str[i]; i++) {
		int cur = str[i] - 'a';
		// û���ַ���ֱ�ӷ��ش� 
		if (!son[p][cur]) return res;
		p = son[p][cur];
		// ��¼�ַ����� 
		res += cnt[p];
	}
	return res;
}
char str[N];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	while (n--) {
		scanf("%s", &str);
		add(str);
	}
	while (m--) {
		scanf("%s", &str);
		printf("%d\n", findWord(str));
	}
	return 0;
}
