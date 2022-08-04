#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

// 虽然这个题分在了dp里面，但实际上就是个桶排水题w，总之搞了一点算法
// 还没有真正开始学DP，而蓝桥杯似乎必考这玩意w，开刷w 

const int N = 1e6 + 10;
int bucket[N];
int main() {
	int n, num, res, temp;
	while (scanf("%d", &n) != EOF) {
		memset(bucket, 0, sizeof bucket);
		res = 0, temp = n;
		// 这里直接写成n--了，下面还用n判断...实在奇妙w 
		while (temp--) {
			scanf("%d", &num);
			bucket[num]++;
			if (bucket[num] >= (n + 1) / 2) res = num;
		}	
		printf("%d\n", res);
	}
	return 0;
}
