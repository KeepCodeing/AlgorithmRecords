#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

// ��01�������⣬���ǲ��Ǽ򵥵������з����������Ҽ��˸��ܹ���������Լ��
// ���Ҳ�֪����ôд������Ӧ�ÿ��Ը�����仯���� 

// ���ѵ���60��..�������ȫTLE�ˣ���Ȼ��д���仯���Ƿ��ֵڶ���״̬̫���ˣ����鿪����... 

const int N = 2010, M = 100010;
int cow[N];
int n, m;
int cnt = 0;
int f[N][N];
int dfs(int level, int deepth, int sumNum) {
	if (level == deepth) {
		if (!(sumNum % m) && sumNum != 0) cnt++;
		return 1;
	}
	if (f[level][sumNum] != -1) return f[level][sumNum];
	f[level][sumNum] = dfs(level + 1, deepth, sumNum + cow[level]);
	f[level][sumNum] = dfs(level + 1, deepth, sumNum);
}

int main() {
	cin >> n >> m;
	memset(f, -1, sizeof f);
	for (int i = 1; i <= n; i++) cin >> cow[i];
	sort(cow + 1, cow + n);
	dfs(1, n + 1, 0);
	cout << cnt;
	return 0;
}
