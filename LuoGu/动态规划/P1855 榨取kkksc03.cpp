#include <iostream>
using namespace std;

// ��ά���ñ�����01������ 

// �������⣺
// 1. time�����ƺ���C++���ĳ���ؼ��ֳ�ͻ������CE����������Ǿ�������������
// 2. ��Ȼ���˶�ά���ñ���ģ�ͣ����Ƿ���û��������һ�Ȼ������⣨���ܣ�
// ���������Ҳ���ǵ�һ���ˣ����е�����ǰ�max��Ϊ��min���������ǰ���������
// Ϊ1��Ҳ����˵������ģ�����˵�����ʱ������ģ����û�еĶ�����Ҫ�Լ���������
// ������� 

const int N = 210;
int money[N], tm[N]; 
int f[N][N];
int main() {
	int n, m, t;
	cin >> n >> m >> t;
	for (int i = 1; i <= n; i++) cin >> money[i] >> tm[i];
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= money[i]; j--) {
			for (int k = t; k >= tm[i]; k--) {
				f[j][k] = max(f[j - money[i]][k - tm[i]] + 1, f[j][k]);
			}
		}
	}
	cout << f[m][t];
	return 0;
} 
