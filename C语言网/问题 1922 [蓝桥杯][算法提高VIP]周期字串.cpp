#include <iostream>
using namespace std;

// �ƺ����ǡ��ִ�ʫ����򾡱��һ���˼·����������ȡ��Ȼ���ж� 

bool solve(string cmpStr, int step, int sLen, string str) {
	for (int j = 0; j < sLen; j += step) {
		if (cmpStr != str.substr(j, step)) return false;
	}
	return true;
}

int main() {
	string str;
	cin >> str;
	int sLen = str.size();
	for (int i = 1; i <= sLen; i++) {
		string cmpStr = str.substr(0, i);
		if (sLen % cmpStr.size() != 0) continue;
		if (solve(cmpStr, i, sLen, str)) {
			// û��ע�⵽ѭ��Ϊһ�������ѡ������Ϊ��0�������о����е�����cmpStr�������
			// ��ô���ģ���ʵ��Ϊ����ַ����Ǹ�ѭ���ģ����Խ�ȡ��ĳ��λ��һ�����ҵ��ظ���
			// �Ǹ��ַ��� 
			cout << cmpStr.size();
			break;
		}
	}
	return 0;
}
