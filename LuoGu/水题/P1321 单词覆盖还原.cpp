#include <iostream>
using namespace std;

// ��Ϊboy��girl���ַ�������ͬ�����Կ���ֻҪ���������������ַ�
// ������һ�����Ǵʣ�Ϊ�˷���ͳ�ƽ�ԭ�����滻 

int main() {
	string str;
	cin >> str;
	// Cܳ��replace̫Ұ����
	for (int i = 0; i < str.size(); i++) {
		int b, g;
		if (b = str.find("boy") != str.npos) {
			str.replace(b, b + 3, "1"); 
		}
		if (g = str.find("girl") != str.npos) {
			str.replace(g, g + 4, "0"); 
		}
		if (b == str.npos && g == str.npos) break;
	} 
	cout << str; 
	return 0;
}
