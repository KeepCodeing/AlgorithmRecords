#include <iostream>
using namespace std;

// 01�����������С�����ͳ���С�����������ƣ������仹�ǲ�̫��Ϊʲô�����ܣ� 

// ״̬��ʾf[i]����ʾ��ǰ����Ϊiʱ���ܻ�õ�����ֵ����˵�����ֵ
// �����˱����ݻ�ʱ��ʣ�������Ϳ�ͨ��������-��ǰ������á� 

const int N = 10010;
int val[N], wei[N];
int f[N];
int main() {
	int v, n, c;
	cin >> v >> n >> c;
	for (int i = 1; i <= n; i++) cin >> wei[i] >> val[i];
	for (int i = 1; i <= n; i++) {
		for (int j = c; j >= val[i]; j--) {
			f[j] = max(f[j], f[j - val[i]] + wei[i]);
		}
	}
	bool flag = false;
	for (int i = 1; i <= c; i++) {
		if (f[i] >= v) {
			flag = true;
			// ��һ���������ڱ����ݻ��Ľ������С�����Ľ�
			// ���ʣ������� 
			cout << c - i;
			break;
		}
	}
	if (!flag) cout << "Impossible";
	return 0;
}
