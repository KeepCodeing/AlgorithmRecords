#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

// https://www.luogu.com.cn/problem/P3366

const int N = 5e3 + 10;
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
		int a = anc(x), b = anc(y);
		bin[a] = b;
	}
	bool ask(int x, int y) {
		return anc(x) == anc(y);
	}
};

struct Node {
	int ut, vt, wt;
	bool operator<(const Node& n) const {
		return wt < n.wt;
	}
} root[N];

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m, ut, vt, wt;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> root[i].ut >> root[i].vt >> root[i].wt;
	}
	unionFind uf;
	int res = 0;
	for (int i = 0; i < m; i++) {
		if (!uf.ask(root[i].ut, root[i].vt)) {
			uf.uni(root[i].ut, root[i].vt); 
			res += root[i].wt;
			// n--;
			// n个点的MST只可能有n - 1条边 
			// 
			// if (n == 1) break;
		}
	}
//	if (n > 1) cout << "orz";
//	else cout << res << endl;
	cout << res << endl;	
	return 0;
}
