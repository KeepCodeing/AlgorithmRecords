#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	string a, b;
	cin >> a >> b;
	if (b[0] == '0' || a.size() != b.size()) {
		cout << "WRONG_ANSWER" << endl;
		return 0;
	}
	if (a[0] == '0' && b[0] == '0') {
		cout << "OK" << endl;
		return 0;
	}
	sort(a.begin(), a.end());
	int idx = 0;
	while (a[idx] == '0') idx++;
	swap(a[idx], a[0]);
	cout << (a == b ? "OK" : "WRONG_ANSWER") << endl;
	// STL算法太粪了w，不知道为什么坠毁了，还是用循环等模拟算了 
//	int zeroIndex = a.find_last_of("0");
//	string zeros;
//	if (zeroIndex != a.npos) for (int i = 0; i <= zeroIndex; i++) zeros += "0";
//	if (zeroIndex != a.npos && a.substr(zeroIndex + 1).insert(1, zeros.c_str(), zeroIndex + 1) == b) cout << "OK" << endl; 
//	else cout << (a == b ? "OK" : "WRONG_ANSWER") << endl;
	// cout << a << endl;
	return 0;
}
