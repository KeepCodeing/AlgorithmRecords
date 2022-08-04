#include <iostream>
#include <map>
using namespace std;
map<string, int > m;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); 
	string str;
	cin >> str;
	// 注意substr的用法，开头位置不变，变得是截取长度 
	int sLen = str.size(); 
	for (int i = 0; i <= sLen; i++) {
		for (int j = 1; j <= sLen - i; j++) {
			m[str.substr(i, j)]++;
		}
	}
	int maxLen = -1;
	for (map<string, int>::iterator it = m.begin(); it != m.end(); it++) {
		if (it->second > 1) {
			// 奇妙的错误，在这种循环结构里不能直接用类似maxLen < it->first.size()的方式对比大小，不知道是不是
			// 优先级问题，总之很难发现... 
			int sl = it->first.size();
			if (sl > maxLen) {
				maxLen = sl;
			}
		}
	}
	cout << maxLen;
	return 0;
} 
