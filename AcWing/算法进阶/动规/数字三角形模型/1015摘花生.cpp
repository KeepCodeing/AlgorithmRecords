#include <iostream>
using namespace std;

// ״̬���ϣ�f[i][j]��ʾ��(i, j)���λ���ܻ�ȡ���������
// ״̬���ԣ�max����Ϊ��ĿҪ������������
// ״̬���֣�һ��������״̬
// 1. �������߹�������Ӧ��״̬����f[i - 1][j] 
// 2. ������߹�������Ӧ��״̬����f[i][j - 1]
// ���Ľ⼯����max{1., 2.}  

const int N = 110;
int graph[N][N], f[N][N]; 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);  
	int T;
	cin >> T;
	while (T--) {
		int r, c;
		cin >> r >> c;
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				cin >> graph[i][j];
			}
		}
		// ״̬ת�Ʒ���
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				// ��Ϊ������ô�߻�������ժȡ�����Կ��԰����д��max����
				f[i][j] = max(f[i - 1][j], f[i][j - 1]) + graph[i][j];
			}
		}
		cout << f[r][c] << endl;
	}
	return 0;
}
