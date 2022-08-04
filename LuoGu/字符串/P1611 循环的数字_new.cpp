#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

// ×¹»Ù£¬Ìâ¶¼Ã»¶Á¶®.. 

map<string, int > mp;
string num2str(int n) {
	string str = "";
	while (n) {
		str = str + (char)(n % 10 + '0');
		n /= 10;
	}
	sort(str.begin(), str.end());
	return str;
}
int main() {
	int A, B;
	cin >> A >> B;
	for (int i = A; i <= B; i++) mp[num2str(i)]++;
	int res = 0;
	for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++) res += it->second;
	cout << res;
	return 0;
}
