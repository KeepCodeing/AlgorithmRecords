#include <iostream>
#include <map>
using namespace std;
map<string, int > m;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); 
	string str;
	cin >> str;
	// ע��substr���÷�����ͷλ�ò��䣬����ǽ�ȡ���� 
	int sLen = str.size(); 
	for (int i = 0; i <= sLen; i++) {
		for (int j = 1; j <= sLen - i; j++) {
			m[str.substr(i, j)]++;
		}
	}
	int maxLen = -1;
	for (map<string, int>::iterator it = m.begin(); it != m.end(); it++) {
		if (it->second > 1) {
			// ����Ĵ���������ѭ���ṹ�ﲻ��ֱ��������maxLen < it->first.size()�ķ�ʽ�Աȴ�С����֪���ǲ���
			// ���ȼ����⣬��֮���ѷ���... 
			int sl = it->first.size();
			if (sl > maxLen) {
				maxLen = sl;
			}
		}
	}
	cout << maxLen;
	return 0;
} 
