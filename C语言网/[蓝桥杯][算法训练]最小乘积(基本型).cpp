#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// 好像在LeetCode做过了w，就是最大乘最小.. 

const int N = 10;
int nums[2][N];
bool cmp(int a, int b) {return a > b;}
int main() {
	int T, n, res;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < 2; i++) 
			for (int j = 0; j < n; j++) scanf("%d", &nums[i][j]);
		sort(nums[0], nums[0] + n), sort(nums[1], nums[1] + n, cmp), res = 0;
		for (int i = 0; i < n; i++) res += nums[0][i] * nums[1][i];
		printf("%d\n", res);
	}
	return 0;
}
