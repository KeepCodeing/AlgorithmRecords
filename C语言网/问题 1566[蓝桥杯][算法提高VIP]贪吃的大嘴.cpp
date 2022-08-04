#include <iostream>
#include <vector>
using namespace std;

// 多重背包问题，关键在于如何判断吃了多少个蛋糕，以及美味度是否达到了m 
// 坠毁... 

const int N = 20010;
typedef pair<int, int > PII;

int f[N];
struct cookie {
	int v, w;
	cookie(int v, int w) : v(v), w(w) {};
};
vector<cookie > vec;
int main() {
	int n, v;
	cin >> v >> n;
	for (int i = 1; i <= n; i++) {
		int vi, ci;
		cin >> vi >> ci;
		for (int j = 1; j <= ci; j <<= 1) {
			vec.push_back(cookie(vi * j, 1));
			// 我谔谔，这里写成了/=，应该是用一个数少一个数 
			ci -= j;
		}
		if (ci > 0) vec.push_back(cookie(vi * ci, 1)); 
	}
	int vLen = vec.size();
	for (int i = 0; i < vLen; i++) {
		for (int j = v; j >= vec[i].v; j--) {
			f[j] = min(f[j], f[j - vec[i].v] + 1);
		}
	}
	cout << f[v];
	return 0;
} 
