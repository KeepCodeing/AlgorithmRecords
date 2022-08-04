#include <iostream>
using namespace std;

struct unionFind {
	int bin[120];
	unionFind() {
		for (int i = 1; i <= 120; i++) bin[i] = i;
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
};

int main() {
	int n, k;
	cin >> n >> k;
	while (k--) {
		int x, y;
		cin >> x >> y;
		
	}
	return 0;
}
