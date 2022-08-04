#include <iostream>
using namespace std;

// 今天第三次写并查集...，，刻意练习来加深印象，这个题就不像上一个题了，这个题需要路径压缩
// 当然最好写并查集的时候就加上路径压缩，因为也就一行代码 

struct unionFind {
	int *bin;
	unionFind(int len) {
		bin = new int[len + 1];
		for (int i = 1; i <= len; i++) bin[i] = i;
	}
	int anc(int x) {
		if (bin[x] == x) return x;
		bin[x] = anc(bin[x]);
		return bin[x];
	}
	void uni(int x, int y) {
		bin[anc(x)] = anc(y);
	}
	void ask(int x, int y) {
		if (anc(x) == anc(y)) cout << "Y" << endl;
		else cout << "N" << endl;
	} 
	~ unionFind() {
		delete[] bin;
	}
};

int main() {
	int n, m;
	int x, y, z;
	cin >> n >> m;
	unionFind u(n);
	while(m--) {
		cin >> z >> x >> y;
		if (z == 1) u.uni(x, y);
		else u.ask(x, y);  
	}
	
	return 0;
}
