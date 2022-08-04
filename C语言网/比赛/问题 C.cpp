#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
set<int > s;
int nums[100010], bucket[100010];
bool r(int n) {
	return s.count(n); 
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		while (r(t)) t++;
		s.insert(t);
		nums[i] = t;
	}
	for (int i = 0; i < n; i++) {
		cout << nums[i];
		if (i != n - 1) cout << ' ';
	}
	return 0;
}
