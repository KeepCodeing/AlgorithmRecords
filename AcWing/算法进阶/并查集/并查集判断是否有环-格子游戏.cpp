#include <iostream>
using namespace std;

// 思路：当输入的两个坐标存在一个共同祖先（在同一个集合里），就说明
// 它们连接起来会形成环，也就是游戏结束，如果没有环，就说明这两个点
// 要被添加到一个集合里 

const int N = 210, M = N * N;
struct unionFind {
	int bin[M];
	unionFind() {
		// 并查集下标从0开始 
		for (int i = 0; i <= M; i++) bin[i] = i;
	}
	int anc(int x) {
		// 更简洁的写法 
		if (x != bin[x]) bin[x] = anc(bin[x]);
		return bin[x];
	}
	void uni(int x, int y) {
		bin[anc(x)] = anc(y);
	}
	bool ask(int x, int y) {
		return anc(x) == anc(y);
	}
};
unionFind u;
int n, m;
// 因为输入的是二维数据，而并查集只能处理一维的数据，所以这里要将二维
// 数据转换为一维数据，公式为x * n + y，只要保证二维数据转换为一维数据
// 唯一即可 
int getDot(int x, int y) {return x * n + y;}
int main() {
	cin >> n >> m;
	int res = 0;
	for (int i = 1; i <= m; i++) {
		int x, y;
		char op;
		cin >> x >> y >> op;
		// 将下标从0开始，这样才能用x * n + y这个公式，同样，并查集的下标也得从0开始 
		x--, y--;
		int dot, ndot;
		// 获取当前点对应的一维表示 
		ndot = getDot(x, y);
		// 获取向下走向右走对应的一维表示 
		if (op == 'D') dot = getDot(x + 1, y);
		else dot = getDot(x, y + 1);
		// 判断两个点是否在一个连通图里，如果在，说明它们相连会形成环，即游戏结束 
		if (u.anc(ndot) == u.anc(dot)) {
			res = i;
			break;
		}
		// 如果两个点不在一个连通图里，则将它们合并 
		u.uni(dot, ndot); 
	}
	if (res) cout << res;
	else cout << "draw";
	return 0;
}

/*
输入样例：
3 5
1 1 D
1 1 R
1 2 D
2 1 R
2 2 D
输出样例：
4
*/
