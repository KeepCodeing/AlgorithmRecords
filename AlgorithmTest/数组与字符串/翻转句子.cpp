#include <iostream>
#include <algorithm>
using namespace std;
// ����һ���ַ����磺Hello World 114514,YJSP810��Ҫ��ֻ��ת���ʣ�����ת����

// ˼·���ո񣬱��ʹ����ֲ���ת������ֻ���жϵ�ǰ�ַ����Ƿ���Ҫ��ת����
bool checkReverse(string str) {
	bool flag = true;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			flag = false;
		} else {
			flag = true;
			break;
		}
	} 
	return flag;
}

string reverseWords(string str) {
	// �Ƚ��ַ����ָ�Ϊ�Կո񣬱������Ķ���Ӵ�
	string tempStr, result;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] != ' ' && str[i] != ',' && str[i] != '.') {
			tempStr += str[i];
		} else {
			if (checkReverse(tempStr)) reverse(tempStr.begin(), tempStr.end());
			result += tempStr + str[i];
			tempStr.clear();
		}
	} 
	// ����������û�б�������ַ������ͼ�д���� 
	if (str[str.length() - 1] != '.') {
		if (checkReverse(tempStr)) reverse(tempStr.begin(), tempStr.end());
		result += tempStr;
	}
	return result;
}

 
int main() {
	cout << reverseWords("Hello World 114514,YJSP810.1919.") << endl;
	return 0;
}
