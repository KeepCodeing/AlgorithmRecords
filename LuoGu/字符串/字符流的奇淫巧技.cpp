#include <iostream>
#include <sstream>
using namespace std;
int main() {
	stringstream ss;
	string result;
	// �ַ���ʵ��תʵ�� 
	ss << "114.514";
	ss >> result;
	cout << result << endl;
	return 0;
}
