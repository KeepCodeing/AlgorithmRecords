#include <iostream>
#include <algorithm>
using namespace std;
// ����һ���ַ�����Ҫ���䷭ת���� 
// ˼·�����ַ��������ö���ռ�洢��ʹ��STL���� 
int main() {
	string a = "Hello";
	string b = "World";
	string temp;
	for (int i = a.size() - 1; i >= 0; i--) {
		temp += a[i];
	}
	cout << temp << endl;
	reverse(b.begin(), b.end());
	cout << b << endl;
	return 0;
}
