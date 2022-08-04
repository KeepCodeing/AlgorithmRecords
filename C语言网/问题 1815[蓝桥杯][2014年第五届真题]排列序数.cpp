#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	string str;
	cin >> str;
	string temp = str;
	sort(str.begin(), str.end());
	int cnt = 1;
	// 似乎其实序列next_permutation()函数不会进行排列，所以要特判
	// 另外因为特判了其实序列，所以下标从1开始，即第二个序列 
	if (str == temp) cout << 0;
	while (next_permutation(str.begin(), str.end())) {
		if (str == temp) {
			cout << cnt;
			break;
		}
		cnt++;
	};
	return 0;
}
