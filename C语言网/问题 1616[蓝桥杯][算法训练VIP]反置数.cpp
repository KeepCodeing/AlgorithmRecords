#include <iostream>
using namespace std;

int reverseNum(int x) {
	// �������㷭ת�ģ����Ǵ�������0�Ƚ��鷳���������ַ���������
	// ���̣���ȫ���ô�����Ϊ���������0����res�����ã���res�����õ�
	// �ǵ�һ����0�����֣������������0���ָ�����ǰ��ʲô������ν�� 
	int res = 0;
	while (x) {
		res = res * 10 + x % 10;
		x /= 10;
	} 
	return res;
}

int main() {
	int a, b;
	cin >> a >> b;
	cout << reverseNum(reverseNum(a) + reverseNum(b));
	return 0;
}
