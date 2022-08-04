#include <iostream>
using namespace std;

// 看了半天才看懂题意w，意思是不能有大于等于7个元素连在一起...
// 比较好想的是暴力，这个复杂度完全没问题，不过更聪明的做法是双指针，这个题很类似
// 那个压缩字符串的题，即统计有多少个元素重复，然后用数字代替... 

int main() {
	string str;
	cin >> str;
	bool flag = false;
	int left = 0, right = 0, sLen = str.size();
	// 全部元素对比完了才退出.. 
	while (left < sLen) {
		// 右指针和真正区间会有个差为1，当第一个不同元素出现时，right其实已经是不同元素那个
		// 位置了... 
		while (str[left] == str[right]) right++;
		// 做差，这样减出来可以保证区间是自然的，因为right比实际位置大1 
		if (right - left >= 7) {
			flag = true;
			break;
		}
		// 从第一个不同的元素开始继续往后扫 
		left = right;
	}
	if (flag) cout << "YES";
	else cout << "NO";
	cout << endl;
	return 0;
}
