#include <iostream>
using namespace std;

// ��Ŀ�ƺ�˵�����Ĵ�Сд����ô�������ַ�������
// ��ʽ��֮��ֱ�ӶԱȾͿ����� 

string be(string str) {
	for (int i = 0; i < str.size(); i++) str[i] = tolower(str[i]);
	return str;
}
int main() {
	string a, b;
	cin >> a >> b;
	a = be(a), b = be(b);
	if (a == b) cout << 0;
	else if (a < b) cout << -1;
	else cout << 1;
	cout << endl;
	return 0;
}
