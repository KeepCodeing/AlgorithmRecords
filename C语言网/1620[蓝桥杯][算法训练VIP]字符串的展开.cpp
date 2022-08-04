#include <iostream>
#include <algorithm>
using namespace std;

// 谔谔，和洛谷上的那个题一模一样... 

bool isAlpha(char c) {
	return c >= 'a' && c <= 'z';
} 
bool isNum(char c) {
	return c >= '0' && c <= '9';
}
int main() {
	int p1, p2, p3;
	string str;
	string result;
	cin >> p1 >> p2 >> p3;
	cin >> str;
	int sLen = str.size();
	// 首先考虑下-出现在开头和末尾，这种情况是无法进行展开的 
	for (int i = 0; i < sLen; i++) {
		if (i != 0 && i != sLen - 1) {
			if(str[i] == '-') {
				// 获取-号前后字符
				char left = str[i - 1], right = str[i + 1];
				// 如果同为字母或者数字才进行操作，不然形如a-1的字符串会展开错误 
				if (isAlpha(left) && isAlpha(right) || isNum(left) && isNum(right)) {
					// 如果right只比left大一，就跳过后面的操作，并且删除- 
					if (right - 1 == left) continue; 
					// 左边严格小于右边，执行后续操作 
					if (right > left) {
						string tStr = "";
						// 对每位字符都进行操作
						// 注意开头和结尾的字符不参与展开 
						for (char j = left + 1; j <= right - 1; j++) {		
							// 处理p1的三种情况，大写，小写，* 
							char temp;
							if (p1 != 3) temp = (isAlpha(j) ? (p1 == 2 ? toupper(j) : j) : j);
							else temp = '*';
							// 执行p2的重复
							for (int i = 0; i < p2; i++) tStr += temp;
						} 
						// 执行翻转操作，这里可以判断下p1的值，全是*没必要翻转 
						if (p3 == 2 && p1 != 3) {
							// 双指针
							int leftIndex = 0, rightIndex = tStr.size() - 1;
							while (leftIndex < rightIndex) swap(tStr[leftIndex++], tStr[rightIndex--]); 
						} 
						// 加上处理后的结果 
						result += tStr;
						continue;
					}
				} 
			}
		}
		result += str[i];
	}
	cout << result;
	return 0;
}
