#include <iostream>
#include <cstdio>
using namespace std;
const int N = 50000 + 10, M = 30;
struct Node {
	int cost, imp;
} node[M];
typedef long long LL;
LL f[N];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) scanf("%d%d", &node[i].cost, &node[i].imp);
	for (int i = 1; i <= m; i++) {
		for (int j = n; j >= node[i].cost; j--) {
			// 状态转移方程不知道为什么写成了f[j - 1]...明明是选或不选，为何和上一个状态有关系呢...
			// 不过只WA了两个点w.. 
			f[j] = max(f[j], f[j - node[i].cost] + node[i].cost * node[i].imp);
		}
	}
	printf("%lld", f[n]);
	return 0;
} 
