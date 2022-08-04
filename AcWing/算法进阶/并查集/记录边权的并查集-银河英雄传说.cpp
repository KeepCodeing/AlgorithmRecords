#include <iostream>
#include <cmath>
using namespace std;
const int N = 30010;
struct unionFind {
	// sz表示当前连通块大小，dist表示集合中每个节点到根的距离 
	int bin[N], sz[N], dist[N];
	unionFind () {
		for (int i = 1; i <= N; i++) {
			bin[i] = i, sz[i] = 1, dist[i] = 0;
		}
	}
	int anc(int x) {
		if (bin[x] != x) {
			// 在进行路径压缩的同时将当前节点到根节点的距离变为当前节点到父节点的距离，这样就类
			// 似一个前缀和后面就可以用这个来求出两个战舰之间隔多少战舰 
			dist[x] += dist[bin[x]];
			bin[x] = anc(bin[x]);
		}
		return bin[x];
	}
	// 合并距离 
	void uniDist(int x, int y) {
		int ax = anc(x), ay = anc(y);
		// 因为在查询时就利用了类似前缀和的思想，所以合并时要将集合x中所有点
		// 到新集合y根节点的距离更新只需要将x集合存的前缀和改为y集合的sz属性即可 （不是这样哦）
		
		// 因为这里用的是前缀和，所以合并操作只需要改根节点的距离就行。那么旧根节点x到新根节点y的距离
		// 就是y的size属性，所以只需要将x到y的距离加上y的size属性即可。因为x本来是个根节点，所以它不管
		// 是直接加y的size属性还是等于y的size属性都是一样的 
		dist[ax] = sz[ay];
		// 因为新增了一个集合，所以要更新y集合的大小 
		sz[ay] += sz[ax];
		// 将x的根节点指向y 
		bin[ax] = ay;
	}
	int getDist(int x, int y) {
		int ax = anc(x), ay = anc(y);
		if (ax != ay) return -1;
		// 两个节点的距离可以利用前缀和公式计算出来，因为不知道先后顺序，所以要求下绝对值
		// 另外因为题目要求的是中间有多少战舰，所以还要-1，另外如果x==y，那么我们得出来的是
		// -1，实际答案是0，所以还要加个max特判下 
		return max(0, abs(dist[x] - dist[y]) - 1);
	}
};
unionFind u;
int main() {
	int T;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		char op;
		int x, y;
		cin >> op >> x >> y;
		if (op == 'M') u.uniDist(x, y);
		else cout << u.getDist(x, y) << endl;
	} 
	return 0;
} 

/*
输入样例：
4
M 2 3
C 1 2
M 2 4
C 4 2
输出样例：
-1
1
*/
