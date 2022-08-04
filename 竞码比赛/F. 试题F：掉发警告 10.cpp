#include <iostream>
using namespace std;
unsigned long long res;
int main() {
	int n;
	cin >> n;
	int a = 1, b = 2;
	int day = 1;
	for (int i = 3; i <= n; i++) {
		res = a + b;
		a = b, b = res;
		if (i >= 6) {
			day *= 2;
			res -= day - 1;
			
		}
	}
	cout << res;
	return 0;
}
//#include <iostream>
//using namespace std;
//unsigned long long ans[60];
//int main() {
//	int n;
//	cin >> n;
//	int cnt = 0;
//	int day = 0;
//	ans[0] = 1;
//	for (int i = 1; i <= n; i++) {
//		if (i > 3) cnt++;
//		if (i % 3 == 0) day++;
//		ans[i] = ans[i - 1] + day + cnt;
//	}
//	cout << ans[n];
//	return 0;
//}
