#include <iostream>
#include <algorithm>
using namespace std;

// 不知道这个题是不是部分背包问题，但是如果按照测试数据来看
// 似乎不是全选，而是可以选一部分

// 关键：要当前价格最少 

struct elements {
	int m, w, tot;
	elements(int m1 = 0, int w1 = 0, int t1 = 0) {
		m = m1, w = w1, tot = t1;
	}
	bool operator<(const elements& e) {
		// 按价格降序 
		return m < e.m;
	}
};
elements *e;
int main() {
	int t, n;
	int result = 0;
	cin >> t >> n;
	e = new elements[n];
	for (int i = 0; i < n; i++) {
		cin >> e[i].m >> e[i].w;
		e[i].tot = e[i].m * e[i].w;
	}
	sort(e, e + n);
	for (int i = 0; i < n; i++) {
		// cout << e[i].m << ' ' << e[i].w << ' ' << e[i].tot << endl;
		// 全的装的下 
		if (t >= e[i].w) {
			result += e[i].tot;
			t -= e[i].w;
		} else {
			// 只能装下部分，用剩下的部分*当前牛奶的价格 
			result += t * e[i].m; 
			break;
		}
	}
	cout << result;
	delete[] e;
	return 0;
}
