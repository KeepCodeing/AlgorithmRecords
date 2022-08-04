#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

// ��ϰ�ڶ�������������ģ������
// ��ô������������һ�������յ㵽�������·��ע�⣬������Ȼ��������Դ�㣬��Ϊ����Ҫ��Ĳ��ǹ������·������ÿ��
// ������·����Ȼ������һ����㵽�����յ�����·�����ǵ�������һ�Σ��������յ����·Ҫ��N - 1�Σ��������ͼ��� 
// ���⿼���費��Ҫ��ν����ͼ�����Է����ǲ���Ҫ�ģ���Ϊ������ȥ���ǻض���·����������ͼ���������󹫹����·��.. 

// �����ˣ��水�������˼·������N - 1�����·�������ܿ��ܳ�ʱ�����⻹�Ƿ���ͼ
// �������е㵽1�����̾��룬��ʵ���Ƿ���ͼ��1�����е�ľ���.. 

// ��ôһ������ͼ��Ȼ������չ������ȴ���ø������������Դ��ֻ�������������Ĺ������·�����... 
// �Ƚ�����w�����������ⶼ����ȷд�����룬����˼·���ٶ�ճ������֪���ǲ���û��ϸ���⣨���飩 

typedef pair<int, int > PII;
typedef long long LL;
const int N = 1e3 * 10 + 10, M = 1e5 * 5 + 10;
int head[N], e[M], ex[M], w[M], idx = 0;
int _head[N], _e[M], _ex[M], _w[M], _idx = 0;
bool visited[N];
int dist[N], _dist[N];
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
void _add(int ut, int vt, int wt) {
	_e[_idx] = vt, _w[_idx] = wt, _ex[_idx] = _head[ut], _head[ut] = _idx++;
}
// �����ȥ�����· 
int dijkstra(int st, int n) {
	// ��˵memset�����帳ֵ���ķ�ʽ������һ����ֵ�����ļ�����0x3f����Ϊmemset�ᰴ�ֽڸ�ֵ 
	memset(dist, 0x3f, sizeof dist);
	memset(visited, 0, sizeof visited);
	priority_queue<PII, vector<PII >, greater<PII > > que;
	que.push(PII(0, st));
	dist[st] = 0; // һ��Ҫע�����ĳ�ʼ��Ŷ 
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
	int res = 0;
	// ������������2~n��1�����·���������ǵ�1�����·��ֵ 
	for (int i = 1; i <= n; i++) res += dist[i];
	return res;
} 
int dijkstra2(int st, int n) {
	memset(visited, 0, sizeof visited);
	memset(_dist, 0x3f, sizeof _dist);
	priority_queue<PII, vector<PII >, greater<PII > > que;
	_dist[st] = 0;
	que.push(PII(0, st)); 
	while (que.size()) {
		PII now = que.top();que.pop();
		int ut = now.second, wt = now.first;
		if (visited[ut]) continue;
		visited[ut] = true;
		for (int i = _head[ut]; i != -1; i = _ex[i]) {
			int vt = _e[i];
			if (_dist[vt] > _w[i] + wt) {
				_dist[vt] = _w[i] + wt;
				que.push(PII(_dist[vt], vt)); 
			}
		}
	}
	int res = 0;
	for (int i = 1; i <= n; i++) res += _dist[i];
	return res;
}
int main() {
	int n, m;
	memset(head, -1, sizeof head);
	memset(_head, -1, sizeof _head);
	scanf("%d%d", &n, &m);
	int ut, vt, wt;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &ut, &vt, &wt);
		add(ut, vt, wt), _add(vt, ut, wt);
	}
	printf("%d",  dijkstra(1, n) + dijkstra2(1, n));
//	// ��2~n��1�����· 
//	for (int i = 2; i <= n; i++) {
//		res += dijkstra(i, false, n);
//	}
//	// ����һ��1��2~n�����· 
//	res += dijkstra(1, true, n);
//	printf("%ld", res);
	return 0;
}
