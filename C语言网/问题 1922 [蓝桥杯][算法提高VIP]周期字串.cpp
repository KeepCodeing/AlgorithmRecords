#include <iostream>
using namespace std;

// 似乎就是“现代诗如蚯蚓”哪一题的思路，按步长截取，然后判断 

bool solve(string cmpStr, int step, int sLen, string str) {
	for (int j = 0; j < sLen; j += step) {
		if (cmpStr != str.substr(j, step)) return false;
	}
	return true;
}

int main() {
	string str;
	cin >> str;
	int sLen = str.size();
	for (int i = 1; i <= sLen; i++) {
		string cmpStr = str.substr(0, i);
		if (sLen % cmpStr.size() != 0) continue;
		if (solve(cmpStr, i, sLen, str)) {
			// 没有注意到循环为一的情况（选择性以为是0），还有就是有点忘了cmpStr这个参数
			// 怎么来的，其实因为这个字符串是个循环的，所以截取到某个位置一定能找到重复的
			// 那个字符串 
			cout << cmpStr.size();
			break;
		}
	}
	return 0;
}
