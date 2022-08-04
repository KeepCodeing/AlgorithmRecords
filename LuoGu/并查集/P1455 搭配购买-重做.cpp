#include <iostream>
using namespace std;
const int N = 10010;
int n, m, w;
int wei[N], val[N];
int bin[N];
int f[N];
struct unionFind {
	unionFind () {for (int i = 1; i <= N; i++) bin[i] = i;}
	int anc(int x) {
		// 感觉这样写还是不太熟练 
		if (x != bin[x]) bin[x] = anc(bin[x]);
		return bin[x];
	}
	void uni(int x, int y) {
		if (!ask(x, y)) {
			int ax = anc(x), ay = anc(y);
			bin[ax] = ay;
			val[ay] += val[ax];
			wei[ay] += wei[ax];
		}
	}
	bool ask(int x, int y) {return anc(x) == anc(y);}
};
unionFind u;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> w;
	// 先输入的是价钱，后面是价值，可以看成代价和花费 
	for (int i = 1; i <= n; i++) cin >> wei[i] >> val[i];
	while (m--) {
		int x, y;
		cin >> x >> y;
		u.uni(x, y); 
	}
	// 01背包模型有点忘了...
	// 第一层循环为有多少个物品，第二层循环为
	// 手上有多少钱以及能花多少钱（代价），最终的结果为
	// 是当前解更优还是花钱买另一个东西更优 
	for (int i = 1; i <= n; i++) {
		if (i == bin[i]) {
			for (int j = w; j >= wei[i]; j--) {
				f[j] = max(f[j], f[j - wei[i]] + val[i]);
			}
		}
	}
	cout << f[w];
	return 0;
}
