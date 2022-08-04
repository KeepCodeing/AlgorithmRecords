#include <iostream>
using namespace std;

// 每次的操作：先用原苹果数减去原苹果数%n，再用这个苹果数减去这个苹果数/n 

int main() {
	int n, m;
	cin >> n >> m;
	for (int j = 1;; j++) {
		int pg = j;
		for (int i = 0; i < n; i++) {
			if (pg % n != m) continue; 
			int t = (pg - (pg % n));
			pg = (t - (t / n));
		}
		if (pg % n == m) {
			cout << j;
			break;
		} 
	}
	return 0;
}
/*
15622 12496
15622 9996
15622 7996
15622 6396
15622 5116
15622
*/
