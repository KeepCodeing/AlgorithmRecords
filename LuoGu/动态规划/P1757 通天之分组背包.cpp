#include <iostream>
#include <vector>
#include <set> 
using namespace std;
struct ele {
	int v, w;
	ele(int v, int w) : v(v), w(w) {};
};
// 我谔谔，居然想了半天怎么存物品，vector<vecotr> >这种形式实在不好理解，好在回想起了vector存图... 
vector<ele > vec[110];
set<int > ss;
int f[1010];
int main() {
	int n, v;
	cin >> v >> n;
	for (int i = 1; i <= n; i++) {
		int val, wei, g;
		cin >> val >> wei >> g;
		ss.insert(g); 
		vec[g].push_back(ele(val, wei)); 
	}
	// 这里之前直接写的n，这样是没考虑有多少组的，所以RE了两个点，用set存有多少组，相对来说比较奢侈，因为桶
	// 就够了 
	int vLen = ss.size();
	// 这里要注意，i表示的是当前是那一组，而题目给的组是从1开始的，所以这里i也要从1开始 
	for (int i = 1; i <= vLen; i++) {
		int eLen = vec[i].size();
		// 倒着枚举，先枚举钱，再枚举物品 
		for (int j = v; j >= 1; j--) {
			for (int k = 0; k < eLen; k++) {
				// 注意要判断下出界
				if (j >= vec[i][k].v) {
					// 谔谔，这里写成了f[k]，这里列举的不是第i个物品的最优解，而是价格为j时的最优解
					// 不管怎么说这里和01背包都是相反的顺序关系 
					f[j] = max(f[j], f[j - vec[i][k].v] + vec[i][k].w);
				} 
			}
		}
	}
	cout << f[v];
	return 0;
}
