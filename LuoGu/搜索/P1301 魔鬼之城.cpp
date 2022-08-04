#include <iostream>
#include <cstdio>
using namespace std;

// �о��е������ĸо��������������ƶ���ʽ�ɵ�ǰλ�þ��������ҹ涨�������һ���ߵķ���ͬ��
// ��ô����ǰ�ߣ����ǰ˸������ߣ�����ÿ���ߵĲ���Ϊ����*��ǰ���ӵ�ֵ�������߾��Ǽ�¼��ǰ�ߵķ���
// �ı�ž���... 
/*
������ģ���������
�߷����������߷����ǹ̶��ģ����Ǹ��ݵ�ǰ���ֵ����
һ��������������
��ν��
��ʵ���ǿ��Է��֣����ܵ�ǰ���ֵ�Ƕ��٣��߷��ǲ���ģ����ֻ���ߵĲ��������Կ���ֱ�ӽ��߷���д������Ȼ����ϵ�ǰ���ֵ������
����ʹ��һ�� vis ��������ǵ�ǰ���Ƿ��߹������ĸ������߹���Ҳ���Ƕ࿪һά��¼��ǰ�㱻���ʵķ���Ȼ�����ڽṹ�����һ�� pre
������������¼��ǰ���������߷��������ǰ�㱻ĳ���߷��߹������ߵ�ǰ����߷�����һ������ͬ���ͽ��м�֦��ע�⣬����ֻ�ü�¼��
һ�����߷��������֦��ֻ���70�֣���Ϊ��ʵĳ������ԴӶ�������߹��������˵�ǰ�㣬�������ֻ�жϷ����Ƿ���ͬ���ͻ�Ĭ�ϼ�ȥ
���������߷���
*/ 

// ע�⿪��ռ䣬��Ȼ��RE 
const int N = 1110;
int n, m;
int graph[N][N];
bool vis[N][N][10];
int mv[8][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
struct Node {
	int x, y, step, pre;
	Node (int x, int y, int step, int pre) : x(x), y(y), step(step), pre(pre) {};
	Node () {};
} que[N * N];
int bfs() {
	int qtop = 0, qback = 0;
	que[qtop] = Node(1, 1, 0, -1);
	while (qtop <= qback) {
		Node now = que[qtop++];
		if (now.x == n && now.y == m) return now.step;
		int nv = graph[now.x][now.y];
		for (int i = 0; i < 8; i++) {
			// Ӧ���Ǵӵ�ǰ��ƫ�ƣ�������ֱ���� 
			int nx = now.x + mv[i][0] * nv, ny = now.y + mv[i][1] * nv;
			if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
			// �����һ�����Ѿ��Է���i�߹�һ���ˣ����ߵ�ǰ�߷�����һ������߷���ͬ���ͼ��� 
			if (vis[nx][ny][i] || i == now.pre) continue;
			// ���Ĳ���֮һ�����λ�õ�ͬʱ��Ƿ���... 
			vis[nx][ny][i] = true;
			que[++qback] = Node(nx, ny, now.step + 1, i);
		}
	}
	return -1;
} 
int main() {
	// ע�������Ƿ�������� 
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &graph[i][j]);
		}
	}
	int res = bfs();
	if (res == -1) printf("NEVER");
	else printf("%d", res);
	return 0;
}
