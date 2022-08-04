#include <iostream>
using namespace std;

// 01背包，输出最小体力和宠物小精灵那题类似，但是其还是不太懂为什么（无能） 

// 状态表示f[i]，表示当前体力为i时，能获得的最大价值，因此当最大价值
// 超过了背包容积时，剩余体力就可通过总体力-当前体力获得。 

const int N = 10010;
int val[N], wei[N];
int f[N];
int main() {
	int v, n, c;
	cin >> v >> n >> c;
	for (int i = 1; i <= n; i++) cin >> wei[i] >> val[i];
	for (int i = 1; i <= n; i++) {
		for (int j = c; j >= val[i]; j--) {
			f[j] = max(f[j], f[j - val[i]] + wei[i]);
		}
	}
	bool flag = false;
	for (int i = 1; i <= c; i++) {
		if (f[i] >= v) {
			flag = true;
			// 第一个重量大于背包容积的解就是最小体力的解
			// 输出剩余的体力 
			cout << c - i;
			break;
		}
	}
	if (!flag) cout << "Impossible";
	return 0;
}
