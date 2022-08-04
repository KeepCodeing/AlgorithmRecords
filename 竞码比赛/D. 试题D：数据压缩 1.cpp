#include <iostream>
using namespace std;
int main() {
	string str;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> str;
	int cnt;
	int j = 0;
	for (int i = 0; i < str.size(); i++) {
		cnt = 0;
		while (str[i] == str[j]) j++, cnt++;
		// 没有多试几种情况，之前写的i=j，如果i和j是相同的，就会产生
		// 一个死循环，也就是没有考虑到如果只有一个字符的情况，如果只有
		// 一个字符，i不会发生改变，跳过这个字符继续遍历，而j默认
		// 指到下一个字符上 
		i = j - 1;
		cout << str[i] << cnt;
	} 
	return 0;
}
