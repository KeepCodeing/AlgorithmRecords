#include <iostream>
#include <cstdio>
using namespace std;
typedef unsigned long long ULL;
bool flag = false;
void dfs(int n, ULL ans, int deepth) {
	// �����˲��ǵ���ô�Ӽ�֦��...Ӧ�����ڽ���ݹ�ǰ�ͼ�֦�������ǽ������˲ű��.. 
	if (deepth >= 19 || flag) return;
	if (ans % n == 0) {
		if (!flag) cout << ans << endl, flag = true;
		return;
	}
	dfs(n, ans * 10 + 1, deepth + 1);
	dfs(n, ans * 10, deepth + 1);
}
int main() {
	int n;
	while (scanf("%d", &n), n) {
		flag = false;
		dfs(n, 1, 0);
	}
	return 0;
}
