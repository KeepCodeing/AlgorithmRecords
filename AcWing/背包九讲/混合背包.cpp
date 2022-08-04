#include <iostream>
#include <vector>
using namespace std;

// 缝合背包，就是把01背包，完全背包，多重背包缝合在一起..
// 分情况套模板即可，因为多重背包可以转换为01背包，所以实际上我们只用
// 处理两种情况 

const int N = 1010;
struct Good {
	int s, v, w;
	// 啊这...这里v(v)写成了v(s)... 
	Good(int s, int v, int w) : s(s), v(v), w(w) {};
};
vector<Good > vec;
int f[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); 
	int n, v;
	cin >> n >> v;
	for (int i = 1; i <= n; i++) {
		int vi, wi, si;
		cin >> vi >> wi >> si;
		if (si == -1) {
			// 01背包直接装
			vec.push_back(Good(si, vi, wi));  
		} else if (si == 0) {
			// 完全背包也可以直接装，但是要标记下si，这两种背包都是处理的时候换模型
			vec.push_back(Good(si, vi, wi));
		} else {
			// 多重背包要处理成01背包，这里用二进制优化即可
			for (int k = 1; k <= si; k <<= 1) {
				si -= k;
				vec.push_back(Good(-1, vi * k, wi * k)); 
			} 
			// 这里应该不能偷懒写成if(si)，si如果为负if也会执行 
			if (si > 0) vec.push_back(Good(-1, vi * si, wi * si)); 
		}
		
	}
	// 分背包情况处理
	int vLen = vec.size();
	// 从0开始是因为下标 
	for (int i = 0; i < vLen; i++) {
		// 处理多重背包 
		if (vec[i].s == 0) {
			for (int j = vec[i].v; j <= v; j++) f[j] = max(f[j], f[j - vec[i].v] + vec[i].w);
		} else {
			// 处理01背包 
			for (int j = v; j >= vec[i].v; j--) f[j] = max(f[j], f[j - vec[i].v] + vec[i].w);
		}
	}
	cout << f[v];
	return 0;
}
