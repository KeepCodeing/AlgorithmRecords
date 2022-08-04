#include <iostream>
#include <vector>
using namespace std;
vector<int > vec;
int main() {
	int n, minNum = 0x3FFFFFFF, maxNum = -1000000, tot = 0;
	int t;
	cin >> n;
	while (n--) cin >> t, minNum = min(minNum, t), maxNum = max(maxNum, t), tot += t;
	cout << maxNum << endl << minNum << endl << tot;
	return 0;
}
