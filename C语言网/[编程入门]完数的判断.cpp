#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int nums[N];
int main() {
	int T, sum, cnt;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		sum = cnt = 0;
		for (int j = 1; j < i; j++) {
			if (i % j == 0) sum += j, nums[cnt++] = j;
		}
		if (sum == i) {
			cout << i << " its factors are ";
			for (int j = 0; j < cnt; j++) cout << nums[j] << ' ';
			cout << endl;
		}
	}
	return 0;
}
