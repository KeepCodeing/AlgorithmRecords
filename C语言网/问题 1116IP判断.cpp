#include <iostream>
#include <sstream>
using namespace std;

// 用字符串流简化操作 

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
				// 清空缓冲区，不然会有BUG 
				s.clear(); 
				s << temp;
				s >> num;
				if (num < 0 || num > 255) {
					flag = false;
					break;
				}
				// 同样，情况temp字符串 
				temp = "";
			}
		}
		if (flag) cout << "Y";
		else cout << "N";
		cout << endl;
	}
	return 0;
} 
