#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

// ��֪������Դ���ܲ��ܽ������֮�ȸ�����ϲ������������0�㣬Ȼ���ܹ������·��Ȼ��ͳ�����Ǹ���
// ��ֵ��С... 
// Ȼ������Դ��û��ʲô�ã�д�˸�n^2logn�Ķ��Dijkstra����ʱ��... 
// ����������д���ˣ�����д�ĳ��õ�ȴ��int...Ȼ��O2����ȥ�ˣ����²����ܲ��ܹ�..ԭ�������Ƿ�
// ������û��O2...��ʵһ���⽻5������価������ͨ���ʵĳ���..����û�취�أ��������ǳ�����֭����... 

typedef pair<int, int > PII;
const int N = 510, M = 8000 * 2 + 10;
int head[N], e[M], ex[M], w[M], idx = 0;
int dist[N];
int visited[N];
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
void dijkstra(int st) {
	memset(dist, 0x3f, sizeof dist);
	memset(visited, 0, sizeof visited);
	priority_queue<PII, vector<PII >, greater<PII > > que;
	que.push(PII(0, st));
	dist[st] = 0;
	while (que.size()) {
		PII now = que.top();que.pop();
		int ut = now.second, wt = now.first;
		if (visited[ut]) continue;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			if (dist[vt] > wt + w[i]) {
				dist[vt] = wt + w[i];
				que.push(PII(dist[vt], vt)); 
			}
		}
	}
}
vector<int > fov;
int main() {
	memset(head, -1, sizeof head);
	int p, f, c;
	scanf("%d%d%d", &p, &f, &c);
	int ft;
	for (int i = 0; i < f; i++) {
		scanf("%d", &ft);
		fov.push_back(ft); 
	}
	int ut, vt, wt;
	for (int i = 0; i < c; i++) {
		scanf("%d%d%d", &ut, &vt, &wt);
		// �����Ȼ��д��add(ut, vt, wt), (vt, ut, wt);...
		add(ut, vt, wt), add(vt, ut, wt);
	}
	double minPath = 1e9;
	double temp;
	int fLen = fov.size(), res;
	for (int i = 1; i <= p; i++) {
		dijkstra(i), temp = .0;
		for (int j = 0; j < fLen; j++) temp += dist[fov[j]];
		// �����Ȼ��д�����������ͣ����Ҹ�����... 
		temp /= .0 + f;
		if (minPath > temp) {
			minPath = temp;
			res = i;
		}
	}
	printf("%d", res);
	return 0;
}

