#include <iostream>
#include <sstream>
using namespace std;

// ���ַ������򻯲��� 

int main() {
	stringstream s;
	string str;
	while(cin >> str) {
		string temp;
		int num;
		bool flag = true;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] != '.') {
				if (str[i] < '0' || str[i] > '9') {
					flag = false;
					break;
				}
				temp += str[i];
			} else {
				// ��ջ���������Ȼ����BUG 
				s.clear(); 
				s << temp;
				s >> num;
				if (num < 0 || num > 255) {
					flag = false;
					break;
				}
				// ͬ�������temp�ַ��� 
				temp = "";
			}
		}
		if (flag) cout << "Y";
		else cout << "N";
		cout << endl;
	}
	return 0;
} 
