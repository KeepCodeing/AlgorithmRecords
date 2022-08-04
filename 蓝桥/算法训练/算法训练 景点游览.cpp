#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int > vec;
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	int n, t;
	cin >> n;
	while(n--) cin >> t, vec.push_back(t);
	sort(vec.begin(), vec.end(), cmp);
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i];
		if (i != vec.size() - 1) cout << ' ';
	}
}
