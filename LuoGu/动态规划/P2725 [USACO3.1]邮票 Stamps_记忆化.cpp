#include <iostream>
#include <cstring>
#define endl '\n'
using namespace std;

const int N = 50 + 10, M = 200 + 10;
int nums[N], f[N][M];
int k, n;

int dfs(int i, int k) {
	if (f[i][k] != -1) return f[i][k];
	
	if (i > n) return 0;
	
	if (!k) return 0;
	
	// ��Ŀ����˼�����һ������x��ʹ��1~x�����ֶ��ܱ���Ʊ��ϱ�ʾ����
	// �����������Ʊ�������ܱ�ʾ���Ǹ���... 
	return f[i][k] = max(dfs(i, k - 1) + nums[i], dfs(i + 1, k));
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	memset(f, -1, sizeof f);
	
	cin >> k >> n;
	for (int i = 1; i <= n; i++) cin >> nums[i];
	cout << dfs(1, k) << endl;
	return 0;
}
