#include <iostream>
#include <algorithm>
using namespace std;

// ������ 
// Ȼ�����˰��춼û��������ôȥ���һ��+... 

int main() {
	char m;
	int sLen, oneCnt, cnt = 0;
	string str;
	char temp;
	cin >> m >> str;
	sLen = str.size();
	oneCnt = sLen - count(str.begin(),  str.end(), '0');
	for (int i = sLen - 1; i >= 0; i--) {
		temp = str[sLen - i - 1];
		if (temp != '0') {
			cnt++;
			cout << temp << '*' << m << '^' << i;
			// �ж��ǲ������һ����0�ַ� 
			if (cnt != oneCnt) cout << '+';
		}
	}
	return 0;
}
