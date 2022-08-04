#include <iostream>
#include <algorithm>
#include <set>
#define endl '\n'
using namespace std;
set<string > ss;
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	string str;
	cin >> n;
	while (n--) {
		cin >> str;
		sort(str.begin(), str.end());
		ss.insert(str); 
	}
	cout << ss.size() << endl;
	return 0;
}
