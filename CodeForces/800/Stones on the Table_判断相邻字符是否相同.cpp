#include <iostream>
using namespace std;

// �븴���ˣ�������Ϊ������Ǹ�̰��ʲô�ģ����������ԭ�������ж���һ���ַ��͵�ǰ�ַ��Ƿ���ͬ... 
// ����Ҳû��Ҫ��Ļ���ɫʲô�ģ�ͳ��������������... 

int main() {
	string str;
	cin >> str;
	int sLen = str.size(), cnt = 0;
	for (int i = 0; i < sLen - 1; i++) {
		if (str[i] == str[i + 1]) cnt++;
	}
	cout << cnt << endl;
	return 0;
}
