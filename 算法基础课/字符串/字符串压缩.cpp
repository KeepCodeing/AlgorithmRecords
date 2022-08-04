#include <iostream>
#include <map> 
#include <algorithm>
using namespace std;
// 给定一个字符串，如"aaaaabbbbbbbbcccc"要求返回"a4b7c3"，
// 如果不能压缩返回原字符串，即统计某个字符重复出现的次数，并将其后字符改成出现次数 
// 思路：先对某个字符进行计数，再利用replace方法替换字符 
// 自己写的整形转字符串方法，效率太低 
string int2str(int num) {
	string result;
	while (num) {
		result += (num % 10 + '0');
		num /= 10;
	}
	reverse(result.begin(), result.end());
	return result;
}
int main() {
	map<char, int > c_map;
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		c_map[str[i]]++;
	}
	for (map<char, int >::iterator it = c_map.begin(); it != c_map.end(); it++) {
		// 排除只出现过一次的字符 
		if (it->second == 1) continue;
		int index = str.find(it->first);
		// 从第一个字符串之后到最后一个字符串都替换成该字符的出现次数 
		str.replace(index + 1, it->second - 1, int2str(it -> second - 1));
	}
	cout << str << endl;
	return 0;
}
