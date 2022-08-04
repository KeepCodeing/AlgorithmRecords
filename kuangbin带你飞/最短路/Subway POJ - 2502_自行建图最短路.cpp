#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
using namespace std;

// �����������ⲻһ���������Ҫ�������Լ�������ĿȻ����ȷ��ͼ...�������ȷ�����������Ŀ�ģ�Ҫ�ж��Ǵ����������յ�
// �컹���ߵ��յ�죬ֻ�����ڵ�����վ̨���ܻ��ൽ�ͼ�￴����Ӧ������һ��ֱ�ߣ������ǿ���ѡ���ߵ�����һ��վ̨�ϳ�����
// ������һ��վ̨�³��ߵ��յ������һ��վ̨...
// ��ô���ǽ�ͼ��Ҫ����������ˣ��������Ǹ�ÿ��վ̨һ����ţ���Ϊ���Դ�����һ��վ̨�ߵ��յ������㣬���ÿ��վ̨��Ҫ��
// �յ�������ߡ������Ϊֻ�����ڵ�վ̨�ܻ��ൽ��������ǻ�Ҫ��¼��һ��վ̨��λ�ã�Ȼ������һ��վ̨�͵�ǰվ̨���ߣ����
// ��Ϊ���ǿ��Դ�����һ��վ̨��·������վ̨�����Ի�Ҫö������վ̨�����ǻ�����һ����·�ı�...����ͼ�������·������ 

// û�����Ӷ��ű��˵Ĵ���д���...û�иɾ�w... 

