#include <iostream>
#include <algorithm>
using namespace std;
int E[11];
struct p {
	int w, id, d;
	p(int w1 = 0, int i = 0, int d1 = 0) {
		w = w1, id = i, d = d1;
	}
	bool operator<(const p& per) {
		if (w != per.w) return w > per.w;
		return id < per.id;
	}
};
int main() {
	int n, k;
	cin >> n >> k;
	p *per = new p[n];
	for (int i = 0; i < 10; i++) cin >> E[i];
	for (int i = 0; i < n; i++) {
		cin >> per[i].w;
		per[i].id = i + 1;
	}
	sort(per, per + n);
	for (int i = 0; i < n; i++) {
		per[i].d = i % 10;
		per[i].w += E[per[i].d];
	}
	sort(per, per + n);
	for (int i = 0; i< k; i++) {
		cout << per[i].id;
		if (i != k - 1) cout << ' '; 
	}
	return 0;
}
