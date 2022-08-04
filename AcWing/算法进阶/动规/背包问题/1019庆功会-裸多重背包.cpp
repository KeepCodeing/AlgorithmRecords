#include <iostream>
#include <vector>
using namespace std;
const int N = 6010;
int f[N];
struct ele {
	int v, w;
	ele(int v, int w) : v(v), w(w) {};
};
vector<ele > vec;
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int v, w, s;
		cin >> v >> w >> s;
		for (int k = 1; k <= s; k <<= 1) {
			vec.push_back(ele(v * k, w * k)); 
			s -= k;
		}
		if (s > 0) vec.push_back(ele(v * s, w * s)); 
	}
	int vLen = vec.size();
	for (int i = 0; i < vLen; i++) {
		for (int j = m; j >= vec[i].v; j--) {
			f[j] = max(f[j], f[j - vec[i].v] + vec[i].w);
		}
	}
	cout << f[m];
	return 0;
}

/*
输入样例：
5 1000
80 20 4
40 50 9
30 50 7
40 30 6
20 20 1

输出样例：
1040
*/
