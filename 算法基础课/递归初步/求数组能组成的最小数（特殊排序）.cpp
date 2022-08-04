#include <iostream>
#include <algorithm>
using namespace std;
// 给出一个数组，要求输出该数组元素拼接在一起能组成的最小数
// 思路：利用sort的对比规则对元素进行操作 
bool s(int a, int b) {
	string t1, t2;
	// 利用字符串将数字拼接在一起
	t1 += a, t2 += b;
	// 对比大小 
	// a.compare(b)  a字符串中的字符ASCII码大于b字符串中的字符就会返回1，否则返回-1，相同返回0 
	return t1.compare(t2);
}
int main() {
	int arr[] = {3, 32, 321};
	sort(arr, arr + 3, s);
	for (int i = 0; i < 3; i++) {
		cout << arr[i];
	}
	return 0;
}
