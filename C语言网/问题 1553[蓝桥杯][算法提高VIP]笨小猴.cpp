#include <iostream>
#include <cmath>
using namespace std;
int bucket[26];
bool isPrime(int x) {
	if (x <= 1) return false;
	int k = sqrt(x);
	for (int i = 2; i <= k; i++) {
		if (x % i == 0) return false;
	}
	return true;
}
int main() {
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		bucket[str[i] - 'a']++;
	}
	int maxn = -1, minn = 0x3fffffff;
	for (int i = 0; i < 26; i++) {
		maxn = max(maxn, bucket[i]);
		if (bucket[i] > 0) minn = min(minn, bucket[i]);
	}
	int ans = maxn - minn;
	if (isPrime(ans)) {
		cout << "Lucky Word" << endl << ans;
	} else {
		cout << "No Answer" << endl << 0;
	}
	return 0;
}
