#include <iostream>
using namespace std;
int main() {
	// 看到字典序就知道是贪心了，之前做过一个贪心题（完全忘了w），就是
	// 要求字典序最大..那么一个位置有两种选法，选1位或选2位，前者一定存在一个可行的映射方案，后者则不一定有
	// 而题目要求的字典序最大，那么也就是要求从前往后选到的字符更靠后，也就是说尽量从两位开始选，两位不合法
	// 才选一位，这样就能保证字典序最大了..
	string str;
	cin >> str;
	int sLen = str.size();
	for (int i = 0; i < sLen; i++) {
		// 如果能选两位（也就是说还没到字符串末尾，就判断下是否合法 
		if (i + 1 < sLen) {
			// 注意这里要-1，因为下面'A'其实是默认temp从0开始的... 
			int temp = ((str[i] - '0') * 10 + str[i + 1] - '0') - 1;
			if (temp <= 26) {
				i++;
				cout << (char)('A' + temp);
			} else {
				cout << (char)('A' + (str[i] - '0'));
			}
	
		} else {
			// 如果不能选两位，就只能选一位了
			cout << (char)((str[i] - '0') + 'A'); 
		}
	}
	return 0;
}
