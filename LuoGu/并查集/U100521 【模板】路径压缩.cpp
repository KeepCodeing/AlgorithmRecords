#include <iostream>
using namespace std;

// 想着除了并查集dfs应该也能做，但实际上这样或许要对每个点
// 都进行一次dfs，这样就坠毁了... 

struct unionFind {
	int *bin;
	// 题目给的意思就是说有m个点，每个点默认指向自己
	// 但是不一定会让所有点都有祖先，那么这个点的祖先就是
	// 自己，虽然不管怎么样这个操作都有，但是这次是第一次碰到 
	unionFind(int m) {
		bin = new int[m + 10];
		for (int i = 1; i <= m; i++) {
			bin[i] = i;
		}
	}
	int anc(int x) {
		if (x == bin[x]) return x;
		bin[x] = anc(bin[x]);
		return bin[x];
	}
	void uni(int x, int y) {
		bin[anc(x)] = anc(y);
	}
	bool ask(int x, int y) {
		return anc(x) == anc(y);
	}
	~ unionFind() {
		delete[] bin;
	}
};

int n, m;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	unionFind u(m);
	while (n--) {
		int x, y;
		cin >> x >> y;
		u.uni(x, y); 
	} 
	int q;
	cin >> q;
	while (q--) {
		int op, x, y;
		cin >> op >> x;
		if (!op) {
			cin >> y;
			if (u.ask(x, y)) cout << "Yes";
			else cout << "No";
		} else {
			// 第一次碰到问祖先的题，不过模板很全可以轻松做到 
			cout << u.anc(x);
		}
		cout << endl;
	}
	return 0;
}
