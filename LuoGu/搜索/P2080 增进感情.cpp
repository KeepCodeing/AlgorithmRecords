#include <iostream>
#include <cmath>
using namespace std;

// 是裸的爆搜题，但是还是有点剪枝技巧
// 对于这题而言，剪枝的条件是已经出现了最优解（这当然是所有爆搜问题都要的剪枝w），而其一开始想的出现最优解的
// 条件是当当前好感度只差已经大于答案时，进行剪枝。这个方法有些题可以用，有些题不能用，因为数据的特殊性。
// 剪枝还是得根据题目给的条件来，比如这个题就是根据答案进行剪枝 

const int N = 35;
typedef pair<int, int > PII;
PII nums[N];
bool flag = false;
int n, v;
int getAbs(int a, int b) {
	return abs(a - b);
}
int res = 0x3fffffff;
void dfs(int level, int deepth, int va, int vb) {
	if (level == deepth) {
		int vi = getAbs(va, vb);
		if (va + vb >= v) flag = true, res = min(res, vi);
		return;
	}
	// 一个小剪枝，不加这个会TLE，这个剪枝的意思是当好感度相差已经最小的时候，就不进行搜索了 
	if (!res) return;
	for (int i = level; i < deepth; i++) {
		dfs(i + 1, deepth, va + nums[i].first, vb + nums[i].second);
	}
}
int main() {
	cin >> n >> v;
	for (int i = 1; i <= n; i++) cin >> nums[i].first >> nums[i].second;
	dfs(1, n + 1, 0, 0);
	if (flag) cout << res;
	else cout << -1;
	return 0;
}
