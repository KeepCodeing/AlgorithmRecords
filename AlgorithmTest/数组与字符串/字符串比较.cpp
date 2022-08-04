#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

// 字符串对比方法1：排序 
// 时间复杂度O(nlogn) 
bool checkStrSort(string str1, string str2) {
	if (str1.length() != str2.length()) return false;
	sort(str1.begin(), str1.end());
	sort(str2.begin(), str2.end());
	return str1 == str2;
}


// 字符串对比方法2：Map统计字符个数
// 假设字符串长为m，遍历需要O(n)，所以时间复杂度为O(m + n)
bool checkStrMap(string str1, string str2) {
	if (str1.length() != str2.length()) return false;
	map<char, int> m, m2;
	for (int i = 0; i < str1.length(); i++) {
		m[str1[i]]++, m2[str2[i]]++;
	}
	if (m.size() != m2.size()) return false;
	for (map<char, int>::iterator it = m.begin(); it != m.end(); it++) {
		if (it->second != m2[it->first]) return false;
	}
	return true;
}

int main() {
	cout << checkStrMap("Hello", "Hello");
	return 0;
}
