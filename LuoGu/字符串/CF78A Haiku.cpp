#include <iostream>
using namespace std;

// 简单模拟即可...，CF的测试点还蛮多的... 

string strs[3];
int cnt[3];
bool isYuan(char str) {
	return str == 'a' || str == 'e' || str == 'i' || str == 'o' || str == 'u';
}
int main() {
	for (int i = 0; i < 3; i++) getline(cin, strs[i]);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < strs[i].size(); j++) {
			if (isYuan(strs[i][j])) cnt[i]++;
		}
	}
	cout << ((cnt[0] == 5 && cnt[1] == 7 && cnt[2] == 5) ? "YES" : "NO");
	return 0;
}
