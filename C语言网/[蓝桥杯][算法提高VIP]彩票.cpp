#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 40, M = 10, K = 7;
int trick[M], bucket[N];
int res[M];
int main() {
	int n, t, cnt;
	scanf("%d", &n);
	for (int i = 1; i <= K; i++) scanf("%d", &trick[i]);
	// 读入彩票并且放到桶里，然后再统计出现了多少个有效数字，这样可以免去开二维数组，而且可以直接处理 
	for (int i = 1; i <= n; i++) {
		memset(bucket, 0, sizeof bucket);
		// 保证下标正确 
		cnt = K + 1;
		for (int j = 1; j <= K; j++) {
			scanf("%d", &t);
			bucket[t]++;
		}
		// 遍历桶，然后统计出现了几个数字，这里用自减代替了下标，如果用自增结果会是倒着的.. 
		for (int j = 1; j <= K; j++) {
			if (bucket[trick[j]]) cnt--;
		}
		// 统计有多少个票.. 
		res[cnt]++;
	}
	for (int i = 1; i <= K; i++) cout << res[i] << ' ';
	return 0;
}
