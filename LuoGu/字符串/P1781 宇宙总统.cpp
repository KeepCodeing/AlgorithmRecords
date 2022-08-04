#include <iostream>
#include <algorithm>
using namespace std;

// 应该可以用字符串排序的方法来解 

struct voter {
	string str;
	int id;
	voter(string s = "", int i = 0) {
		str = s, id = i;
	}
	bool operator<(const voter& v) {
		// 字符串比较大小：如果长度相同，比较ASCII码 
		if (str.size() == v.str.size() && str > v.str) return str > v.str;
		// 否则比较长度 
		return str.size() > v.str.size();
	}
};
voter *v;
int main() {
	int n;
	cin >> n;
	v = new voter[n];
	for (int i = 0; i < n; i++) {
		cin >> v[i].str;
		v[i].id = i + 1;
	}
	sort(v, v + n);
	cout << v[0].id << endl << v[0].str;
	delete[] v;
	return 0;
}
