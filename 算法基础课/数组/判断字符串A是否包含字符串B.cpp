#include <iostream>
using namespace std;
// ����һ���ַ���A���ж�����һ���ַ���B�Ƿ񱻰���������
// ���ֽⷨ
// 1. ������ 2. map������3. ����4. ����API�����ļ��ⷨ�� 
int main() {
	string A = "Hello World";
	string B = "World1";
	for (int i = 0; i < B.size(); i++) {
		// ʹ��find������A�������B���������ַ� 
		if (A.find(B[i]) == -1) {
			cout << "can not !" << endl;
			break;
		}
	}
	
	return 0;
} 
