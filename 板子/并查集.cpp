#include <iostream>
using namespace std;

// https://www.luogu.com.cn/problem/P3367

const int N = 1e4 + 10;
struct unionFind {
	int bin[N];
	unionFind() {
		for (int i = 0; i < N; i++) bin[i] = i;
	}
	int anc(int x) {
		if (x != bin[x]) bin[x] = anc(bin[x]);
		return bin[x];
	}
	void uni(int x, int y) {
		int a = anc(bin[x]), b = anc(bin[y]);
		bin[a] = b;
	}
	void ask(int x, int y) {
		if (anc(x) == anc(y)) cout << "Y";
		else cout << "N";
		cout << endl;
	}
};

int main() {
	int n, m;
	int x, y, z;
	cin >> n >> m;
	unionFind u;
	while(m--) {
		cin >> z >> x >> y;
		if (z == 1) u.uni(x, y);
		else u.ask(x, y);  
	}
	return 0;
}
