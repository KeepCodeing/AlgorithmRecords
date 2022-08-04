#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

// ��Ż���ͼ��С��ͨ�������ݽṹѧ�Ļ�����Ȼ�󿴵İ����㷨ѧ��ģ��w���Ϳ���������⣬��ʱ����ȫ�±�
// �����֪����ĿҪ�����·��������ȫ��֪����ôд�����Ӱ�...
// ˼·�����������·��һ����1�����ж���ľ��루ȥ�ľ��룩������һ�鷴��ͼ�������е㵽1�ľ��루�صľ��룩���� 
// ����������cow party�Ǹ��ⲻͬ�������������������n�����·�϶���TLE��... 

// ��ʵ����дһ��dijkstra�͹��ˣ�������ͼ�����˰�dist��������Ȼ���ܷ���ͼ��ʱ���ٻ�ԭdist���У�ΪʲôҪд
// ����������ʵ����Ϊ����ͼ��һ��������Ľ�������ǰѶ��㣬��Ȩ������������������ͼ��ԭidx��Ȼ����������ͼ
// �����齨������ͼ������������дһ��������.. 

const int N = 1e3 + 10, M = 1e5 + 10, INF = 0x3fffffff;
typedef pair<int, int > PII;
int head1[N], e1[M], ex1[M], w1[M], idx1 = 0;
int head2[N], e2[M], ex2[M], w2[M], idx2 = 0;
int dist1[N], dist2[N];
bool visited[N];
void add1(int ut, int vt, int wt) {
	e1[idx1] = vt, w1[idx1] = wt, ex1[idx1] = head1[ut], head1[ut] = idx1++;
}
void add2(int ut, int vt, int wt) {
	e2[idx2] = vt, w2[idx2] = wt, ex2[idx2] = head2[ut], head2[ut] = idx2++;
}
// �����е�ȥ�ľ��� 
void dijkstra1(int st) {
	fill(dist1, dist1 + N, INF);
	priority_queue<PII, vector<PII >, greater<PII > > que;
	dist1[st] = 0;
	que.push(PII(0, st));
	while (que.size()) {
		PII now = que.top();que.pop();
		int ut = now.second, wt = now.first;
		if (visited[ut]) continue;
		visited[ut] = true;
		for (int i = head1[ut]; i != -1; i = ex1[i]) {
			int vt = e1[i];
			if (dist1[vt] > w1[i] + wt) {
				dist1[vt] = w1[i] + wt;
				que.push(PII(dist1[vt], vt)); 
			}
		}
	}
}
// �����е�صľ��� 
void dijkstra2(int st) {
	fill(dist2, dist2 + N, INF);
	fill(visited, visited + N, false);
	priority_queue<PII, vector<PII >, greater<PII > > que;
	dist2[st] = 0;
	que.push(PII(0, st));
	while (que.size()) {
		PII now = que.top();que.pop();
		int ut = now.second, wt = now.first;
		if (visited[ut]) continue;
		visited[ut] = true;
		for (int i = head2[ut]; i != -1; i = ex2[i]) {
			int vt = e2[i];
			if (dist2[vt] > w2[i] + wt) {
				dist2[vt] = w2[i] + wt;
				que.push(PII(dist2[vt], vt)); 
			}
		}
	}
}
int main() {
	int n, m, ut, vt, wt;
	scanf("%d%d", &n, &m);
	fill(head1, head1 + N, -1);
	fill(head2, head2 + N, -1);
	while (m--) {
		scanf("%d%d%d", &ut, &vt, &wt);
		add1(ut, vt, wt), add2(vt, ut, wt); // ����ͼ�����ﷴ��ͼ��Ҳ���ǰѱߵķ��򷴹����� 
	}
	dijkstra1(1);
	dijkstra2(1);
	int res = 0;
	// һ��AC��ϲ�� 
	for (int i = 1; i <= n; i++) res += dist1[i] + dist2[i];
	cout << res;
	return 0;
}
