#include <iostream>
using namespace std;
int main() {
	string str;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> str;
	int cnt;
	int j = 0;
	for (int i = 0; i < str.size(); i++) {
		cnt = 0;
		while (str[i] == str[j]) j++, cnt++;
		// û�ж��Լ��������֮ǰд��i=j�����i��j����ͬ�ģ��ͻ����
		// һ����ѭ����Ҳ����û�п��ǵ����ֻ��һ���ַ�����������ֻ��
		// һ���ַ���i���ᷢ���ı䣬��������ַ�������������jĬ��
		// ָ����һ���ַ��� 
		i = j - 1;
		cout << str[i] << cnt;
	} 
	return 0;
}
