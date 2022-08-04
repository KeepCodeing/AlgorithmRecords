#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

// ��Ϊ�þ�ûˢ����ϲ��ɿ��������棩�������︴ϰ������������·����С������ 

// �������Է���ͼ��������Դ�㣬�Ƚ��������һ���� 

// �����ܽ���Ϊʲô�������ˣ����ȣ�����û������Ϳ�ʼϹд����ĿҪ������������صĺ͵����ֵ����ȴ�������һ��ȥ�����ֵ�� 
// Ȼ��Ī������������Դ�����˴�������Сֵ��������һ�������ĳ��ĺͿ϶��ǷǷ��ģ�����һ����ȥ����Сֵ��С��������Сֵ
// ȴ������...���Ǻ���ģ�����Ǳ������ˣ����ģ�������þ�û��Ҳ������д�������... 

typedef pair<int, int > PII;
const int N = 1000 * 10 + 10, M = 100000 * 5 + 10, INF = 0x3fffffff;

int head[N], e[M], ex[M], w[M], idx = 0;
int head1[N], e1[M], ex1[M], w1[M], idx1 = 0;
int dist1[M];
int dist[M];
bool visited[N];
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
void add1(int ut, int vt, int wt) {
	e1[idx1] = vt, w1[idx1] = wt, ex1[idx1] = head1[ut], head1[ut] = idx1++; 
}
void dijkstra(int st) {
	memset(visited, 0, sizeof visited);
	memset(dist, 0x3f, sizeof dist);
	priority_queue<PII, vector<PII >, greater<PII > > que;
	// ע��������������ʼ��... 
	dist[st] = 0;
	que.push(PII(0, st));
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
}
// ����Դ��дը�ˣ���д�����·...
void dijkstra1(int st) {
	memset(visited, 0, sizeof visited);
	memset(dist1, 0x3f, sizeof dist1);
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
int main() {
	int n, m, x;
	memset(head, -1, sizeof head);
	memset(head1, -1, sizeof head1);
	scanf("%d%d%d", &n, &m, &x);
	int ut, vt, wt;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &ut, &vt, &wt);
		add(ut, vt, wt);
		// ��������ʵʵ����ͼ��Ȼ�����������·��������... 
		add1(vt, ut, wt); 
	}
	// ������Դ�㣨�� 
//	for (int i = 1; i <= n; i++) 
//		if (i != x) add(0, i, 0);
	// ���ţ��ȥ�����·��ֵ 
	dijkstra(x);
	// ���ţ�������·��ֵ
	dijkstra1(x); 
	int res = 0;
	for (int i = 1; i <= n; i++) {
		res = max(res, dist[i] + dist1[i]);
	}
	printf("%d", res);
	// ͨ������Դ�����ţ�������·�������Ǵ����Ҫ˵�Ļ�������Ŀ��û������Ϳ�ʼд�ˣ�������ĿҪ��
	// ����һͷţ���ص����·֮�͵����ֵ����ô˼���¿ɲ�����һͷţȥ�����·��ֵ����С�ģ��������·
	// ��ֵȴ�����������ֵ���Ҳ�����ģ�����У���ô���ǵ�һ�����·��ľ��Ǵ�ģ���Ϊ��һ�����·
	// ���������ţ��ȥ�����·�����ֵ����������Բ���������������˵�ģ���ô�ٿ��ڶ������·����ľ���
	// ���е㵽�յ�����·����������·��ʲô���أ�������·ʲô�ö�û�У���Ϊ����Ҫʹ����·�����
	// ����ȥ��·��ȡ���е���Сֵ���ص�·��ȡ���ֵ...�ɴˣ�����������ֻ���Ƿ���ͼȻ�����������·
	// ������... 
//	dijkstra(0, 0);
//	// 46
//	for (int i = 1; i <= n; i++) cout << dist[i] << ' ';
	return 0;
}


