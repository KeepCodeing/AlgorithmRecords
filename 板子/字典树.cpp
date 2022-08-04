#include <iostream>
#include <cstdio>
using namespace std;
const int N = 500010, M = 60;
int son[N][26], cnt[N], idx = 0;
void add(char str[]) {
	int p = 0;
	for (int i = 0; str[i]; i++) {
		int cur = str[i] - 'a';
		if (!son[p][cur]) son[p][cur] = ++idx;
		p = son[p][cur];
	}
	// ͳ�Ƶ��ʳ��ִ�����������������ʱ���������ظ�����
	// ʱ���޷��ж��Ǹ������Ƿ񱨹��� 
	// cnt[p]++;
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
