#include <iostream>
using namespace std;

// ˼·�Ǽ�¼��һ���ߵķ��������ͬ��˵��Ҫ������ 
// ������DFS�����������һ��������¼��һ�εķ��� Ȼ��
// ������·������һ�飬����һ���ܵó��⣬���ǲ���Խ�࣬����
// �ļ��ʾ�Խ�����Բ�����һ��BFS��ͬ���ǶԱȷ��򣬵�����Ϊ
// �ߵ��յ�;��������·������ת��ļ���Ҳ����С�ģ������
// BFSֻҪ����ͬ�Ϳ��Լ�¼ 

// ������Ҫע������ô�ж��߲����յ㣬Ӧ�ÿ���ͨ��bfs�ķ���ֵ��
// ������ߵ������صľ�����һ�����ڵ���0����������Ĭ�Ϸ���-1 

// �����̣�׹���ˣ����ܺͷ����й�ϵ 

#define x first
#define y second
typedef pair<int, int > PII;
const int N = 110, M = N * N;
int n;
// ����ͬ�����ñ�Ƿ��ʹ���ֻ�ý��߹����ַ����˾��� 
char graph[N][N];
int sx, sy, ex, ey;
// �о�Ҫ������Ԫ�أ����������ø��ṹ�� 
// ʵ����Ҫ�����Ԫ�أ���Ϊ�䲻֪����ô�˳���һ���ߵķ����������ﻹҪ���·��� 
// ��Ȼ���԰ѷ���תΪ�ַ�������ֱ����move�������Ӧ��Ҳ�� 
struct Node {
	int x, y;
	string path;
	Node () {};
	Node (int x, int y, string path) : x(x), y(y), path(path) {};
};
Node que[M];
int move[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int getCnt(string str) {
	cout << str << endl;
	// ��ͷ�ķ����㣬��Ϊ��ʼλ�÷�����
	int sLen = str.size();
	int cnt = 0;
	int j = 1;
	// ˫ָ��ͳ���ж��ٸ��������ַ� 
	for (int i = 1; i < sLen; i++) {
		while (str[i] == str[j]) j++;
		cnt++;
		// ����������ط��е㲻�ǵ� 
		i = j - 1;
	} 
	return cnt;
} 
int bfs() {
	int qtop = 0, qback = 0;
	que[qtop] = Node(sx, sy, "");
	// ����������Ƕ�����ν�������Ȳ��������
	while (qtop <= qback) {
		Node now = que[qtop++];
		if (now.x == ex && now.y == ey) return getCnt(now.path);
		for (int i = 0; i < 4; i++) {
			int nx = now.x + move[i][0], ny = now.y + move[i][1];
			if (nx > n || nx < 1 || ny > n || ny < 1) continue;
			if (graph[nx][ny] != '.') continue;
			graph[nx][ny] = 'x';
			// ����ͻȻ���ϣ���ʵ���Լ�¼��ÿ���ߵķ����ж��ٸ��ַ���ͬ��˵���߹��˶�����· 
			que[++qback] = Node(nx, ny, now.path + char(i + 65)); 
		}
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 'A') sx = i, sy = j, graph[i][j] = '.';
			if (graph[i][j] == 'B') ex = i, ey = j, graph[i][j] = '.';
		}
	}
	cout << bfs();
	return 0;
} 
