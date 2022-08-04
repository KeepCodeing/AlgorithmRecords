#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

// 突然回想起了map按value排序的方法，试下能不能过 
// 写了会发现坠毁了，因为不会固定某个结构体

map<string, int > m;
vector<string > res;
void readstr(string& str) {
	char c;
	while ((c = getchar()) != '\n') str += c;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	// getline()会把这个回车给吃了，所以的加个getchar抵消 
	int maxCnt = -1;
	while (n--) {
		string str;
		// 题目说可以有词组，也就是用空格隔开的一行字符串... 
		readstr(str);
		// cout << endl << str << endl;
		m[str]++;
		maxCnt = max(maxCnt, m[str]);
	}
	for (map<string, int >::iterator it = m.begin(); it != m.end(); it++) {
		cout << it->first << ' ' << it->second << endl;
		if (it->second == maxCnt) res.push_back(it->first); 
	}
	sort(res.begin(), res.end());
	int rLen = res.size();
	cout << endl;
	for (int i = 0; i < rLen; i++) {
		cout << res[i];
		if (i != rLen - 1) cout << endl;
	}
	return 0;
}
/*
5 
red 
blue 
black 
black 
blue
*/
