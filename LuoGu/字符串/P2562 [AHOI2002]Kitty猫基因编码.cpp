#include <iostream>
#include <algorithm>
using namespace std;

// �ݹ���������ַ�����⼴�� 
// м�㷨ÿ�ζ���ȡһ�����ַ�������Ч�ʺܵͣ�����ֻ��¼λ�� 

void t(string str) {
	if (count(str.begin(), str.end(), '0') == str.size()) {
		cout << "A";
		return;
	}
	if (count(str.begin(), str.end(), '1') == str.size()) {
		cout << "B";
		return;
	}
	int sLen = str.size() / 2;
	cout << "C";
	t(str.substr(0, sLen));
	t(str.substr(sLen));
}
int main() {
	string str;
	cin >> str;
	t(str);
	return 0;
}
