#include <iostream>
using namespace std;

// 因为难度是普及-，所以没有分到水题里...思路就是用HashTable或者桶计数，然后判断是否能刚好用完即可 

int bucket[30];
int main() {
	string a, b, c;
	cin >> a >> b >> c;
	for (int i = 0; i < a.size(); i++) bucket[a[i] - 'A']++;
	for (int i = 0; i < b.size(); i++) bucket[b[i] - 'A']++;
	for (int i = 0; i < c.size(); i++) bucket[c[i] - 'A']--;
	for (int i = 0; i < 26; i++) {
		if (bucket[i] != 0) {
			cout << "NO"; // 要求正好用完所有字符... 
			return 0;
		}
	}
	cout << "YES";
	return 0;
}
