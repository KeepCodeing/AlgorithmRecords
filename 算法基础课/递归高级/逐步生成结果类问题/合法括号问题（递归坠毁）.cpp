#include <iostream>
#include <map>
using namespace std;
// ����һ���ַ�������(())��{()}�ȣ�Ҫ���ж����Ƿ��ǺϷ����ţ�()��[]��{}�ȶ��ǺϷ�����

// ����������������ַ�������һ�����壬����ͱȽϸ����ˣ������һ�����ַ������ж�')'ǰ��
// �ǲ���'('��']'��'}'��ͬ��������ջ��д������֮ǰд���ˣ������õݹ�д 

string str;
bool flag = true;
char visited[100] = {' '};
map<char, char > m;
// level������ǵ�ǰ���ַ����е��Ǹ��ַ� 
char solve(char c, int level) {
	// ���Գ��˳� 
	if (str.size() % 2 != 0) {
		flag = false;
		return ' ';
	}
	if (level >= str.size()) return ' ';
	// ���������ŷ��أ���ǰ������ŶԱ�
	if (c == ')' || c == ']' || c == '}') {
		// cout << c << endl;
		return c;
	}
	for (int i = 1; i <= str.size() / 2; i++) {
		if (visited[i] == ' ') continue;
		visited[i] = c;
		cout << solve(str[level + i], level + 1) << endl;
		visited[i] = c;
	}
	
	// cout << c << endl;
}
int main() {
	m['('] = ')', m['{'] = '}', m['['] = ']';
	cin >> str;
	// ([{}])
	solve(str[0], 0);
	return 0;
}
