#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int > vec;
int main() {
	int n, m;
	cin >> n >> m;
	while (n--) {
		int t;
		cin >> t;
		vec.push_back(t); 
	}
	do {
		if (m <= 0) break;
		m--;
	} while (next_permutation(vec.begin(), vec.end()));
	int vLen = vec.size();
	for (int i = 0; i < vLen; i++) {
		cout << vec[i];
		if (i != vLen - 1) cout << ' ';
	}
	return 0;
}
