#include <iostream>
using namespace std;
int main() {
	char start, end = 'A', t;
	int m, n;
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		start = 'A';
		t = end;
		for (int j = 0; j < i; j++) {
			cout << t;
			t--;
		}
		for (int k = 0; k < n - i; k++) {
			start++;
		}
		end++;
		cout << endl;
	}
	return 0;
}
