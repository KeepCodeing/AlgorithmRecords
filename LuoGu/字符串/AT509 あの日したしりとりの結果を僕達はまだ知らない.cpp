#include <iostream>
#include <set>
using namespace std;
set<string > sset;
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); 
	int T;
	cin >> T;
	string pre = "1919810";
	string now;
	int cnt = 1;
	while (T--) {
		cin >> now;
		// 首先，对于第一个字符串要进行特判，因为它之前就没有别的字符串了，其次，如果某个字符串
		// 出现了多次，那么不管是否是合法的，都说明有人输了 
		if (now[0] != pre[pre.size() - 1] && pre != "1919810" || sset.count(now)) {
			cout << (cnt % 2 ? "LOSE" : "WIN") << endl;
			return 0;
		}
		// 更新字符串集合、前一个单词、回合数 
		sset.insert(now), pre = now, cnt++;
	}
	cout << "DRAW" << endl;
	return 0;
}
