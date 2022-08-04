#include <iostream>
#include <algorithm>
using namespace std;
bool isNum(char c) {
	return c >= '0' && c <= '9';
}
bool isAlpha(char c) {
	return c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z';
}
int main() {
	int p1, p2, p3;
	cin >> p1 >> p2 >> p3;
	string str, result;
	cin >> str;
	int sLen = str.size();
	for (int i = 0; i < sLen; i++) {
		if (str[i] == '-') {
			// 考虑到字符串首尾可能出现-，但是这样无法
			// 处理的情况 
			if (i != 0 && i != sLen - 1) {
				char left = str[i - 1], right = str[i + 1];
				// 处理下右边只比左边大1的情况，即删除- 
				if (left + 1 == right) {
					continue;
				} 
				// 右边大于左边开始处理，并去掉-，否则原样加上去，这里要考虑下左边字符
				// 虽然小于右边字符但是不是同一个类型的情况，比如9-A 
				if (right > left && (isAlpha(left) && isAlpha(right) || isNum(left) && isNum(right))) {
					string temp;
					for (char j = left; j <= right; j++) {
						// p1 == 3，填充*，否则判断是否是字母，这里都判断了下p1，避免重复操作 
						char t = (p1 != 3 ? j : '*');
						if (isAlpha(t) && p1 != 3) {
							if (p1 == 1) t = tolower(t); 
							else t = toupper(t);
						}
						// 处理p2的重复 
						for (int k = 1; k <= p2; k++) {
							// 不对首尾字符进行操作，这里是因为其只会跳过-，所以要这样判断下 
							if (j == left || j == right) continue;
							temp += t;
						}
					}
					// 处理p3的倒序 
					if (p3 == 2 && p1 != 3) {
						int l = 0, r = temp.size() - 1;
						// 池沼了，这里之前写成了r++.. 
						while (l < r) swap(temp[l++], temp[r--]);
					}
					result += temp;
					continue;
				}
			}
		}
		result += str[i];
	}	
	cout << result;
	return 0;
}