typedef pair<double, int > PII;
const int N = 205, M = 5e4 + 10;
const double INF = 1e18 + .0;
int sx, sy, edx, edy;
int head[N], e[M], ex[M], idx = 0;
double dist[N];
bool vis[N];
double w[M];
void add(int ut, int vt, double wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
// �����Ȩ��ע����Ŀ����km/h����Ҫ��m/m 
double cpl(int x1, int y1, int x2, int y2, int tm) {
	int t1 = x1 - x2, t2 = y1 - y2;
	// �������/ÿСʱ�ߵ��ٶ��ٻ�ԭ����/ÿ���� 
	return sqrt(t1 * t1 + t2 * t2) / tm / 1000 * 60;
}
// ��¼��ǰվ���� 
int id = 1;
// ���վ����Ϣ�Ľṹ������ 
struct Station {
	int x, y;
} station[N]; 
double dijkstra(int st) {
	for (int i = 1; i < id; i++) dist[i] = INF;
	// ע����㲻���ߣ��յ����û�е����ܹ�ֱ�ӵ�������Ҫ�ֶ���ʼ�� 
	dist[st] = 0, dist[201] = INF;
	priority_queue<PII, vector<PII >, greater<PII > > que;
	que.push(PII(.0, st));
	while (que.size()) {
		PII now = que.top();que.pop();
		int ut = now.second;
		double wt = now.first;
		if (vis[ut]) continue;
		vis[ut] = true;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			if (dist[vt] > wt + w[i]) {
				dist[vt] = wt + w[i];
				que.push(PII(dist[vt], vt)); 
			}
		}
	}
	return dist[201];
}
int main() {
	memset(head, -1, sizeof head);
	int x, y, px, py;
	scanf("%d%d%d%d", &sx, &sy, &edx, &edy);
	// ����������Բ����жϵ�һ��վ����û����һ��վ��... 
	while (~scanf("%d%d", &station[id].x, &station[id].y)) {
		x = station[id].x, y = station[id].y;
		// ÿ��վ�㶼����ֱ���ߵ��յ�������
		add(0, id, cpl(x, y, sx, sy, 10));
		add(id, 201, cpl(x, y, edx, edy, 10));
		id++;
		while (~scanf("%d%d", &station[id].x, &station[id].y), station[id].x != -1) {
			// ��ȡ��һ��վ�����Ϣ 
			px = station[id - 1].x, py = station[id - 1].y;
			x = station[id].x, y = station[id].y; 
			// ��һ��վ��͵�ǰվ�����ͨ���������ൽ��
			add(id, id - 1, cpl(x, y, px, py, 40));
			add(id - 1, id, cpl(x, y, px, py, 40));
			// ���Դ���һ��վ���ߵ���ǰվ�㣬��ǰվ��Ҳ�����߻���һ��վ�㣬����ɴ��д�����棬��Ϊ���Դӵ�ǰվ���ߵ�����
			// վ��... 
			// add(idx, idx - 1, cpl(x, y, px, py, 10));
			// add(idx - 1, idx, cpl(x, y, px, py, 10));
			// �ӵ�ǰվ������Ǵ�����߹����ģ�Ҳ����ֱ���ߵ��յ� 
			add(0, id, cpl(x, y, sx, sy, 10));
			add(id, 201, cpl(x, y, edx, edy, 10));
			id++; 
		}
	}
	// ÿ��վ̨֮����Բ���  �ܹ��ı����[1, id-1]����Ϊ��idx++�����������������ʱ����Ǹ����ǲ����ڵ�... 
	int tx1, tx2, ty1, ty2;
	// for (int i = 1; i < id; i++) cout << station[i].x << ' ' << station[i].y << endl;
	for (int i = 1; i < id; i++) {
		for (int j = i + 1; j < id; j++) {
			tx1 = station[i].x, ty1 = station[i].y;
			tx2 = station[j].x, ty2 = station[j].y;
			add(i, j, cpl(tx1, ty1, tx2, ty2, 10));
			add(j, i, cpl(tx1, ty1, tx2, ty2, 10));
		}
	}
	// ����������� 
	printf("%d", (int)(dijkstra(0) + 0.5));
	return 0;
}
//#include <cstdio>
//#include <cmath>
//#include <iostream>
//#include <cstring>
//#include <queue> 
//using namespace std;
//const int N = 205, M = 5e4 + 5;
//struct E {
//	int v, next;
//	double w;
//} e[M];
//struct Stop {
//	int x, y;
//} stop[N];
//int id = 1, x, y, lx, ly, sx, sy, ex, ey, len = 1, h[N];//id�����ı�� 
//bool vis[N]; //�����0 �յ�ı����201 ��Ϊ�����200��վ�� 
//double d[N];
//double getD(int x1, int y1, int x2, int y2, int t) {
//	double x = x1 - x2;
//	double y = y1 - y2;
//	cout << x1 << ' ' << x2 << ' ' << y1 << ' ' << y2 << ' ' << t << endl;
//	cout << sqrt(x*x + y*y) / t / 1000 * 60 << endl;
//	return sqrt(x*x + y*y) / t / 1000 * 60; 
//}
//void add(int u, int v, double w) {
//	e[len].v = v;
//	e[len].w = w;
//	e[len].next = h[u];
//	h[u] = len++;
//}
////��a > b ����true a <= b ����false 
//bool cmp(double a, double b) {
//	if (a - b > 1e-4) return true;
//	return false;
//}
//void spfa() {
//    for (int i = 1; i < id; i++) d[i] = 1e18; 
//	d[0] = 0; d[201] = 1e18;
//	queue<int> q;
//	q.push(0);
//	while (!q.empty()) {
//		int u = q.front();
//		q.pop();
//		vis[u] = false;
//		for (int j = h[u]; j; j = e[j].next) {
//			int v = e[j].v;
//			double w = d[u] + e[j].w;
//			if (cmp(d[v], w)) {
//				d[v] = w;
//				if (!vis[v]) q.push(v), vis[v] = true;
//			} 
//		}
//	}
//}
//int main() {
//	scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
//	while (~scanf("%d%d", &stop[id].x, &stop[id].y)) {
//		x = stop[id].x, y = stop[id].y;
//		add(0, id, getD(x, y, sx, sy, 10));
//		add(id, 201, getD(x, y, ex, ey, 10));
//		++id; 
//		while (scanf("%d%d", &stop[id].x, &stop[id].y), stop[id].x != -1) {
//			x = stop[id].x, y = stop[id].y;
//			lx = stop[id - 1].x, ly = stop[id - 1].y;
//			//��վ�㲽�е��յ� ����� 
//			add(0, id, getD(x, y, sx, sy, 10));
//			add(id, 201, getD(x, y, ex, ey, 10)); 
//			//������ǰһ��վ��ı�
//			add(id, id - 1, getD(x, y, lx, ly, 40)); 
//			add(id - 1, id, getD(x, y, lx, ly, 40));
//	 		++id; //-1��ʱ��id���� 
//		} 
//	}
//	//ÿ��վ̨֮����Բ���  �ܹ��ı���ǡ�1, id-1�� 
//	// for (int i = 1; i < id; i++) cout << stop[i].x << ' ' << stop[i].y << endl;
//	for (int i = 1; i < id; i++) {
//		for (int j = i + 1; j < id; j++) {
//			x = stop[i].x, y = stop[i].y;
//			lx = stop[j].x, ly = stop[j].y;
//			add(i, j, getD(x, y, lx, ly, 10));
//			add(j, i, getD(x, y, lx, ly, 10));
//		}
//	}
//	spfa();
//	printf("%d", int(d[201] + 0.5));//�������� 
//	return 0;
//}
///*
//0 0 10000 1000
//0 200 5000 200 7000 200 -1 -1
//0 0 200 0 10
//nan
//0 10000 200 1000 10
//59.8077
//5000 0 200 200 40
//7.5
//5000 0 200 200 40
//7.5
//5000 0 200 0 10
//29.976
//5000 10000 200 1000 10
//29.6135
//7000 5000 200 200 40
//3
//7000 5000 200 200 40
//3
//7000 0 200 0 10
//41.9829
//7000 10000 200 1000 10
//17.3482
//2000 600 5000 600 10000 600 -1 -1
//2000 0 600 0 10
//11.4473
//2000 10000 600 1000 10
//47.94
//5000 2000 600 600 40
//4.5
//5000 2000 600 600 40
//4.5
//5000 0 600 0 10
//29.7832
//5000 10000 600 1000 10
//29.9038
//10000 5000 600 600 40
//7.5
//10000 5000 600 600 40
//7.5
//10000 0 600 0 10
//59.8919
//10000 10000 600 1000 10
//nan
//
//*/
