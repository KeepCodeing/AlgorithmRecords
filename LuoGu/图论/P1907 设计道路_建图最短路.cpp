#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

// �Ƚϸ��ӵĵط��ǽ�ͼ.. 
// ׹����w����֪�����������WA��һ����..��Ϊɵ�ƴ���ͽ�������ͼҲWA������.. 

typedef pair<double, int > PII;
const int N = 1e3 + 10, M = N * N;
int head[M], e[M], ex[M], idx = 0;
double w[M], dist[M];
bool vis[M];
void add(int ut, int vt ,double wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
struct Poi {
	double x, y;
} poi[N];
struct Tpoi {
	int x, y;
	Tpoi(int x, int y) : x(x), y(y) {};
	bool operator<(const Tpoi& t) const {
		// ע��ȥ�ع���һ��Ҫ��ȫ... 
		if (y != t.y) return y < t.y;
		return x < t.x;
	}
};
map<Tpoi, bool > mp;
// ����Ӧ�ø���double��������int... 
double cpl(double x1, double y1, double x2, double y2) {
	return sqrt((x1 - x2 + .0) * (x1 - x2) + (y1 - y2 + .0) * (y1 - y2));
}
double dijkstra(int st, int ed) {
	for (int i = 0; i < M; i++) dist[i] = 0x3fffffff;
	priority_queue<PII, vector<PII >, greater<PII > > que;
	que.push(PII(.0, st));
	// ���˰����������㣬���ǲ�֪��Ϊʲôû��w... 
	dist[st] = .0;
	while (que.size()) {
		PII now = que.top(); que.pop();
		int ut = now.second;
		double wt = now.first;
		if (vis[ut]) continue;
		vis[ut] = true;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			if (dist[vt] > w[i] + wt) {
				dist[vt] = w[i] + wt;
				que.push(PII(dist[vt], vt)); 
			}
		}
	}
	return dist[ed]; 
}
int main() {
	memset(head, -1, sizeof head);
	double dr, rr;
	scanf("%lf%lf", &dr, &rr);
	int n, tx, ty;
	scanf("%d", &n);
	// ��ΪҪ����㣬���һ��������±�ӣ�����ֱ�Ӱ�������������� 
	for (int i = 2; i <= n + 1; i++) scanf("%lf%lf", &poi[i].x, &poi[i].y);
	// ͬ���������Եı��ҲҪ����... 
	while (scanf("%d%d", &tx, &ty), tx && ty) mp[Tpoi(tx + 1, ty + 1)] = true; 
	// �����յ�ҲҪ�������� 
	n += 2;
	scanf("%lf%lf", &poi[1].x, &poi[1].y);
	scanf("%lf%lf", &poi[n].x, &poi[n].y);
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			double t = cpl(poi[i].x, poi[i].y, poi[j].x, poi[j].y);
			// �����Ȩ�����һ���֪���ǵ���߻���˫���w����һ����С�������ĸо�w��... 
			if (mp[Tpoi(i, j)]) add(i, j, t * rr), add(j, i, t * rr);
			else add(i, j, t * dr), add(j, i, t * dr);
		}
	}
	printf("%.4lf", dijkstra(1, n));
//	for (int i = 1; i <= n; i++) {
//		printf("%.2lf %.2lf\n", poi[i].x, poi[i].y);
//	}
	return 0;
}
