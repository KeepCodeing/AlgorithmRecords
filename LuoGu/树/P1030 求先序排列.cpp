#include <iostream>
using namespace std;

// �����ֺ���������ַ��������һ���ַ��������������������������ֿ��Խ����������Ϊ������
// �ٶ���������ó����������������������+��������Ϳɵó�������� 

void fir(string mid, string before) {
	if (mid.size() > 0) {
		char ch = before[before.size() - 1];
		cout << ch;
		int k = mid.find(ch);
		fir(mid.substr(0, k), before.substr(0, k));
		fir(mid.substr(k + 1), before.substr(k, mid.size() - k - 1)); 
	}
}
int main() {
	string mid, before;
	cin >> mid >> before;
	fir(mid, before);
	return 0;
}
