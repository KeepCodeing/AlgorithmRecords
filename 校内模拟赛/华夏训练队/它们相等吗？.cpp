#include <iostream>
#include <map>
#define endl '\n'
using namespace std;
map<char, char > mp;
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	string a, b;
	cin >> a >> b;
	for (int i = 0; i < a.size(); i++) {
		if (!mp.count(a[i])) {
			mp[a[i]] = b[i];
		} else {
			if (mp[a[i]] != b[i]) {
				cout << "No";
				return 0;
			}	
		}
	}
	cout << "Yes";
	return 0;
}
