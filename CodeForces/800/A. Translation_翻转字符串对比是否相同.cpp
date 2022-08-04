#include <iostream>
#include <algorithm>
using namespace std;

// 可以不翻转直接头尾对比，不过感觉这样麻烦点... 

int main() {
	string a, b;
	cin >> a >> b;
	int left = 0, right = b.size() - 1;
	while (left < right) swap(b[left++], b[right--]);
	if (a == b) cout << "YES";
	else cout << "NO";
	cout << endl;
	return 0;
}
