#include <iostream>
using namespace std;
// ��дһ��swap��������ȻҲ������algorithm��� 
void sp(char &a, char &b) {
	char temp = a;
	a = b;
	b = temp;
}
// ˫ָ����ת�ַ��� 
bool solve(string str) {
	string temp = str;
	// ��������ָ���λ�� 
	int l = 0, r = str.size() - 1;
	// ָ���ײ 
	while (l < r) sp(temp[l++], temp[r--]);
	// ����ǻ����ַ�������˵��������һ���� 
	return str == temp;
}
int main() {
	string str;
	cin >> str;
	string temp;
	int sLen = str.size();
	// ��ÿ��λ��ö�ٿ��Բ�����ַ� 
	for (char i = 'a'; i <= 'z'; i++) {
		for (int j = 0; j <= sLen; j++) {
			temp = str;
			// insert����������j���λ�ò��볤��Ϊ1���ַ�i 
			temp.insert(j, 1, i); 
			// �����˴�ֱ���˳� 
			if (solve(temp)) {
				cout << temp << endl;
				return 0;
			}
		}
	}
	cout << "NA" << endl;
	return 0;
}
