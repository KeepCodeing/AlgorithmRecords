#include <iostream>
using namespace std;

// �߾��㷨�ĺ���˼�룺��Ҫ����ģ����ѧ�е���ʽ���㣬������
// �����ֵ�ÿһλ�������� 

// �߾��� 
string Add(string a, string b) {
	string result;
	// ��ȡ���� 
	int aLen = a.length(), bLen = b.length();
	int maxLen = max(aLen, bLen);
	// ���϶̵��ַ�ǰ��0���������������� 
	for (int i = aLen; i < maxLen; i++) a = "0" + a;
	for (int i = bLen; i < maxLen; i++) b = "0" + b;
	// �ж��Ƿ��λ 
	int flag = 0;
	for (int i = maxLen - 1; i >= 0; i--) {
		char temp = a[i] + b[i] - '0' + flag;
		if (temp > '9') flag = 1, temp -= 10;
		else flag = 0;
		// ��Ϊ�ǵ�������ģ�����Ҫ�Ѽӳ����ĸ�λ��ǰ�� 
		result = temp + result;
	}
	// �ж�����Ƿ�Ҫ���н�λ 
	if (flag) result = "1" + result;
	return result;
}

int main() {
	string a, b;
	cin >> a >> b;
	cout << Add(a, b);
	return 0;
}
