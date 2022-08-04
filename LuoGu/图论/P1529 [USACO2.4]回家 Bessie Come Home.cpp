#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

// ��Ŀ��˵�������رߺ��Ի������������������ͼ�ƺ�û�п���������ڽӾ���Ҫ�����رߣ���
// ��ô�������ǰ���ĸӳ������֣���Ϊ��ΧС������ֱ�Ӱ���ĸ��������Ҳû�����⣩��Ȼ��
// ��ͼ�ܴ��յ������·������...������ͼ�����÷��򽨱ߣ� 

// ̫������...��û��ǲ�ҪϹ�����룬��Ϊ������������ַ��������Ǵ洢��Ԫ�������Σ�����������Ĵ���
// ������RE��������w��δ��ֵ���磩��ֵ��һ�������������ڱ����ǿ��Թ��ģ�����������Ͳ�һ���ˡ��ɴ�
// �ɼ������ָ��ӵ����뻹����cin���㣬������������ҲҪ��Ӧ���Ѿ����˺ܶ������Ŀ���ȴ�������Ե�мw�� 

typedef pair<int, int > PII;
const int N = 1e5 * 2 + 10, INF = 0x3fffffff;
int head[N], e[N], ex[N], w[N], idx = 0;
int dist[N];
bool visited[N];
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
void dijkstra() {
	priority_queue<PII, vector<PII >, greater<PII > > que;
	que.push(PII(0, 'Z'));
	fill(dist, dist + N, INF);
	dist['Z'] = 0;
	while (que.size()) {
		PII now = que.top();que.pop();
		int ut = now.second, wt = now.first;
		if (visited[ut]) continue;
		visited[ut] = true;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			if (dist[vt] > w[i] + wt) {
				dist[vt] = w[i] + wt;
				que.push(PII(dist[vt], vt)); 
			}
		}
	} 
	int res = INF;
	char c;
	for (int i = 'A'; i <= 'Y'; i++) 
		if (res > dist[i]) res = dist[i], c = i;
	printf("%c %d", c, res);
}
int main() {
	int n, wt;
	char ut, vt;
	scanf("%d", &n);
	getchar();
	fill(head, head + N, -1);
	for (int i = 0; i < n; i++) {
		// ����Ϲ��д����scanf("%c %c %d", &ut, &vt, &wt);��ʱut��vt��wt�������Σ��ڼ���getchar()֮�󱾻�����
		// û�����⣬�����ȫRE�������� 
		cin >> ut >> vt >> wt;
		getchar();
		// printf("%d %d %d\n", ut, vt, wt);
		add(ut, vt, wt), add(vt, ut, wt);
	}
	//getchar();
	dijkstra();
	return 0;
}
