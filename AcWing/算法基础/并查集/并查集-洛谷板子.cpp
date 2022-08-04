#include <iostream>
using namespace std;

// fuxi下从洛谷教程里学到的并查集

// 其实并查集就是在操作若干树，树的根节点就是这个集合的编号，合并操作
// 就是将一个树的根节点指向另一个树的任意节点。 

// 刚刚对比了下new分配内存和直接分配内存的效率，似乎是差不多的，但是在main里new超大的
// 数组不会爆栈（废话，new分配到的空间是堆空间），不过似乎没见过有人用new来动态分配的
// 一般还是直接开个大数组，王道征途... 

struct unionFind {
	int *bin;
	unionFind(int n) {
		bin = new int[n + 5];
		for (int i = 1; i <= n; i++) bin[i] = i;
	}
	int anc(int x) {
		if (x == bin[x]) return x;
		// 这里所谓的路径压缩就是在遍历的过程中把所有遍历过的节点
		// 直接指向根节点 
		bin[x] = anc(bin[x]);
		return bin[x];
	}
	void uni(int x, int y) {
		// 合并：把y集合的根节点指向x集合的根节点 
		bin[anc(x)] = anc(y);
	}
	bool ask(int x, int y) {
		// 查询：判断x集合的根节点是否和y集合的根节点相同 
		return anc(x) == anc(y);
	}
	~ unionFind() {
		delete[] bin;
	}
}; 
int main() {
	int n, m;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	unionFind u(n);
	char code;
	int a, b;
	while (m--) {
		cin >> code >> a >> b;
		if (code == 'M') u.uni(a, b);
		else cout << (u.ask(a, b) ? "Yes" : "No") << endl; 
	} 	
	return 0;
}
/*
输入样例：
4 5
M 1 2
M 3 4
Q 1 2
Q 1 3
Q 3 4
输出样例：
Yes
No
Yes
*/
