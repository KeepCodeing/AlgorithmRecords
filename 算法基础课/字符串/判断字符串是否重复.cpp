#include <iostream>
using namespace std;
// ����һ���ַ�����Ҫ��ʹ�ö���Ĵ洢�ռ��ж��Ƿ����ַ��ظ�
// ˼·���������ж���ASCII�뻹��UTF�룬Ȼ����һ���������Ѿ����ֹ����ַ����ں����ж����жϸ��ַ����ֹ�
// û���� 
int main() {
	string str = "WORLD";
	int temp[128] = {0};
	for (int i = 0; i < str.size(); i++) {
		if (temp[(int)str[i]] != 0) {
			cout << "can not!" << endl;
			break;
		}
		// ���ｫ�ַ���ASCII����Ϊ������±� 
		temp[(int)str[i]] = 1;
	}
	return 0;
} 
