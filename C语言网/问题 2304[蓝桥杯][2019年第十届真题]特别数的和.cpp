#include <iostream>
using namespace std;
bool isNum(int x) {
	return x == 0 || x == 1 || x == 2 || x == 9;
}
int check(int x) {
	int res = 0;
	int tx = x;
	while (x) {
		// ��Ȼ�Ѽ�ԭ�������˼�ÿһλ����... 
		if (isNum(x % 10)) {
			res += tx;
			break;
		}
		x /= 10;
	}
	return res;
}
int main() {
	int n;
	cin >> n;
	unsigned long long ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += check(i);
	}
	cout << ans;
	return 0;
}
