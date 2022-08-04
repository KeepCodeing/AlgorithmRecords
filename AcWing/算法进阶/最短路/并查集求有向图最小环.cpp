#include <iostream>
#define endl '\n'
using namespace std;
const int N = 200000 + 10;
int bin[N], dist[N];
int ans = 0x3fffffff;

// 用Dijkstra或者floyd求有向图的最小环复杂度都不太理想，对于有向图的floyd算法来说，求它的最小环其实就是求一次
// 全源最短路...
// 这里使用并查集进行解题，它的主要思路是在连边的过程中判断两个点是否在一个集合里，如果在一个集合里，即说明x，
// 和y在一个环路里，那么x，y的距离和就是x到根节点的距离+y到根节点的距离+1，其它部分和带权并查集类似 

struct unionFind {
	unionFind() {
		// 关于dist的初始值：一开始的所有点都是单独的一个点，所以没有到父节点的距离 
		for (int i = 0; i < N; i++) bin[i] = i, dist[i] = 0; 
	}
	int anc(int x) {
		if (x != bin[x]) {
			// 注意这里的写法，它和并查集求路径长度不同，它要的距离是路径压缩前的...而另一个题是有顺序规定的，
			// 所以可以直接把当前点的距离从父节点推导出... 
			int fa = bin[x];
			// 普通并查集的连边过程 
			bin[x] = anc(bin[x]);
			dist[x] += dist[fa];
		}
		return bin[x];
	}
	void uni(int x, int y) {
		int a = anc(x), b = anc(y);
		if (a == b) {
			// 如果x，y的祖宗在一个集合里，就说明他们在一个环路里，那么统计这个环的长度 
			ans = min(ans, dist[x] + dist[y] + 1);
		} else {
			bin[a] = b;
			// 如果不在一个集合里进行合并的时候算出x到y的根节点的距离 
			dist[x] = dist[y] + 1;
		}
	}
};
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, vt;
	cin >> n;
	unionFind uf;
	for (int i = 1; i <= n; i++) {
		cin >> vt;
		uf.uni(i, vt);
	} 
	cout << ans << endl;
	return 0;
}
