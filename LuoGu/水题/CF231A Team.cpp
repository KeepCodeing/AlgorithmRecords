#include <iostream>
using namespace std;

// Ë®ÌâµÚ°Ëµ¯... 

int main() {
	int n, cnt = 0;
	cin >> n;
	int x, y, z;
	while (n--) {
		cin >> x >> y >> z;
		if (x + y + z >= 2) cnt++;
	}
	cout << cnt;
	return 0;
}
