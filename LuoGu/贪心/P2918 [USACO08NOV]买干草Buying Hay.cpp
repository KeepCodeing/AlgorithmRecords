#include <iostream>
#include <algorithm>
using namespace std;

struct elements {
	int w, m;
	double p;
	elements(int w1 = 0, int m1 = 0, double p1 = .0) {
		w = w1, m = m1, p = p1;
	}
	// 钱越少越靠前，大概不可行，按性价比排试试 
	bool operator<(const elements& e) {
		return p > e.p;
	}
};
elements *e;
int main() {
	int n, h;
	int temp;
	cin >> n >> h;
	e = new elements[n];
	for (int i = 0; i < n; i++) {
		cin >> e[i].w >> e[i].m;
		// 如果按照部分背包的解法，或许可解？
		// 设置一个性价比 
		e[i].p = e[i].w * 1.0 / e[i].m; 
	}
	sort(e, e + n);
	// 贪心策略：先选性价比高的，因为选不完，所以
	// 可以一直选，但是这里不能分着选，也就是说
	// 必须得选出重量相等的干草
	int ans = 0;
	int index = 0;
	while(true) {
		temp = e[index].w;
		if (h == 0) {
			break;
		} else if (h > 0) {
			h -= temp;
			ans += e[index].m;
		} else {
			h += temp;
			ans -= e[index].m;
			index++;
		}
	} 
	cout << ans;
//	cout << endl;
//	for (int i = 0; i < n; i++) {
//		cout << e[i].w << ' ' << e[i].m << ' ' << e[i].p << endl;
//
//	}
	return 0;
}
