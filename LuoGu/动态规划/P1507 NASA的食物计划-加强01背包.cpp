#include <iostream>
using namespace std;

// 同样是加强版01背包，由此可见01背包就是类似于有N个约束条件（背包大小），有一个价值选项，要求最大值得题（当然
// 价值选项似乎也是可变的） 

// 顺序写错了，结果测试数据过了，但是提交全部RE... 

struct foods {
	int size, w, v;
	foods(int s1 = 0, int w1 = 0, int v1 = 0) {
		size = s1, w = w1, v = v1;
	}
};
int f[2000][2000];
int main() {
	int s, fs, n;
	cin >> s >> fs >> n;
	foods *fd = new foods[n + 1];
	for (int i = 1; i<= n; i++) {
		cin >> fd[i].size >> fd[i].w >> fd[i].v;
	}
	// 注意这里的顺序问题，最内层的循环一定是会消耗背包体积的代价，比如重量，时间等等， 
	// 而外面的代价一般都会影响背包体积 
	for (int i = 1; i <= n; i++) {
		for (int j = s; j >= fd[i].size; j--) {
			for (int k = fs; k >= fd[i].w; k--) {
				// 这里之前减错了，应该就是对应的价值减去对应的代价 
				f[j][k] = max(f[j][k], f[j - fd[i].size][k - fd[i].w] + fd[i].v);
			}
		}
	}
	cout << f[s][fs];
	delete[] fd;
	return 0;
}
