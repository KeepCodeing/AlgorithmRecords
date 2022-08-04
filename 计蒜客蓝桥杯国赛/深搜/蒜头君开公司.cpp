#include <iostream>
#define endl '\n'
using namespace std;
const int N = 110;
int graph[N][N];
bool vis[N];
int ans = 0x3fffff;
void dfs(int level, int deepth, int cost, int cnt) {
	if (level == deepth) {
		// ע�����cnt�����ã��������ж��Ƿ����ÿһ�ж�ѡ��һ��Ԫ�أ�ΪʲôҪ��cnt����Ϊ���ֻ��ݵ�״̬�ǡ�����һ������
		// ��һ�С��ģ����������м�ľ�����vis[j]������Ҳ������Ԫ���Ƿ��ظ�... 
		if (cnt == deepth) ans = min(ans, cost);
		return;
	}
	for (int i = level; i < deepth; i++) {
		for (int j = 0; j < deepth; j++) {
			if (vis[j]) continue;
			vis[j] = true;
			dfs(i + 1, deepth, cost + graph[i][j], cnt + 1);	
			vis[j] = false;
		}
	}
}
int main () {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); 
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}
	dfs(0, n, 0, 0);
	cout << ans << endl;
	return 0;
}
