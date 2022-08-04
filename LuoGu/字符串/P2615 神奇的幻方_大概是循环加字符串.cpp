#include <iostream>
#include <cstdio>
using namespace std;

// ��¼��һ�����λ�ã�Ȼ��ѭ��ģ���������w 

typedef pair<int, int > PII;
const int N = 50;
int graph[N][N];
int main() {
	int n, tn;
	cin >> n;
	// �С��У�ע��nһ��Ϊ������Ҳ����˵����֮��Ҫ+1... 
	PII pre = PII(1, n / 2 + 1);
	graph[pre.first][pre.second] = 1;
	tn = n * n;
	for (int i = 2; i <= tn; i++) {
		int px = pre.first, py = pre.second;
		int nx, ny;
		if (px == 1 && py != n) nx = n, ny = py + 1;
		else if (py == n && px != 1) ny = 1, nx = px - 1;
		else if (px == 1 && py == n) nx = px + 1, ny = py;
		else if (px != 1 && py != n) {
			if (!graph[px - 1][py + 1]) nx = px - 1, ny = py + 1;
			else nx = px + 1, ny = py;
		}
		graph[nx][ny] = i;
		pre = PII(nx, ny);
//		break;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", graph[i][j]);
		}
		puts("");
	}
	return 0;
}
