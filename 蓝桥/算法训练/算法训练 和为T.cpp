#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int cnt = 0;
vector<int > res; 
void dfs(int level, int deepth, long num, long arr[], long target) {
	if (num == target && res.size() > 0) {
		int rLen = res.size();
		for (int i = 0; i < rLen; i++) {
			cout << res[i];
			if (i != rLen - 1) cout << ' ';
		}
		cnt++;
		cout << endl;
		return;
	}
	for (int i = level; i <= deepth; i++) {
		if (num + arr[i] > target) continue;
		res.push_back(arr[i]); 
		dfs(i + 1, deepth, num + arr[i], arr, target);
		res.pop_back();
	}
}

int main() {
	long n, target;
	cin >> n;
	long arr[n + 1];
	for (int i = 1; i <= n; i++) cin >> arr[i];
	cin >> target;
	dfs(1, n, 0, arr, target);
	cout << cnt;
	return 0;
}
