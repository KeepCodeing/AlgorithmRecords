#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
string *strs;
vector<string > result;
// 题目都没看完就直接开始写，题目里说的匹配字符串，其写出匹配字符了（无能） 
int main() {
	int n;
	string c;
	cin >> n;
	strs = new string[n];
	for (int i = 0; i < n; i++) cin >> strs[i];
	cin >> c;
	// 这个地方没有什么意义，完全可以先将输入数组排序完了遍历的过程中边判断边输出 
	for (int i = 0; i < n; i++) {
		// cout << strs[i].find(c) << endl;
		if (strs[i].find(c) != 0) continue;
		result.push_back(strs[i]);
	}
	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++) {
		cout << result[i];
		if (i != result.size() - 1) cout << endl;
	}
	delete[] strs;
	return 0;
}
