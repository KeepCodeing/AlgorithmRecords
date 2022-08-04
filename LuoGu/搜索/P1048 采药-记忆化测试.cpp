#include <iostream>
using namespace std;
int t, m;
int maxValue = -1;
struct element {
	int ti, va;
	element(int t = 0, int v = 0) {
		ti = t, va = v;
	}
};
element *el;
void dfs(int level, int deepth, int leftTime, int temp, int v) {
	if (level == deepth || leftTime <= 0) {
		if (leftTime < 0) v -= temp;
		if (v > maxValue) maxValue = v;
		return;
	}
	for (int i = level; i < deepth; i++) {
		dfs(i + 1, deepth, leftTime - el[i].ti, el[i].va, v + el[i].va);
	}
}

int main() {
	cin >> t >> m;
	el = new element[m];
	for (int i = 0; i < m; i++) cin >> el[i].ti >> el[i].va;
	dfs(0, m, t, 0, 0);
	cout << maxValue;
	delete[] el;
	return 0;
}
