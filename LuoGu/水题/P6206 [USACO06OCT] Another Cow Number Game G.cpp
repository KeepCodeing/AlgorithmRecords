#include <iostream>
using namespace std;

// ������û����ˮ����...��yy��.. 

int main() {
	unsigned long long n;
	cin >> n;
	int score = 0;
	while (n != 1) {
		if (n % 2 != 0) n = n * 3 + 1;
		else n /= 2;
		score++;
	}
	cout << score;
	return 0;
}
