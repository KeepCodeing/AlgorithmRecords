#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

// ������д���ֵģ�nlogn�ĸ��Ӷȣ�Ȼ���䲻֪����ôд>=�Ķ���w��������ⷢ�ֱ���n^2����... 

const int N = 1e3 + 10;
int f[N], g[N];
int main() {
	int m, n, res = 0x3fffffff;
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= m; i++) scanf("%d", &f[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &g[i]);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			res = min(res, abs(f[i] - g[j]));
		}
	}
	printf("%d", res);
	return 0;
}
