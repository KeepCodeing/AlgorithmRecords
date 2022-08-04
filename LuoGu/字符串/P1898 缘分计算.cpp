#include <iostream>
#include <algorithm>
using namespace std;
void sw(char& a, char &b) {
	char t;
	t = a, a = b, b = t; // 
}
void rev(string& str) {
	int l = 0, r = str.size() - 1;
	while (l < r) swap(str[l++], str[r--]); // 利用双指针算法旋转字符串 
}

int main() {
	int st;
	string str, res, temp;
	cin >> str >> st;
	int t, sLen = str.size();
	for (int i = 0; i < sLen; i++) {// 数位分离转成字符串，为了方便这里还得来次翻转 
		t = st + str[i] - 'A', temp = "";
		while (t) temp += (char)(t % 10 + '0'), t /= 10;
		rev(temp), res += temp;// 翻转我们得出来的数字
	}
	int rLen;
	while (true) { // 循环处理，直到出现了合法解
		temp = "";
		rLen = res.size();
		if (rLen <= 3) {
			if (res == "100") break;
			else if (rLen <= 2) break;
		}
		for(int i = 0; i < rLen - 1; i++) temp += (char)((res[i] - '0' + res[i + 1] - '0') % 10 + '0'); // 按题目要求取出相邻两个数的个位再把它转成字符 
		res = temp; // 更新解 
	}
	if (res[0] == '0') cout << res[1]; // 特判下首字符是不是0 
	else cout << res;
	return 0;
}
