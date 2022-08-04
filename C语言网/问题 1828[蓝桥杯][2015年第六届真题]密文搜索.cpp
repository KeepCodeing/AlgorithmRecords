#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
set<string > s;
int main() {
	// 许多长度为8的密码列表，也就是说可以把原串切分成
	// 许多个长度为8的子字符串，然后生成密码的全排列
	// 去对比，为了方便，可以把子字符串插入到一个set里 
	string str;
	cin >> str;
	int sLen = str.size();
	// 这样似乎才是正确的每次移动一位截取子字符串的方法 
	for (int i = 0; i + 7 < sLen; i++) {
		s.insert(str.substr(i, 8)); 
	}
	int n;
	cin >> n;
	int ans = 0;
	while (n--) {
		string temp;
		cin >> temp;
		sort(temp.begin(), temp.end());
		do {
			// 因为第一个序列不会进行对比，所以用do while 
			if (s.count(temp)) ans++;
		} while(next_permutation(temp.begin(), temp.end()));
	}
	cout << ans;
	return 0;
}
