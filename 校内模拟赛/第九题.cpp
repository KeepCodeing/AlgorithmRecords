#include <iostream>
using namespace std;
bool check(float x) {
	//if ((int)x == )
}
int main() {
	int n;
	cin >> n;
	if (n <= 2) {
		cout << n;
		return 0;
	}
	int cnt = n;
	while ((n >> 1) != 1) {
		cnt += (n >> 1) + 1;
		n >>= 1;
		n++;
	}
	cout << cnt + 3;
	return 0;
}
