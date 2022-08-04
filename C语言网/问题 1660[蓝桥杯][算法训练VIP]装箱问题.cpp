#include <iostream>
#include <vector>
using namespace std;
vector<int > vec;
int minWei = 0x3fffffff;
void dfs(int level, int deepth, int v, int pre) {
	//if (v >= minWei) return;
	if (level == deepth || v <= 0) {
		if (v < 0) v += pre;
		minWei = min(minWei, v);
		return;
	}
	for (int i = level; i < deepth; i++) {
		// 不知道为什么这个迫真剪枝不能加，或许是出口条件的原因罢 
		//if (v - vec[i] < 0) continue;
		dfs(i + 1, deepth, v - vec[i], vec[i]);
	}
}
int main() {
	int v;
	int n, t;
	cin >> v >> n;
	while (n--) cin >> t, vec.push_back(t);
	dfs(0, vec.size(), v, 0);
	cout << minWei; 
	return 0;
}
