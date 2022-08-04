#include <iostream>
#include <vector>
using namespace std;

// 看起来可以拿来练下记忆化搜索.. 
// 调了半天，发现自己爆搜都有点倒车了w..不过以前也确实没注意过这个细节就是了.. 

const int N = 40;
int nums[N];
vector<int > vec;
void dfs(int level, int deepth, int m, int val) {
//	cout << level << endl;
//	if (level > deepth) {
//		for (int i = 0; i < vec.size(); i++) cout << vec[i] << ' ';
//		cout << endl;
//		return;
//	}
	if (m == 0) {
		cout << val << endl;
		return;
	}
	vec.push_back(level); 
	// 选当前树 
	dfs(level + 2, deepth, m - 1, val + nums[level]);
	// 不选当前树 
	dfs(level + 1, deepth, m, val);
	vec.pop_back();
	
}
void bk(int level, int deepth, int m, int val) {
	if (m == 0) {
//		cout << "eee" << endl;
		for (int i = 0; i < vec.size(); i++) {
//			res += vec[i];
			cout << vec[i] << ' ';
		}
		cout << endl;
//		cout << val << endl;
//		cout << res << endl;
		return;
	}
	if (level > deepth) {
//		if (vec.size() == 3) {
//			int res = 0;
//			
//		}
		return;
	}
	for (int i = level; i <= deepth; i++) {
		vec.push_back(i); 
		bk(i + 2, deepth, m - 1, val + nums[i]);
		vec.pop_back();
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) scanf("%d", &nums[i]);
	bk(1, n, m, 0);
//	dfs(1, n, m, 0);
	return 0;
}
