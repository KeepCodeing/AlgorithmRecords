#include <iostream>
using namespace std;

// ���Զ��ַ�������һ������Ȼ��ͳ��V����K������
// ���������ȣ����ģ������ 
char *str;
int main() {
	int n;
	cin >> n;
	int vCnt = 0, kCnt = 0, minCnt = 0;
	str = new char[n];
	for (int i = 0; i < n; i++) {
		cin >> str[i];
		if (str[i] == 'K') kCnt++;
		else vCnt++;
	}
	if (kCnt && vCnt) minCnt = min(kCnt, vCnt);
	for (int i = 0; i < n; i++) {
		str[i] = str[i] == 'V' ? 'K' : 'V'; 
		for (int j = 0; j < n; j++) {
			
		}
		str[i] = str[i] == 'V' ? 'K' : 'V'; 
	}
	cout << minCnt;
	delete[] str;
	return 0;
}
