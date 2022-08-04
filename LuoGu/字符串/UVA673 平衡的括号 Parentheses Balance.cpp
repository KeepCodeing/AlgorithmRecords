#include <iostream>
char stk[130];
using namespace std;
bool check(char c) {
	return c == '(' || c == '[' || c == '{';
}
bool cmpChar(char a, char b) {
	if (a == '(') {
		if (b == ')') return true;
		return false;
	}
	if (a == '[') {
		if (b == ']') return true;
		return false;
	}
	if (a== '{') {
		if (b == '}') return true;
		return false;
	}
}
int main() {
	int n;
	cin >> n;
	while (n--) {
		string str;
		cin >> str;
		int tt = -1;
		bool flag = true;
		for (int i = 0; i < str.size(); i++) {
			// ��������ջ�����ַ����ų�ջ�Ա� 
			if (check(str[i])) {
				stk[++tt] = str[i];
			} else {
				// ���ջΪ�գ������ֳ����˷����ţ���һ���޽� 
				if (tt == -1) {
					cout << "No" << endl;
					flag = false;
					break;
				}
				// cout << stk[tt--] << ' ' << str[i] << endl;
				// ������Ų�ƥ��Ҳ�޽� 
				if (!cmpChar(stk[tt--], str[i])) {
					cout << "No" << endl;
					flag = false;
					break;
				}
			}
		}
		if (flag) cout << "Yes" << endl;
	}
	return 0;
}
