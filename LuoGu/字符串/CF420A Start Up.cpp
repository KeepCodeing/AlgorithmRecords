#include <iostream>
#include <algorithm>
using namespace std;

// �������ڣ�û�뵽������������start up�ˣ�ָ���⣩... 

// N���Ǿ����ַ������������ѣ� 
// A H I M N O T U V W X Y
bool checker(char s) {
	//return s!='A'&&s[i]!='H'&&s[i]!='V'&&s[i]!='I'&&s[i]!='M'&&s[i]!='W'&&s[i]!='O'&&s[i]!='T'&&s[i]!='U'&&s[i]!='X'&&s[i]!='Y';
}
int main() {
	string str;
	cin >> str;
	// �����ж����ǲ��ǻ��ģ�Ȼ���ж��¸��ַ����Ƿ�ֻ���ھ����ַ���
	string temp = str;
	int l = 0, r = str.size() - 1;
	while (l < r) swap(temp[l++], temp[r--]);
	cout << temp;
	if (temp != str) cout << "NO" << endl;
	else {
		for (int i = 0; i < str.size(); i++) {
			if (!checker(str[i])) {
				cout << "NO" << endl;
				return 0;
			}
		}
		cout << "YES" << endl;
	}
	return 0;
} 
