#include <iostream>
#include <cmath>
#define endl '\n'
using namespace std;
int cnt = 0;

void fn(int n, int t, int tn) {
	
	for (int i = t; i <= n / 2; i++) {
		cout <<  tn<< endl;
		fn(n, i + 1, pow(10, i) + n);
		cnt++;
	}
}

int main() {
	int n;
	cin >> n;
	fn(n, 0, n);
	cout << cnt << endl;
	return 0;
}
