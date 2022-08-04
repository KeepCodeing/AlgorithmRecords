#include <iostream>
using namespace std;
// 给定一个字符串，要求不使用额外的存储空间判断是否有字符重复
// 思路，可以先判断是ASCII码还是UTF码，然后用一个数组标记已经出现过的字符，在后续判断中判断该字符出现过
// 没即可 
int main() {
	string str = "WORLD";
	int temp[128] = {0};
	for (int i = 0; i < str.size(); i++) {
		if (temp[(int)str[i]] != 0) {
			cout << "can not!" << endl;
			break;
		}
		// 这里将字符的ASCII码作为数组的下标 
		temp[(int)str[i]] = 1;
	}
	return 0;
} 
