#include <iostream>
using namespace std;

// ˮ���ʮ����..���Ͼ�Ҫ����ˣ�dokidoki 

void mswap(char& a, char& b) {
	char temp = a;
	a = b, b = temp;
}

string reverseStr(string str) {
	int left = 0, right = str.size() - 1;
	while (left < right) mswap(str[left++], str[right--]);
	return str;
}
int main() {
	string s1, s2;
	cin >> s1 >> s2;
	
	cout << (s1 == reverseStr(s2) ? "YES" : "NO");
	return 0;
}
