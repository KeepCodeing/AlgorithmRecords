#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 100010;
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
	int p = 0, res = 0;
	for (int i = 0; str[i]; i++) {
		int cur = str[i] - 'a';
		if (!son[p][cur]) return res;
		p = son[p][cur];
		res += cnt[p];
	}
	return res;
}
char str[N][510];
char buf[510];
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%s", &str[i]);
	}
	int res = 0;
	
	for (int i = 1; i <= n; i++) {
		int cntNum = 0;
		for (int j = i + 1; j <= n; j++) {
			int index = 0;
			bool flag = true;
			for (int t = j; t <= n; t++) {
				for (int k = index; k <= strlen(str[i]); k++) {
					if (str[i][k] == str[j][k]) {
						index++;
					} else {
						flag = false;
						break;
					}
				}
				if (!flag) break;
			}
		}
		res = max(res, cntNum);
	}
	cout << res;
	return 0;
}
