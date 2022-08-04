#include <iostream>
using namespace std;

// 一眼以为是个贪心题，结果不是.. 

int *arr;
int minHight = 1145141919;
void dfs(int level, int deepth, int hight, int SumH) {
	// 这里没写好 
	// 这里其一直纠结在层次和深度的选择上，但是如果一定要所有数字都加上的话不一定能得到最优解
	// 总之还是太依赖模板了 
	// level == deepth + 1 || 
	if (SumH >= hight) {
		minHight = min(minHight, SumH);
		// if (hight < minHight && hight >= 0) minHight = hight;
		return;
	}
	for (int i = level; i <= deepth; i++) {
		dfs(i + 1, deepth, hight, SumH + arr[i]);
	}
}

int main() {
	int n, b;
	cin >> n >> b;
	arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	dfs(0, n - 1, b, 0);
	cout << minHight - b;
	delete[] arr;
	return 0;
}
