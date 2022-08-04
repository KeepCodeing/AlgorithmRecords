#include <iostream>
#include <map>
using namespace std;

// 看起来像是用桶排，但是数据量太多可能不可行，所以
// 得用map 

map<int, int > mp;
int main() {
	int n;
	cin >> n;
	int t;
	for (int i = 1; i <= n; i++) {
		cin >> t;
		mp[t] = i;
	}
	int q;
	cin >> q;
	while (q--) {
		cin >> t;
		// 奇妙深刻，原来不是打完了一个位置的球这个位置的球就没有了
		// 而是某个位置的球可以无限打...，因为这个全WA了（半恼） 
		// 智障了，又交了次没有删掉测试用的输出... 
		if (mp.count(t)) cout << mp[t] << endl/*, mp.erase(t)*/;
		else cout << 0 << endl;
	}
	return 0;
} 
