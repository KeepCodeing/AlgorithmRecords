#include <iostream>
using namespace std;
int main() {
	int maxLen = -1;
	string temp, str;
	while(cin >> temp) {
		// �������ֱ����temp.size()�ԱȾ�Ȼ���� 
		int t = temp.size();
		if (t > maxLen) {
			maxLen = t;
			str = temp;
		}
	}
	cout << str;
	return 0;
}
