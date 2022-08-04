#include <iostream>
#include <cstdio>
using namespace std;

const int N = 100010;

int son[N][26], cnt[N], idx = 0;

void insertStr(char *str) {
	int p = 0;
	for (int i = 0; str[i]; i++) {
		int cur = str[i] - 'a';
		if (!son[p][cur]) son[p][cur] = ++idx;
		p = son[p][cur];
	}
	cnt[p]++;
}

int query(char *str) {
	int p;
	for (int i = 0; str[i]; i++) {
		int cur = str[i] - 'a';
		if (!son[p][cur]) return 0;
		p = son[p][cur];
	}
	return cnt[p];
}
char str[N];
int main() {
	int n;
	scanf("%d", &n);
	char code[2];
	while (n--) {
		scanf("%s%s", &code, &str);
		if (code[0] == 'I') insertStr(str);
		else printf("%d\n", query(str)); 
	}
	return 0;
}
