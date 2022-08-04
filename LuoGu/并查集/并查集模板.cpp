#include <iostream>
using namespace std;
struct unionFind {
	int *bin;
	// 初始化查询数组 
	unionFind(int len) {
		bin = new int[len + 1];
		for (int i = 1; i <= len; i++) bin[i] = i;
	}
	// 查询祖宗节点，这里加入了路径压缩，不加入路径压缩，并查集的最底效率可能导致超时
	// 加入路径压缩，并查集的效率可以接近O(n) 
	int anc(int x) {
		if (bin[x] == x) return x;
		// 这就是路径压缩，我们添加一个回溯过程：把链上所有的点的bin值，直接指向最终的代表元素。 
		return bin[x] = anc(bin[x]);
	}
	// 合并节点
	void uni(int x, int y) {
		bin[anc(x)] = anc(y);
	} 
	// 查询节点
	void ask(int x, int y) {
		if (anc(x) == anc(y)) cout << "Yes" << endl;
		else cout << "No";
	} 
	// 释放内存 
	~ unionFind() {
		delete[] bin;
	}
};
int main() {
	return 0;
}
