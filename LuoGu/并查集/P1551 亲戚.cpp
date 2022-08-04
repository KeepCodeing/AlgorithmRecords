#include <iostream>
using namespace std;

// 并查集的模板题，这个题只需要实现下并查集的基本功能即可

struct unionFind {
	int *bin;
	unionFind(int len) {
		bin = new int[len + 1];
		// 初始化查询数组，每个元素的颜色默认染成自己 
		for (int i = 1; i <= len; i++) bin[i] = i; 
	}
	// 查询某个元素的祖先操作 
	int anc(int x) {
		// 如果找到了该元素的祖先，返回即可 
		if (bin[x] == x) return x;
		// 否则继续向上查找祖先，例如bin[1] = 1, bin[2] = 1, bin[3] = 2;假如我们要查询的是3的祖先， 
		// 那么这段代码就会先比较bin[3]的颜色是不是其自己，如果不是，找bin[2]，找到bin[2]发现也不是
		// 继续向上找bin[1]，此时就算找到了祖先节点了 
		anc(bin[x]);
	}
	// 合并操作，注意声明函数类型，不然可能编译不了 
	void uni(int x, int y) {
		//将x这群人的颜色染成y这群人的颜色 
		bin[anc(x)] = anc(y);
	} 
	// 查找操作
	void ask(int x, int y) {
		// 查询x的祖先是不是和y的祖先相同，如果相同就说明他们是亲戚 
		if (anc(x) == anc(y)) cout << "Yes" << endl;
		else cout << "No" << endl;
	} 
	~ unionFind() {
		delete[] bin;
	}
}; 

int main() {
	int n, m, p;
	int x, y;
	cin >> n >> m >> p;
	// 分配空间以及初始化染色 
	unionFind u(n);
	// 构造亲戚关系 
	while (m--) {
		cin >> x >> y;
		u.uni(x, y);
	}
	// 执行查找操作
	while (p--) {
		cin >> x >> y;
		u.ask(x, y);
	} 
	return 0;
}
