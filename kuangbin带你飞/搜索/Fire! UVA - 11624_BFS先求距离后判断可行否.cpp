#include <iostream>
#include <cstring>
using namespace std;

// �������ƺ��������������������֪��Ϊʲô����ϵĴ���...��ô���������ȴӻ��ܱ�BFS��Ȼ���������ӵ�������ͼ��ʱ��
// �ٴ����ܱ�BFS���ж������ܲ����ڻ����ӵ���ͼ��ĳ��֮ǰ�߹������...��ô������ô�ж�����û�߳���ͼ��Ӧ�ÿ��Լ�¼�����
// һ��������꣬����ڵ�ͼ���˵�����Գ�ȥ����ô�����Ļ�Ӧ�ÿ���д���жϣ��жϵ�ǰ���Ƿ���磬�����˵�����У��������
// ��ͼ��û�е�����˵��������...

#define x first
#define y second
typedef pair<int, int > PII;
const int N = 1000 + 100;
int T, n, m, sx, sy;
char graph[N][N];
int mv[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int qtop1 = 0, qback1 = 0;
int dist[N][N];
PII que1[N * N];
// ������ȡ�����ӵ�������ͼ��ʱ���BFS���������ƺ�ֻ��һ���𣬵�����Ŀ
// û��˵ֻ��һ�������Կ����кܶ��..
void bfs1() {
	while (qtop1 <= qback1) {
		PII now = que1[qtop1++];
		for (int i = 0; i < 4; i++) {
			int nx = now.x + mv[i][0], ny = now.y + mv[i][1];
			if (nx >= n || nx < 0 || ny >= m || ny < 0) continue;
			if (dist[nx][ny] != -1 || graph[nx][ny] != '.') continue;
			dist[nx][ny] = dist[now.x][now.y] + 1;
			que1[++qback1] = PII(nx, ny);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << dist[i][j] << ' ';
		}
		cout << endl;
	}
}
// ����ģ���˵��ж�
struct Node {
	int x, y, step;
	Node (int x, int y, int step) : x(x), y(y), step(step) {};
	Node () {};
} que[N * N];
bool visited[N][N];
int bfs2() {
	int qtop = 0, qback = 0;
	que[qtop] = Node(sx, sy, 0);
	while (qtop <= qback) {
		Node now = que[qtop++];
		// �����ж��Ƿ��ܹ��߳�ȥ
		if (now.x <= 0 || now.x >= n - 1 || now.y <= 0 || now.y >= m - 1) return now.step;
		for (int i = 0; i < 4; i++) {
			int nx = now.x + mv[i][0], ny = now.y + mv[i][1];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue; // ��Ȼ��������߳�ȥ�����������±껹�ǵúϷ���
			if (visited[nx][ny] || graph[nx][ny] == '#') continue;
			if (now.step + 1 >= dist[nx][ny] && nx >= 0 && nx < n && ny >= 0 && ny < m) continue;
			visited[nx][ny] = true;
			que[++qback] = Node(nx, ny, now.step + 1);
		}
	}
	return -1;
}
int main() {
	cin >> T;
	while (T--) {
		cin >> n >> m;
		// ��ʼ��
		memset(dist, -1, sizeof dist);
		memset(visited, 0, sizeof visited);
		for (int i = 0; i < N; i++) {
			for (int j = 0 ; j < N; j++) graph[i][j] = 'e';
		}
		qtop1 = 0, qback1 = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> graph[i][j];
				// ������л�
				if (graph[i][j] == 'F') que1[qback1++] = PII(i, j), dist[i][j] = 0;
				else if (graph[i][j] == 'J') sx = i, sy = j;
			}
		}
		bfs1();
		int res = bfs2();
		if (res == -1) cout << "IMPOSSIBLE";
		else cout << res;
		cout << endl;
	}
	return 0;
}
/*
1
4 5
####
#J#F
....
....
....
*/
