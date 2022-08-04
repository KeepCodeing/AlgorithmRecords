#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int > vec;
int main() {
	int n, q;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	while (n--) {
		int x;
		cin >> x;
		vec.push_back(x); 
	} 
	sort(vec.begin(), vec.end());
	while (q--) {
		int op, k;
		cin >> op >> k;
		if (op == 1) {
			vec.insert(upper_bound(vec.begin(), vec.end(), k), k);  
		} else {
			cout << vec[k - 1] << endl;
		}
	}
	return 0;
}
