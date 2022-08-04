#include <iostream>
using namespace std;

// ���ȿ���01�����Ķ�ά״̬�ⷨ��01����һ��������״̬����Ʒ��ֵ����Ʒ����
// ��f[i][j]��ʾֻ����i����Ʒ�������Ϊjʱ���ܼ�ֵ����Ƕ���

// result = max(f[n][0~v]��������Ʒ��ѡ���ܴﵽ������ֵ

// 1. ��ѡ��i����Ʒ�� f[i][j] = f[i - 1][j]������ѡ��i����Ʒ�ܻ�õ�����ܼ�ֵ����ǰһ����Ʒ������ܼ�ֵ
// 2. ѡ��i����Ʒ:f[i][j] = f[i - 1][j - v[i]] + w[i]����ѡ��i����Ʒ�ܻ�õ�����ֵ���Ǳ��������ȥ��Ʒ
// ���������ܻ�õ�����

// ���յĽ������max{1. 2.} 

const int N = 1010;
int val[N], wei[N];
int f[N][N];
int main() {
	int n, v;
	cin >> n >> v;
	for (int i = 1; i <= n; i++) cin >> val[i] >> wei[i];
	for (int i = 1; i <= n; i++) {
		// �ж���Ǯ������Ǯ 
		for (int j = val[i]; j <= v; j++) f[i][j] = max(f[i - 1][j], f[i - 1][j - val[i]] + wei[i]);
	}
	int res = -1;
	// �Ա�����ѡ����ֵ��� 
	for (int i = 0; i <= v; i++) res = max(f[n][i], res);
	cout << res;
	return 0;
}
