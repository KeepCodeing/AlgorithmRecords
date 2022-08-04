#include <iostream>
#include <algorithm>
using namespace std;
const int N = 110, M = 30;
int son[N][M], idx = 0;
int cnt[M * N];
void add(int nums[], int k) {
	int p = 0;
	for (int i = 0; i < k; i++) {
		int cur = nums[i];
		if (!son[p][cur]) son[p][cur] = ++idx;
		p = son[p][cur];
	}
	cnt[p]++;
}
int fd(int nums[], int k) {
	int p = 0, res = 0;
	for (int i = 0; i < k; i++) {
		int cur = nums[i];
		if (!son[p][cur]) return -1;
		p = son[p][cur];
		res += cnt[p];
	}
	return res;
}
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	int nums[m + 5];
	while (n--) {
		for (int i = 0; i < k; i++) cin >> nums[i];
		sort(nums, nums + k);
//		for (int i = 0; i < k; i++) cout << nums[i] << ' ';
//		cout << endl;
		add(nums, k);
	}
	for (int i = 0; i < m; i++) nums[i] = i + 1;
	cout << fd(nums, m);
	return 0;
}
