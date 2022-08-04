#include <iostream>
#include <cstring>
using namespace std;
int main() {
	string tx1, tx2;
	cin >> tx1 >> tx2;
	int t1Len = tx1.size(), t2Len = tx2.size();
	// ע����Ŀû�����ݷ�Χw��ֻ�ܶ�̬���ռ䣬����ע��
	// ��̬���Ŀռ�ֵ��ȷ�������ֶ���ʼ��... 
	int f[t1Len + 1][t2Len + 1];
	memset(f, 0, sizeof f);
	for (int i = 1; i <= t1Len; i++) {
		for (int j = 1; j <= t2Len; j++) {
			if (tx1[i - 1] == tx2[j - 1]) f[i][j] = f[i - 1][j - 1] + 1;
			else f[i][j] = max(f[i - 1][j], f[i][j - 1]);
		}
	}
	cout << f[t1Len][t2Len];
	return 0;
}
