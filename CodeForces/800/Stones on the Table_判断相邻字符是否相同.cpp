#include <iostream>
using namespace std;

// 想复杂了，甚至以为这个题是个贪心什么的，看了下题解原来就是判断下一个字符和当前字符是否相同... 
// 而且也没必要真的换颜色什么的，统计下数量就行了... 

int main() {
	string str;
	cin >> str;
	int sLen = str.size(), cnt = 0;
	for (int i = 0; i < sLen - 1; i++) {
		if (str[i] == str[i + 1]) cnt++;
	}
	cout << cnt << endl;
	return 0;
}
