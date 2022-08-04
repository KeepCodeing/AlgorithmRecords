#include <iostream>
#include <vector>
using namespace std;
vector<long > vec;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	while (n--) {
		long x;
		cin >> x;
		vec.push_back(x); 
	}
	
	while (m--) {
		int idx;
		cin >> idx;
		cout << vec[idx - 1] << endl;
	}
	return 0;
}
