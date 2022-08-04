#include <iostream>
using namespace std;
int solve(int n) {
	int temp, t, num;
	for (int i = 10000; i <= 999999; i++) {
		t = i, temp = 0, num = 0;
		while(t) {
			temp = temp * 10 + t % 10;
			num += t % 10; 
			t /= 10;
		
		}
		if (temp == i) {
			if (num == n) cout << temp << endl;
		}
	}
}
int main() {
	int n;
	cin >> n;
	solve(n);
	return 0;
}
