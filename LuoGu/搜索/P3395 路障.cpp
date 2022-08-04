#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

// �����ͬ������ѧ�����ᣬͬ������ѧ��������..��Ҳ����˵���������ȵ÷����� 

// �ֱ�����ww����α������Լ���������ˣ�����û�п������ᣬ����������������ᣬ�ɴ˵��µľ��Ƕ��Ŵ�������
// ���˰���û�н����

// ���۾��ǲ���������ô����ֻҪ�����յ�������Ҷ��˾���...Ҳ����˵������Բ��ܣ�����Ŀ�������������յ�
// ��Ӧ��û�д�����������... 

const int N = 1010;
struct PII {
	int x, y, step;
	PII(int x, int y, int step) : x(x), y(y), step(step) {};
	PII() {};
};
int graph[N][N];
PII que[N * N];
int move[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int n;
// xʵ����y�ᣬyʵ����x�ᣬΪ�˷�������Ƿ��ŵģ��������û�仯��������ŵ�ww�� 
string bfs(int sx, int sy) {
	int qtop = 0, qback = 0;
	que[qtop] = PII(sx, sy, 0);
	// graph[sx][sy] = -1;
	//cout << endl;
	while (qtop <= qback) {
		PII now = que[qtop++];
		//cout << now.x << ' ' << now.y << ' ' << now.step << endl;
		if (now.x == n && now.y == n) return "Yes";
		for (int i = 0; i < 4; i++) {
			int nx = now.x + move[i][0], ny = now.y + move[i][1];
			if (nx > n || nx < 1 || ny > n || ny < 1) continue;
			// cout << nx << ' ' << ny  << ' ' << now.step << ' ' << graph[nx][ny] << endl;
			if (graph[nx][ny] == -1 || now.step > graph[nx][ny] && graph[nx][ny] != 0) continue;
			graph[nx][ny] = -1;
			// cout << nx << ' ' << ny << ' ' << now.step << endl;
			que[++qback] = PII(nx, ny, now.step + 1);
		}
	}
	return "No";
} 

int main() {
	int T;
	scanf("%d", &T);
	int x, y;
	while (T--) {
		memset(graph, 0, sizeof graph);
		scanf("%d", &n);
		for (int i = 1; i <= 2 * (n - 1); i++) {
			scanf("%d%d", &x, &y);
			graph[x][y] = i;
		}
		
//		puts("");
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= n; j++) {
//				printf("%d ", graph[i][j]);
//			}
//			puts("");
//		}
		cout << bfs(1, 1) << endl;
	}
	return 0;
}
