#include <iostream>
using namespace std;

// 这个题似乎是01背包的加强版，在只有价值和重量的基础上又新增了一个限定项，但是
// 不管怎么加都是有公式的

// 普通01背包未优化需要用二维数组来做，经过优化后只需要用一维数组即可，同样，
// 新增了限定项的01背包未优化需要用三维数组来做，但是经过优化只需要用二维数组
// 规律基本不变 

struct person {
	int v, b, w;
	person(int v1 = 0, int b1 = 0, int w1 = 0) {
		v = v1, b = b1, w = w1;
	}
};

int f[1200][1200];

int main() {
	int n, m, x;
	cin >> n >> m >> x;
	person *p = new person[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> p[i].v >> p[i].b >> p[i].w;
	}
	// 基本还是差不多，套公式 
	for (int i = 1; i <= n; i++) {
		// 这一层就是新增的约束项，似乎和01背包比就是多了一维数组 
		for (int j = m; j >= p[i].b; j--) {
			// 规律好像是最内层总是重量（即装包的代价）的循环，同时加上可获得的价值 
			for (int k = x; k >= p[i].w; k--) {
				// 这里还是比较当前元素大还是装包元素大，下标似乎就按顺序来 
				f[j][k] = max(f[j][k], f[j - p[i].b][k - p[i].w] + p[i].v);
			}
		}
	}
	cout << f[m][x];
	delete[] p;
	return 0;
}
