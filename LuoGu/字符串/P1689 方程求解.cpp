#include <iostream>
using namespace std;

// ���ܻ���ֶ���ո����Ի�Ҫ�����¿ո������е�󣬿���Ҫ��long 
// ׹��...
 
long strToNum(string str) {
	long num = 0;
	int fh = 1;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '-') {
			fh *= -1;
			continue;
		} else if (str[i] == '+') {
			continue;
		}
		num = num * 10 + (int)(str[i] - '0');
	} 
	num *= fh;
	return num;
}
int main() {
	string temp, str;
	getline(cin, temp);
	for (int i = 0; i < temp.size(); i++) {
		if (temp[i] != ' ') str += temp[i];
	}
	// ȡ��=�ұߵ��ַ������ж������ǣ��������� 
	int index = str.find('=');
	long ans = 0;
	string right = str.substr(index + 1);
	string left = str.substr(0, index);
	int t = left.find('-') == left.npos ? left.find('+') : left.find('-');
	// ����Ⱥ��ұ���δ֪����ֱ�Ӽ��������� 
	if (right == "?") {
		// ���ݸ����ķ�ΧΪ>=0�����Ե�һ����������Ϊ��
		ans = strToNum(left.substr(0, t)) + strToNum(left.substr(t) );
	} else {
		// ���=�ұ߲���?������ת��������
		long r = strToNum(right);
		string l_l, l_r;
		l_l = left.substr(0, t);
		l_r = left.substr(t);
		if (l_l != "?") {
			// ģ�⽻���� 
			if (l_r == "-?") {
				ans = (-(strToNum(l_l) - r)) * -1;
			} else {
				ans = (-(strToNum(l_l) - r));
			}
		} else {
			ans = r - strToNum(l_r);
		}
	}
	cout << ans;
	return 0;
}
