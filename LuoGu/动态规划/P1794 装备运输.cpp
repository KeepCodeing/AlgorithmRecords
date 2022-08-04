#include <iostream>
using namespace std;

// 二维费用背包+完全背包，没怎么做过，但是应该就是把顺序调过来罢（虚心） 
// 搞不懂是一般二维费用背包还是加了完全背包的了，因为测试样例两种背包
// 答案都对...，但是题目没有特别说明这是个完全背包，而且说是有N件装备...

// 奇妙，就是普通二维费用背包，难度虚高ww 

const int N = 510;
int f[N][N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0); 
	int v, g;
	cin >> v >> g;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x, y, z;
		// 火力，体积和重量 
		cin >> x >> y >> z;
		// 最后枚举重量就行
		for (int j = v; j >= y; j--) {
			for (int k = g; k >= z; k--) {
				f[j][k] = max(f[j][k], f[j - y][k - z] + x);
			}
		} 
//		for (int j = y; j <= v; j++) {
//			for (int k = z; k <= g; k++) {
//				f[j][k] = max(f[j][k], f[j - y][k - z] + x);
//			}
//		} 
	}
	cout << f[v][g];
	return 0;
}
