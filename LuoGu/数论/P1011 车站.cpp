#include <iostream>
using namespace std;
int *station;
int main() {
	int a, n, m, x;
	cin >> a >> n >> m >> x;
	station = new int[n + 1];
	station[1] = station[2] = a;
	for (int i = 3; i <= n; i++) {
		station[i] = station[i - 1] + station[i - 2];
	}
	for (int i = 1; i <= n; i++) cout << station[i] << ' ';
	delete[] station;
	return 0;
}
