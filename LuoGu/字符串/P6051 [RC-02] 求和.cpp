#include <iostream>
#include <sstream>
using namespace std;

// �ַ���ģ���⣬û�뵽��Ȼ���ռ��Ѷ�
// �࿼�ǵ�һ����ĳ���ַ�ǰ��ļ�����Ƿ��������ַ��Ǹ�����
// �жϷ��������������**-1234������������Ǹ�����������123-1234
// ��������Ͳ��Ǹ�����
// ����ж��Ƿ��Ǹ���
// ��str[i - 1] == '-' && str[i - 2] != ���֣���������Ͳ��Ǹ���������
// ��������Ǹ��� 

bool isNum(char c) {
	return c >= '0' && c <= '9';
}
int main() {
	string str;
	while (getline(cin, str)) {
		str += "*";
		int sLen = str.size();
		bool flag = true, isAns = false;;
		int res = 0;
		string temp;
		for (int i = 0; i < sLen; i++) {
			if (isNum(str[i])) {
				if (flag) {
					flag = false;
					if (i != 0 && str[i - 1] == '-') {
						string c = "-";
						if (i >= 2 && isNum(str[i - 2])) c = "";
						temp += c;
					}
				}
				temp += str[i];
			} else {
				flag = true;
				if (temp != "") {
					stringstream ss;
					ss << temp;
					int t;
					ss >> t;
					res += t;
					temp = "";
					isAns = true;
				}
			}
		}
		if (isAns) cout << res << endl;
	}
	return 0;
}
