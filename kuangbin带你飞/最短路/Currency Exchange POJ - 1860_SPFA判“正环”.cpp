#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

// �����ѧ��SPFA��֪���Ǹ���ģ�֮ǰ��ȫ������w...��ô�����Ҫ��ľ�����û��һ��·����1�������ܻص�1��ʹ��1��1��
// �����·����һ��ʼ1��1�����·����....���������ƣ������ܽ������һ����ʹ1��Ȩֵ����Ļ�·�����������Dijkstra��
// ˼·���Ļ������Ժ����Եķ���Dijkstra�����·�������γɻ�·����Ҫ���γɻ�·��Ҳ����ζ��һ������Զ�ξ���������
// �������SPFA����������ô��ô���أ����ȿ������ʹȨֵ��������˼��SPFA��һ�����·���ɳ���������ʵ��Dijkstraһ��
// ���ǵ��ߵĳ��ȿ���ͨ�����ӵĵ������̣���ô�ͽ����ɳڡ�����ͬ�������������Ƶ�˼·������ǰ�ߵı�Ȩ�����ʱ������
// �Ž��С��ɳڡ�����ô��������ô�ж��Ƿ��л�·�Լ��ܷ�֤1��Ȩֵ��������ʵҲ�ܼ򵥣�����ֻ��Ҫ�ж��µ�ǰ��ͷ 
// �ĵ��ǲ���1������ˣ������1�㣬��˵������һ��·������ʹ�ô�1�����ٻص�1������Ŀ�е������������û��ʲ��Ͻ�������
// Ȼ��ʹ������õĻ���ֵ������ô��·Ҳ���ˣ���ֻ���ж���1���ֵ�ǲ��Ǳ�һ��ʼ��ֵ�������...
// ����˵�˺ܶ࣬�ڴ�����ʵ���ǽ�ͼ����˼������Ʊ�Ȩ�Ķ������Լ����ɳڡ��������������ʹ��Ȩ�������ж��µ�ǰ��ͷ��
// �ǲ������... 

// ����ⷸ���붼û����Ĵ��󣺽�ͼ����w�������ɴ�Ⱦ�ѵ�ʱ���д���򻹳�����֮�ø���ҵ�ˣ��ߴ���Ӣ������߼�����...
// ���ҲҪ�����ˣ�������Ļ������Խ��Խ����... 

const int N = 100 + 10, M = N * 2;
int head[N], e[M], ex[M], idx = 0;
// ������Ӷ�����ԣ�����Ӣ���ĩ·w 
double hl[M], yj[M];
double dist[N];
bool visited[N];
void add(int ut, int vt, double hlt, double yjt) {
	// ���ｨͼ��Ȼд���ˣ������д�˸�head[ut] = idx��Ȼ��ͼ��ž��Ǻܶ���Ի��������һֱ��ѭ��... 
	e[idx] = vt, hl[idx] = hlt, yj[idx] = yjt, ex[idx] = head[ut], head[ut] = idx++;
}
int n, m, st;
double sval;
bool spfa() {
	// ���������ѭ����ʼ������Ϊ����double���ͣ�����Ӧ�ò��ó�ʼ������Ϊ�����ط���Ǯ��û��������Ϊ0... 
	// for (int i = 0; i < N; i++) dist[i] = 1e9, visited[i] = false;
	// for (int i = 0; i < N; i++) dist[i] = .0;
	// ���һ��ʼ��svalԪ 
	memset(visited, 0, sizeof visited);
	dist[st] = sval;
	queue<int > que;
	que.push(st);
	while (que.size()) {
		int ut = que.front();que.pop();
		visited[ut] = false;
		// ����ܻ������ϵ�Ǯ�����ͣ��ж����ǲ��Ǳ�һ��ʼ׬�ˣ��������;��ǽڵ���... 
		if (ut == st && dist[st] > sval) return true;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			// ��Ŀ�ļ��㹫ʽ��(���ϵ�Ǯ-Ӷ��)*���ʣ�����ut�������ϵ�Ǯ�ı�ţ�vt����Ҫ����Ǯ�ı�ţ�Ҳ����˵������... 
			double wt = (dist[ut] - yj[i]) * hl[i];
			// �޸ĺ���ɳ�����������ʹ�ñ�Ȩ����.. 
			if (dist[vt] < wt) {
				dist[vt] = wt;
				if (!visited[vt]) {
					visited[vt] = true;
					que.push(vt); 	
				}
			}
		}
	} 
	return false;
}
int main() {
	// ���˳�ʼ��ͷ���... 
	memset(head, -1, sizeof head);
	// ��������������㣬����ʼֵ������Ի��ҵ��������ǶԶ������������������ʵ���Ƕ�����... 
	scanf("%d%d%d%lf", &n, &m, &st, &sval); 
	int ut, vt;
	double hl1, yj1, hl2, yj2;
	while (m--) {
		// ���ߣ�����Ӧ����˫��ߣ���Ϊa���Ե�b��ͬ��bҲ���Ե�a����ô�����û����ν��Ȩ�ˣ�ֻ�л��ʺ�Ӷ������������ 
		scanf("%d%d%lf%lf%lf%lf", &ut, &vt, &hl1, &yj1, &hl2, &yj2);
		 // ��ͼ��ע�⵽�������ر�Ȩ��һ�����������һ��ǿ��ͨͼ... 
		add(ut, vt, hl1, yj1), add(vt, ut, hl2, yj2);
	}
	cout << (spfa() ? "YES" : "NO");
	return 0;
}
/*
3 1 1 20.0
2 3 1.10 1.00 1.10 1.00
1 2 1.00 1.00 1.00 1.00
*/
/*#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;
const int N = 105, M = 205;
struct E {
	int v, next;
	double rt, cm; //rt���� cmӶ�� 
} e[M];
int n, m, u, v, s, h[N], len = 1;  
bool vis[N]; 
double d[N], urt, ucm, vrt, vcm, it; //it�ǳ�ʼ�� 
void add(int u, int v, double rt, double cm) {
	e[len].v = v;
	e[len].next = h[u];
	e[len].rt = rt;
	e[len].cm = cm;
	h[u] = len++;
}
int spfa() {
	d[s] = it; //��ʼ�����λ�õ�Ǯ  ����λ�õ�ǮΪ0 
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = false;
		if (u == s && d[u] > it) return 1; //��������Ǯ���ڳ�ʼ��Ǯ  
		for (int j = h[u]; j; j = e[j].next) {
			int v = e[j].v;
			cout << v << endl;
			double w = (d[u] - e[j].cm) * e[j].rt;
			if (d[v] < w) { //������ν�������һ��׬ 
				d[v] = w;
				if (!vis[v]) {
					q.push(v); vis[v] = true;
				}
			}
		}
	} 
	return 0;
}
int main() {
	scanf("%d%d%d%lf", &n, &m, &s, &it); 
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%lf%lf%lf%lf", &u, &v, &urt, &ucm, &vrt, &vcm);
		add(u, v, urt, ucm);
		add(v, u, vrt, vcm);
	} 
	if (spfa()) printf("YES");
	else printf("NO");
	return 0; 
} 
*/
