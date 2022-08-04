#include <iostream>
using namespace std;
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	// 主要是注意0的情况，但是这种情况也可以加入到加班人数
	// 全都相等的情况 
	if (a == b && b == c) {
		cout << a;
		return 0;
	}
	for (int i = 1; i <= 10000000; i++) {
		// 都能分到，注意是从小到大模 
		if (i % a == 0 && i % b == 0 && i % c == 0) {
			cout << i;
			break;
		}
	}
	return 0;
}
