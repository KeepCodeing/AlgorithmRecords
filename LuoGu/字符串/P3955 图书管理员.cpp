#include <iostream>
#include <algorithm>
using namespace std;
string *books;
bool check(string b, string str) {
	int bLen = b.size(), right = str.size() - 1;
	while (bLen--) {
		if (b[bLen] != str[right--]) return false;
	}
	return true;
}
bool cmp(string a, string b) {
	if (a.size() != b.size()) return a.size() < b.size();
	return a < b;
}
int main() {
	int n, q;
	int l;
	string b;
	bool flag;
	cin >> n >> q;
	books = new string[n];
	for (int i = 0; i < n; i++) {
		cin >> books[i];
	}
	sort(books, books + n, cmp);
	while (q--) {
		cin >> l >> b;
		flag = false;
		for (int i = 0; i < n; i++) {
			if (books[i].size() < l) continue;
			if (check(b, books[i])) {
				cout << books[i] << endl, flag = true;
				break;
			}
		}
		if (!flag) cout << -1 << endl;
	}
	delete[] books;
	return 0;
}
