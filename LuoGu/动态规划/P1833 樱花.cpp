#include <iostream>
#include <cstdio> 
#include <vector>
#include <cmath>
using namespace std;

// 事缝合背包，但是要转换下时间，这里把单位统一为分钟，然后用scanf格式化读入 
// 细节决定成败（绝望） 

const int N = 10010;
struct Cherry {
	int v, w, kind;
	Cherry(int v, int w, int kind) : v(v), w(w), kind(kind) {};
}; 
vector<Cherry > vec;
int f[N];
int main() {
	int t1, t2, m1, m2, n;
	int v; 
	scanf("%d:%d %d:%d %d", &t1, &m1, &t2, &m2, &n);
//	cout << endl;
//	printf("%d:%d %d:%d %d", t1, m1, t2, m2, n);
	// 获取背包容积 
	// 开什么玩笑（UDK饼干），之前两个运算都没加括号，就A了一个点（爆笑） 
	v = abs((t1 * 60 + m1) - (t2 * 60 + m2));
//	cout << endl << v << endl << endl;
	// 代价，价值，背包类型 
	int t, c, p;
	for (int i = 1; i <= n; i++) {
		cin >> t >> c >> p;
		if (p == 0) {
			// 完全背包
			 vec.push_back(Cherry(t, c, 0)); 
		} else {
			if (p > 1) {
				// 多重背包 
				for (int k = 1; k <= p; k <<= 1) {
					vec.push_back(Cherry(t * k, c * k, 1));
					p -= k; 
				}
				if (p > 0) vec.push_back(Cherry(t * p, c * p, 1)); 
			} else {
				// 01背包 
				vec.push_back(Cherry(t, c, 1)); 
			}
		}
	}
	// 套模板
	int vLen = vec.size();
	for (int i = 0; i < vLen; i++) {
		// 处理01背包和多重背包 
		if (vec[i].kind) {
			for (int j = v; j >= vec[i].v; j--) {
				f[j] = max(f[j], f[j - vec[i].v] + vec[i].w);
			}
		} else {
			// 处理完全背包 
			for (int j = vec[i].v; j <= v; j++) {
				f[j] = max(f[j], f[j - vec[i].v] + vec[i].w);
			}
		}
	} 
	cout << f[v];
	return 0;
}
