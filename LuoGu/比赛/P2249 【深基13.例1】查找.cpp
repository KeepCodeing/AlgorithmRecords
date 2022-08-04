#include <iostream>
#include <vector>
using namespace std;
vector<int > vec;
int main() {
	int n, m;
	int t;
	cin >> n >> m;
	int index;
	while(n--) cin >> t, vec.push_back(t);
	while(m--) {
		cin >> t;
		index = lower_bound(vec.begin(), vec.end(), t) - vec.begin();
		if (t == vec[index]) cout << index + 1 << ' ';
		else cout << -1 << ' ';
	}
	return 0;
}
