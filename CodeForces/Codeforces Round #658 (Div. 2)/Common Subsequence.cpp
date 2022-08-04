#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1000 + 10;
int bucket[N];
int T, n, m, t, flag;
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		flag = false;
		memset(bucket, 0, sizeof bucket);
		for (int i = 1; i <= n; i++) scanf("%d", &t), bucket[t]++;
		for (int i = 1; i <= m; i++) scanf("%d", &t), bucket[t]++;
		for (int i = 1; i < N; i++) {
			if (bucket[i] > 1) {
				printf("YES\n");
				printf("1 %d\n", i);
				flag = true;
				break;
			}
		}
		if (!flag) printf("NO\n");
		
	}
	return 0;
}
