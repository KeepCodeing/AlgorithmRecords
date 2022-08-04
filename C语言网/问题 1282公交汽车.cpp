#include <iostream>
#include <vector>
using namespace std;
const int N = 110;
struct bus {
	int v, w;
	bus(int v, int w) : v(v), w(w) {};
};
vector<bus > vec;
int f[N];
int main() {
	int val;
	for (int i = 1; i <= 10; i++) {
		cin >> val;
		int cnt = 10;
		for (int k = 1; k <= cnt; k <<= 1) {
			vec.push_back(bus(val * k, k));
			cnt -= k;
		}
		if (cnt > 0) vec.push_back(bus(cnt * val, cnt)); 
	}
	int v;
	cin >> v;
	for (int i = 0; i <= 9; i++) {
		for (int j = v; j >= 1; j--) {
			f[j] = min(f[j], f[v - j] + vec[i].v * j);
		}
	}
	cout << f[v];
	return 0;
}
