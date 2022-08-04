#include <iostream>
#include <queue>
using namespace std;

// ���������Ƚ����أ�������˼�Ǵ�1�ŵ㿪ʼ����������1�ŵ��бߵĵ������չ��
// �����ͼ�Ļ���������BFS����ɢ���̡�Ȼ����չ���ĵ��ٽ�����չ����������
// ֱ�����е㶼����ɢ���ˣ�����е�û����ɢ����˵���޽⣩���������Ƚ��ԣ�����
// ������ǰѱ�Ȩ����ȥ����ͼ�Ϳ��Է��֣�����������BFS�����·����һ����Ҳ����
// ˵��һ�α���չ���ĵ�ľ���һ������̵ģ�������չ��ȥ�Ĺ�����Ϊ������ʵĴ���
// Ҳ�Ϳ��Ժ��Բ����ˡ���ô�����Ҳ��һ�����������·���⣬������Ϊ���ݷ�Χ
// ��С�����Կ�����floyd��һ��ȫԴ���·��Ȼ��ͳ���¸����ܷ�1�ŵ㣬�Լ�����
// ��1�ŵ�ľ���֮�͡�

// ����Ϊ��fuxi Dijkstra�������д�� 

typedef pair<int, int > PII;
const int N = 110, M = 210, INF = 0x3fffffff;
int head[N], e[M], ex[M], w[M], idx = 0;
int dist[M];
bool visited[N];
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
void dijkstra(int st) {
	priority_queue<PII, vector<PII >, greater<PII > > que;
	que.push(PII(0, st));
	dist[st] = 0;
	while (que.size()) {
		PII now = que.top();que.pop();
		int ut = now.second, wt = now.first;
		if (visited[ut]) continue;
		visited[ut] = true;
		// ����i��ʵ��idx��Ҳ���ǽڵ��� 
		for (int i = head[ut]; i != -1; i = ex[i]) {
			// ȡ������ڵ�ı�� 
			int vt = e[i];
			// �ж����Ƿ����ͨ��ut��w[i]�����ɳ�..��������ȡ�±�Ĳ�����ʵ������ȡ�ڵ��ţ�����������ȥ
			// ���Ǿ������Ƚ��鷳�����ܣ����ɴ�Ͱ��о�������... 
			if (dist[vt] > wt + w[i]) {
				dist[vt] = wt + w[i];
				que.push(PII(dist[vt], vt)); 
			}
		}
	} 
}
int main() {
	int n, m;
	cin >> n >> m;
	int ut, vt, wt;
	fill(head, head + N, -1);
	fill(dist, dist + N, INF);
	for (int i = 1; i <= m; i++) cin >> ut >> vt >> wt, add(ut, vt, wt), add(vt, ut, wt);
	dijkstra(1);
	int res = -1;
	for (int i = 1; i <= n; i++) {
		// �ⲻ�Ϸ� 
		if (dist[i] == INF) {
			cout << -1;
			return 0;
		}
		// ��Ϊ����BFS�����ԣ�����1�ŵ㵽���һ�������̾���һ�������ģ��������
		// �����������̾��룬�е���������Ǹ��� 
		res = max(res, dist[i]);
	}
	cout << res;
	return 0;
}
/*
4 4
1 2 4
2 3 7
2 4 1
3 4 6

11
*/
