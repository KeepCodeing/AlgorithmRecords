#include <iostream>
using namespace std;
const int N = 110;
int v[N], w[N];
int f[N];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int s;
		cin >> s;
		for (int j = 1; j <= s; j++) cin >> v[j] >> w[j];
		// ��01������ͬ�ĵط����Ǳ���˳���Ƿ��ŵģ��ȱ���
		// �����ݻ����ٱ�����Ʒ���� 
		// ��Ȼѭ���������ˣ�����״̬���ǲ���ģ�����û��ҪӲ�� 
		for (int j = m; j >= 0; j--) {
			for (int k = s; k >= 1; k--) {
				// �ж��ǵ�ǰ��ֵ����Ǽ�ȥ��Ʒ�ݻ������ϵ�ǰ��Ʒ��ֵ��� 
				if (j >= v[k])
				f[j] = max(f[j], f[j - v[k]] + w[k]);
			}
		}
	} 
	cout << f[m];
	return 0;
}
