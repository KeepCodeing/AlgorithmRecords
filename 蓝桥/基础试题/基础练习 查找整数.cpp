#include <iostream>
#include <vector>
using namespace std;
vector<int > vec;
int main() {
	int n, t, target;
	cin >> n;
	while(n--) cin >> t, vec.push_back(t); 
	cin >> target;
	int ans = -1;
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] == target) {
			ans = i + 1;
			break;
		}
	}
	cout << ans;
	return 0;
}
