#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
bool isPrime(int n) {
	// 没有考虑到n<=1的情况.. 
	if (n <= 1) return false;
	int k = (int)sqrt((double)n);
	for (int i = 2; i <= k; i++) {
		if (n % i == 0) return false;
	}
	return true;
}
int main() {
	int n, t;
	vector<int > result;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t;
		if (isPrime(t)) result.push_back(t);
	}
	int rSize = result.size();
	for (int i = 0; i < rSize; i++) {
		cout << result[i];
		if (i != rSize - 1) cout << ' ';
	}
	return 0;
}
