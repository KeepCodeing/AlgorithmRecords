#include <iostream>
using namespace std;
int main() {
	int T, n, cnt = 0;
	cin >> T;
	while (T--) {
		cnt = 0;
		cin >> n;
		if (n != 1) {
			while (cnt <= 1000) {
				while (!(n % 6)) n /= 6, cnt++;
				if (n == 1) break;
				cout << n << endl;
//				if (cnt >= 1000) break;
			}
			if (cnt >= 1000 || n != 1) cout << -1;
			else cout << cnt << endl;
		} else {
			cout << 0 << endl;
		}
		
	} 
	return 0;
}
