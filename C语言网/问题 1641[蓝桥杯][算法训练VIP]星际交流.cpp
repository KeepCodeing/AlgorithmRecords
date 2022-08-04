#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 谔谔，本来以为给的排列不一定是第一个的，但是看题解好像就是给的第一个 

vector<int > vec;
int main() {
	int n, m;
	cin >> n >> m;
	int temp;
	while (n--) cin >> temp, vec.push_back(temp);
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
