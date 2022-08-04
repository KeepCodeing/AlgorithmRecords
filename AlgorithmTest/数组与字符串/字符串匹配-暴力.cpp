#include <iostream>
using namespace std;

// 暴力解法，时间复杂度为O(m*n) 
int strCmp(const char *str, const char *target) {
	if (!*target) return -1;
	char *p = (char*)str;
	int index;
	while (*p) {
		index = 1;
		char *start = p, *temp = (char*)target;
		while (*start && *temp && *start == *temp) {
			start++, temp++, index++;
		}
		if (!*temp) return index;
		p++;
	}
}
// 借助hash来对比字符串的算法，时间复杂度为O(m+n)
// 思路：假如原字符串为"1234"，要匹配的字符串为"23"，
// 取hash("12")与hash("23")，进行对比，如果hash相同，
// 进行准确的按位对比，而hash不同，向后移动为hash("23")，
// 以此类推，直到对比完成。
// 可以看成一个滑动窗口，窗口大小为n，每次向后滑动1个单位
// 然后对比hash值，相同则继续对比窗口内容 
int main() {
	cout << strCmp("Hello World", "World");
	return 0;
}
