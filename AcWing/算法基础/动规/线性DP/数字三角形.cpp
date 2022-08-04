#include <iostream>
using namespace std;
const int N = 510, INF = 0x3FFFFFFF;
int nums[N][N], f[N][N];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> nums[i][j];
		}
	}
	// ��ʼ��״̬
	// ע�������ʼ���ķ�Χ������Ϊ��0��ʼ�Լ�i+1����Ϊ������ȡ��������ȡ���ܻᵼ��ȡ��������ĵ� 
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= i + 1; j++) {
			f[i][j] = -INF;
		}
	} 
	// �ӵڶ��п�ʼ���� 
	// ������ĵ�û���߷� 
	f[1][1] = nums[1][1];
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			f[i][j] = max(f[i - 1][j] + nums[i][j], f[i - 1][j - 1] + nums[i][j]);
		} 
	}
	int res = -INF;
	for (int i = 1; i <= n; i++) res = max(f[n][i], res);
	cout << res;
	return 0;
}
