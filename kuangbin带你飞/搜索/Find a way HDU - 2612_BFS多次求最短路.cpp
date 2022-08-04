#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

// �����Ӧ�þ���������BFS��Ȼ���¼������㵽@�ľ��룬���Ա���Сֵ����Ӿ�����..������������ܱȽ��鷳�����
// ��STLģ�����... 

// �����˷�����ĿҪ�����ʵ��һ���������˵���ʱ�����С�����������е������˵���ʱ�����С...���о����еĵ��������
// �˶������ˣ�����ǿ���..��������жϴ𰸾��Ի���w 

#define x first
#define y second
typedef pair<int, int > PII;
const int N = 200 + 10;
int n, m;
// ������������������� 
PII start[2];
char graph[N][N];
// �������BFS�ľ��� 
int _dist[N][N], __dist[N][N];
// bool visited[N][N];
// ��������յ����� 
PII eds[N * N + 10];
void bfs(PII st, int dist[N][N]) {
	// ����BFS�����Է�������Ҫ��γ�ʼ������dist���鲻�У���Ϊ����ֱ�ӵ�ָ�봫������ 
	// ͻȻ���ֲ���Ҫvisited���飬��Ϊdist��������𵽷��ʷ�Ĺ�����.. 
	//memset(visited, 0, sizeof visited);
	queue<PII > que;
	que.push(st);
	// ע���ʼ���������� 
	dist[st.x][st.y] = 0;
	while (que.size()) {
		PII now = que.front();que.pop();
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				// ������ 
				if ((i != 0 || j != 0) && i != j && i != -j) {
					int nx = now.x + i, ny = now.y + j;
					if (nx >= n || nx < 0 || ny >= m || ny < 0) continue; 
					if (graph[nx][ny] == '#') continue;
					if (dist[nx][ny] != -1) continue;
					// ����Ͳ���ֱ�Ӹĵ�ͼ�ˣ���Ϊ��ͼ����ʹ�� 
					// visited[nx][ny] = true;
					dist[nx][ny] = dist[now.x][now.y] + 1;
					que.push(PII(nx, ny));
				}
			}
		}
	}
}
int main() {
	int cnt;
	while (cin >> n >> m) {
		cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> graph[i][j];
				// ���ִ������Ĵ����յ�Ĵ���... 
				if (graph[i][j] == 'Y') {
					// �����ֱ������ 
					start[0] = PII(i, j);
					// ��Ŀ˵Y��MҲ���ϰ��� 
					graph[i][j] = '#';
				}
				if (graph[i][j] == 'M') {
					start[1] = PII(i, j);
					graph[i][j] = '#';
				}
				// ���յ���������������ֱ�Ӳ�ѯ���Ǹ���㵽Ŀǰ���յ�������.. ends��Ȼ��ͻ��... 
				if (graph[i][j] == '@') eds[cnt++] = PII(i, j);
			}
		}
		// ����������BFS 
		int res = INT_MAX;
		memset(_dist, -1, sizeof _dist);
		memset(__dist, -1, sizeof __dist);
		bfs(start[0], _dist);
		bfs(start[1], __dist);
		PII tp;
		for (int i = 0; i < cnt; i++) {
			tp = eds[i];
			// �ӵ㣺������һЩ�������˶������ˣ�Ӧ�ò�����ֻ��һ�����ܵ��ĵ㣩�������Ļ�����жϾͻᵼ��
			// �𰸳��ָ���...Ȼ���WA��w 
			if (_dist[tp.x][tp.y] == -1 || __dist[tp.x][tp.y] == -1) continue;
			res = min((_dist[tp.x][tp.y] + __dist[tp.x][tp.y]) * 11, res);
		}
		cout << res << endl;
	}
	return 0;
}
