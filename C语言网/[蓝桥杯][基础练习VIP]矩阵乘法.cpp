#include <iostream>
using namespace std;

// ѧ���ߴ����б�Ҫ����������ˣ�ʹ���У�..
// ����ĳ˷����ǵ�һ�г�����һ�������1..n���У�ÿ����˵ĺ;��ǵ�һ�У���1..n��λ�õ�Ԫ��
// ��ֵ.. 

const int N = 30 + 10, M = 10;
int matrix[N][N], res[N][N], temp[N][N];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	m -= 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) scanf("%d", &matrix[i][j]), res[i][j] = matrix[i][j];
	}
	while (m--) {
		int tot = 0;
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				tot = 0;
				for (int j = 1; j <= n; j++) {
					// ��ʾ��1�е�j��Ԫ�س��ϵ�j�е�i��Ԫ��..Ȼ���1����k��
					// �Ϳɵõ�������... 
					tot += matrix[k][j] * res[j][i];
				}
				temp[k][i] = tot;
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) res[i][j] = temp[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) printf("%d ", res[i][j]);
		puts("");
	}
	return 0;
}
