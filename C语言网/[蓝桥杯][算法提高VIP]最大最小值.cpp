#include <iostream>
using namespace std;
int main() {
	int n, mx, mm, t;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t;
		if (i == 0) mx = mm = t;
		else mx = max(mx, t), mm = min(mm, t); 
	}
	cout << mx << ' ' << mm;
	return 0;
}
