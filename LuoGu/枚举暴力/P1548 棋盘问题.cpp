#include <iostream>
using namespace std;

// ���Ա���������Ҳ�����ù�ʽ��������������ö�����ϵ�����µ�
// ��ͬ��Ϊ�����Σ�����Ϊ������ 

int main() {
	int n, m;
	int zCnt = 0, cCnt = 0;
	cin >> m >> n;
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			for (int k = i + 1; k <= m; k++) {
				for (int r = j + 1; r <= n; r++) {
					if (k - i == r - j) zCnt++;
					else cCnt++;
				}
			}
		}
	}
	cout << zCnt << ' ' << cCnt;
	return 0;
}
