#include <iostream>
using namespace std;
// 给定一个字符串，如1000100001000，给定一个k，如3，要求将连续的k个0消除
// 上例返回1100001
// 思路:利用两个变量记录第一次出现0的下标和最后一次出现0的下标，再判断
// 这两个下标相减是否等于k-1（下标从0开始），如果等于，利用replace方法
// 将从开头到结尾的字符替换为空字符，最终重置起始和结尾，继续遍历，直到字符串结束 
int main() {
	string s, result;
	int k;
	cin >> s >> k;
	int start = -1, end = -1;
	// 故意增加一个字符来处理最后一串字符 （不需要，因为最后一个字符是'/0'，所以不算越界） 
	// s += '*';
	for (int i = 0; i <= s.size(); i++) {
		if (s[i] == '0' && start == -1) start = i;
		if (s[i] == '0' && start != -1) end = i;
		if (s[i] != '0' && start != -1 && end != -1) {
			if ((end - start) == (k - 1)) {
				s.replace(start, k, "");
			}
			start = end = -1;
		}
	}
	cout << s;
	return 0;
}
