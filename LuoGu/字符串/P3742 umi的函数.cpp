#include <iostream>
using namespace std;

// ������ͬ���䣬���x����ȡy���������޽� 

int main() {
	int n;
	cin >> n;
	string x, y;
	cin >> x >> y;
	for (int i = 0; i < n; i++) {
		if (x[i] < y[i]) {
			cout << -1;
			return 0;
		}
	}
	cout << y;
	return 0;
}
