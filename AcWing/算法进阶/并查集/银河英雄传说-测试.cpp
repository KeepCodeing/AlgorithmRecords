#include <iostream>
#include <cmath>
using namespace std;
const int N = 30010;
struct unionFind {
	int dist[N], bin[N], sz[N];
	// 这里dist居然设置为1了，自己到自己的距离为0... 
	unionFind () {for (int i = 1; i <= N; i++) dist[i] = 0, bin[i] = i, sz[i] = 1;}
	int anc(int x) {
		// 后面类似前缀和的操作就是加边权，每个点的边权都是到父节点的距离 
		if (x != bin[x]) {
			// 注意这里的顺序不能错，得先求前缀和再路径压缩 
			dist[x] += dist[bin[x]];
			bin[x] = anc(bin[x]);
		}
		return bin[x];
	}
	void uni(int x, int y) {
		// 合并加边权就是把被合并集合的根节点距离等于合并集合的大小 
		int ax = anc(x), ay = anc(y);
		// 同一个节点不能反复更新 
		//if (ax != ay) {
		dist[ax] = sz[ay];
		// 更新集合大小 
		sz[ay] += sz[ax];
		bin[ax] = ay;
		//}
	}
	int getDist(int x, int y) {
		int ax = anc(x), ay = anc(y);
		if (ax != ay) return -1;
		// 我谔谔，这里写成了ax和ay，这就变成了根节点距离相减了... 
		return max(0, abs(dist[x] - dist[y]) - 1);
	}
};
unionFind u;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		char op;
		int x, y;
		cin >> op >> x >> y;
		if (op == 'M') u.uni(x, y); 
		else cout << u.getDist(x, y) << endl; 
	}
	return 0;
} 
