#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// 看起来是个背包问题，但实际上这个题可以分割重量，这就是部分背包的标志，所有得用贪心来解，
// 主要思路就是按性价比排序，性价比越大，越值得加入背包，如果背包装不下全部价值的物品了，
// 那么就可以用剩余容量*该物品的性价比，即可把背包填满 

struct elements {
	// 重量，价值，性价比 
	double w, v, p;
	elements(double w1 = 0, double v1 = 0, double p1 = 0) {
		w = w1, v = v1, p = p1;
	}
	bool operator<(const elements& e) {
		return p > e.p;
	}
};
elements *e;
int main() {
	int n, t;
	double result = 0;
	cin >> n >> t;
	e = new elements[n];
	for (int i = 0; i < n; i++) {
		cin >> e[i].w >> e[i].v;
		// 定义性价比等于价格除以重量 
		e[i].p = e[i].v / e[i].w;
	} 
	// 保证性价比越高越先选择 
	sort(e, e + n);
	for (int i = 0; i < n; i++) {
		// 背包还有剩余重量，就可以继续装性价比高的东西 
		if (t >= e[i].w) {
			result += e[i].v;
			t -= e[i].w;
		} else {
			// 剩余空间不足以装下整个物品，
			// 那只装部分
			result += e[i].p * t;
			break;
		}
	}
	delete[] e;
	printf("%.2lf", result);
	return 0;
}
