#include <iostream>
#include <algorithm> 
using namespace std;

// 首先考虑搜索顺序，根据剪枝策略来看，节点越少的路径越优先遍历
// 而车的容积是一定的，那么猫越重其产生的分支就会越少，所以搜索
// 顺序是从大到小 

const int N = 20;
int cats[N];
bool cmp(int a, int b) {return a > b;}
int ans = N;
int n, w;
bool used[N];
void dfs(int level, int deepth, int sw) {
	cout << sw << endl;
	if (sw <= w && sw != 0) used[level] = true;
	if (sw > w) {
		ans++;
		used[level] = true;
		return;
	}
	for (int i = level; i < deepth; i++) {
		if (!used[i])
		dfs(i + 1, deepth, sw + cats[i]);
	}
} 
int main() {
	cin >> n >> w;
	for (int i = 0; i < n; i++) cin >> cats[i];
	// 从大到小排序，优化搜索顺序，我谔谔，因为下标从1开始所以排序
	// 也得从1开始排，比较麻烦，还是从0开始算了 
	sort(cats, cats + N, cmp);
	// for (int i = 0; i < n; i++) cout << cats[i] << ' ';
	dfs(0, n, 0);
	cout << ans;
	return 0;
} 
/*
5 1996
1
2
1994
12
29

2
*/
