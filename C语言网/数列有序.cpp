#include <iostream>
using namespace std;
int main() {
	int n, x, t;
	bool flag;
	while (cin >> n >> x, n != 0 && x != 0) {
		flag = true;
		while (n--) {
			cin >> t;
			if (t >= x && flag) cout << x << ' ', flag = false;
			cout << t << ' ';
		}
		cout << endl;
	}
	return 0;
}
