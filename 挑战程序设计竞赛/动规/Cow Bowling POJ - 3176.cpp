#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

// 经典的数字三角形的题，动规课程也弃了...不过还是有点收获，下面来分析下这个题
// 考虑下最后一步，如果我们按照题意模拟，那么最后的终点就是最后一行的那些数字中的任意一个，这样实在过于麻烦，所以
// 得反向思考下，既然第一个点可以作为起点，那么第一个点也就同样能作为终点，这样的话，最后一步就转换为了从第一个
// 点左边走过来的花费最低还是从最后一个点的右边走过来花费最低。于是子问题就是从(1, 2)这个点走过来还是从(2, 2)这个
// 点走过来花费最低。
// 那么动态转移方程就可以写成f[i][j] = min{f[i + 1][j], f[i + 1][j - 1]} // 这里应该是[j + 1]，考虑最左边的点，j-1就出界了... 
// 另外要注意初始值和边界情况，对于最后一行的所有点而言，它们没有可以选择的点，所以他们的最小花费就是其自身，而边界
// 就是下标不出界即可... 

// 注意下计算顺序，从下往上直到走到了起点

// 还有动态转移方程w，这个题求的是最大值，不是最小值... 

// 这里为了保险开了long long 
typedef long long LL; 
const int N = 370;
int graph[N][N];
LL f[N][N];
int main() {
	int n;
	scanf("%d", &n);
	memset(f, 0, sizeof f);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%d", &graph[i][j]);
			if (i == n) f[i][j] = graph[i][j];
		}
	}
	for (int i = n - 1; i >= 1; i--) {
		for (int j = 1; j <= i; j++) {
			// 状态转移 
			f[i][j] = max(f[i + 1][j], f[i + 1][j + 1]) + graph[i][j];
		}
	}
	printf("%d", f[1][1]);
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= i; j++) {
//			printf("%d ", f[i][j]);
//		}
//		puts("");
//	}
	return 0;
}
