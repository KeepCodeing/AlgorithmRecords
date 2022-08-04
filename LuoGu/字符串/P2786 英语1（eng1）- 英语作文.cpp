#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
const int L = 60;
char str[L];
map<string, int > mp;
bool checker(char c) {
	return c == ',' || c == '.' || c == '!' || c == '?' || c == ' ';
}
int main() {
	int n, p, v;
	scanf("%d%d", &n, &p);
	while (n--) {
		scanf("%s%d", &str, &v);
		mp[str] = v;
	}
	int res = 0;
	while (scanf("%s", &str) != EOF) {
		int last = strlen(str);
		string temp;
		bool flag = true;
		for (int i = 0; i < last; i++) {
			if (checker(str[i])) {
				res += mp[temp] % p;
			    cout << mp[temp] << ' ' << temp << endl;
				temp = "";
				flag = false;
			} else {
				temp += str[i];
			}
		}
		if (flag) res += mp[temp] % p;
	}
	cout << res % p;
	return 0;
}
