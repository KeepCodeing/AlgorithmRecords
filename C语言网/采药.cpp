#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1010;
struct Node {
	int tm, val;
} node[N];
int f[N];
int main() {
	int t, m;
	scanf("%d%d", &t, &m);
	for (int i = 1; i <= m; i++) scanf("%d%d", &node[i].tm, &node[i].val);
	for (int i = 1; i <= m; i++) {
		for (int j = t; j >= node[i].tm; j--) {
			f[j] = max(f[j], f[j - node[i].tm] + node[i].val);
		}
	}
	printf("%d", f[t]);
	return 0;
}
