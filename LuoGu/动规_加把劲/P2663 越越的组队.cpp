#include <iostream>
#define endl '\n'
using namespace std;
const int N = 110;
int nums[N], f[N * 100];

// 01背包... 

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, sum = 0, half;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		sum += nums[i];
	}
	// *不超过一半*，所以这里还得减一（不知道为什么不能等于..） 
	half = sum / 2 - 1;
	for (int i = 0; i < n; i++) {
		for (int j = half; j >= nums[i]; j--) {
			f[j] = max(f[j], f[j - nums[i]] + nums[i]);
		}
	}
	// 背包的答案应该是f[容积]，而不是f[物品个数]... 
	cout << f[half] << endl;
	return 0;
}
