#include <iostream>
#include <vector>
using namespace std;
// ����һ���ַ�����"here you are"��Ҫ���䷭תΪ"are you here"
// ˼·���Ƚ������зֿ���������ƴ����һ��
string splitStr(string str, char reg) {
	string temp, result;
	// ��ֹ©�����һ���ַ� 
	str += reg;
	vector<string > r; 
	// ����ġ�Խ�硱����ֹ©�����һ���ַ� 
	for (int i = 0; i <= str.size(); i ++) {
		if (str[i] != reg) {
			temp += str[i];
		} else {
			r.push_back(temp);
			temp.clear();
		}
	}
	for (int i = r.size() - 1; i >= 0; i--) {
		result += r[i];
		if (i != 0) result += reg;
	}
	return result;
} 
 
int main() {
	cout << splitStr("here you are", ' ');
	return 0;
}
