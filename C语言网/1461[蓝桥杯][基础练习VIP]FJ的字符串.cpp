#include <iostream>
#include <cstdio>
using namespace std;

// �ҹ���...�����Կ��ɺ�һ���ַ���ǰһ���ַ�+i+ǰһ���ַ���� 

int main() {
	int n;
	cin >> n;
	string res = "";
	for (int i = 0; i < n; i++) {
		res += (char)('A' + i) + res;
	}
	cout << res;
	return 0;
}
