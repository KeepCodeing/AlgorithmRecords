#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	string str;
	cin >> str;
	// ����������д����Ȼ����50%������... 
//	swap(str[str.size() - 2], str[str.size() - 1]);
//	cout << str;
// ����������STL���next_permutation()����������һ������
// �������һ���ǰ��ֵ������ģ�Ҳ���ǵ�һ�����ڵ�ǰ�ַ�����
// �ַ��������⻹��pre_purmutation()������������һ���ֵ�����ַ���
	next_permutation(str.begin(), str.end());
	cout << str; 
	return 0;
}
