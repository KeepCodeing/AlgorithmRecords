#include <iostream>
using namespace std;

// ����Ǹ���ͨ01�����⣬������̫����û�����������û���д�� 
// ���������ݱȽ�ˮ����ΪN<=100�����ˣ����������ö���д��
 
int *cai;
int cnt = 0;
void dfs(int level, int deepth, int target) {
	if (target <= 0 || level == deepth + 1) {
		if (target == 0) cnt++;
		return;
	}
	for (int i = level; i <= deepth; i++) {
		// ��֦����֪���᲻��TLE 
		if (cai[i] > target) continue;
		dfs(i + 1, deepth, target - cai[i]);
	}
}
int f[10010];
int main() {
	int n, m;
	cin >> n >> m;
	cai = new int[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> cai[i];
	}
	// dfs(1, n, m);
	// ��������ͨ01����Ψһ�������������������ֵ��������
	// ������
	f[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= cai[i]; j--) {
			// ���ڵĻ�������+=�Ҳ�������˵�ʱ��Ļ�����������ҵ㣨������ͬ�� 
			f[j] += f[j - cai[i]];
		}
	} 
	cout << f[m];
	delete[] cai;
	return 0;
}
