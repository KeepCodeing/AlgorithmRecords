#include <iostream>
#include <vector>
using namespace std;

// 乍一看是个多重背包求方案数，但是可以把多重背包直接改成01背包，不过直接求很可能会超时w 

const int N = 500010;
vector<int > vec;
int f[N];
int main() {
	int k, n;
	cin >> k >> n;
	// 多重背包转01背包，别的题里面都是用个结构体把价值，收益存起来，这个题就只用存价值 
	for (int i = 1; i <= n; i++) {
		int x, t = k;
		cin >> x;
		// for (int j = 1; j <= t; j++) vec.push_back(x); 
		for (int j = 1; j <= t; j <<= 1) {
			vec.push_back(x * j);
			t -= j;
		}
		if (t > 0) vec.push_back(x * t); 
	}
	int vLen = vec.size();
	for (int i = 0; i < vLen; i++) cout << vec[i] << endl;
	int num = 1;
	while (true) {
		fill(f, f + num + 10, 0);
		f[0] = 1;
		for (int i = 0; i < vLen; i++) {
			for (int j = num; j >= vec[i]; j--) {
				f[j] += f[j - vec[i]];
			}
		}
		if (num == 14) cout << f[num] << endl;
		if (!f[num]) break;
		num++;
	}
	cout << num;
	return 0;
}
