#include <iostream>
#include <map> 
#include <algorithm>
using namespace std;
// ����һ���ַ�������"aaaaabbbbbbbbcccc"Ҫ�󷵻�"a4b7c3"��
// �������ѹ������ԭ�ַ�������ͳ��ĳ���ַ��ظ����ֵĴ�������������ַ��ĳɳ��ִ��� 
// ˼·���ȶ�ĳ���ַ����м�����������replace�����滻�ַ� 
// �Լ�д������ת�ַ���������Ч��̫�� 
string int2str(int num) {
	string result;
	while (num) {
		result += (num % 10 + '0');
		num /= 10;
	}
	reverse(result.begin(), result.end());
	return result;
}
int main() {
	map<char, int > c_map;
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		c_map[str[i]]++;
	}
	for (map<char, int >::iterator it = c_map.begin(); it != c_map.end(); it++) {
		// �ų�ֻ���ֹ�һ�ε��ַ� 
		if (it->second == 1) continue;
		int index = str.find(it->first);
		// �ӵ�һ���ַ���֮�����һ���ַ������滻�ɸ��ַ��ĳ��ִ��� 
		str.replace(index + 1, it->second - 1, int2str(it -> second - 1));
	}
	cout << str << endl;
	return 0;
}
