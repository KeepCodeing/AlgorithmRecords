#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

// ����fuxi���·�ˣ������Ƚ�����˼��������һ����ͨ���·��ȫԴ���·���б�Ҫ�������� 

// �����¹ʶ�֪��w����εĽ��������н������ŵģ������Ǵ���������Ϊ����һ��Dijkstra��������������������ģ������
// Ȼ������ڴ��ˣ�֮ǰ��ͼ�Ƚ����ԣ�������������߶����ķǳ��������Ϊ���˱�������û�п��ܴ�ֵ��һ����Ǵ󲿷���Ŀ
// ��һ�������������˵Ļ�����ͼ�������ݷ�Χ������ͼҪ��2����������Trie֮����⣬���鶼Ҫ�����㹻����У�û����������Ҳһ����
// ���������ʱ�䣬���ֻ����40m������60m����... 

typedef pair<int, int > PII;
const int N = 1000 + 10, M = 100000 + 10;
int head[N], e[M], ex[M], w[M], idx = 0;
int _head[N], _e[M], _ex[M], _w[M], _idx = 0;
bool visited[N];
int dist[N], _dist[N];
int n, m, x;
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
void _add(int ut, int vt, int wt) {
	_e[_idx] = vt, _w[_idx] = wt, _ex[_idx] = _head[ut], _head[ut] = _idx++;
}
// ����÷����İ취������Ȼ����ͼֻ�Ǿ������鲻ͬ����Ҳû��Ҫ��дһ��Dijkstra�ˣ�ֱ�Ӵ������������... 
// ��ʵͼҲ��ͬ�ˣ����Ի�Ҫ��ͼ���ɲ�������ȥ
// ע��������ĳ�ʼ�����⣬����ȥ�ľ���һ��ָ�룬��Ϊsizeof�õ��������ָ����������͵�ռ�ֽ�����Ҳ��������
// ��һ��Ԫ�ص�ռ�ֽ�����Ҫ������������Ҫ������������Ԫ�ظ��� 
// ����˵���Ǹ�����׹����ww�����ǵ�������ֱ�ӳ�ʼ����Ȼ����Ϊ�������ݣ������ʼ����ֵ��Ȼ������-1��... 
void dijkstra(int st, int tdist[], int thead[], int te[], int tw[], int tex[]) {
	memset(visited, 0, sizeof visited);
//	cout << sizeof dist << "--";
//	cout << sizeof(int) * N << ' ';
//	memset(tdist, -1, sizeof tdist * N);
	priority_queue<PII, vector<PII >, greater<PII > > que;
	que.push(PII(0, st));
	tdist[st] = 0;
	while (que.size()) {
		PII now = que.top();que.pop();
		int ut = now.second, wt = now.first;
		for (int i = thead[ut]; i != -1; i = tex[i]) {
			int vt = te[i];
			if (tdist[vt] > tw[i] + wt) {
				tdist[vt] = tw[i] + wt;
				que.push(PII(tdist[vt], vt)); 
			}
		}
	} 
//	for (int i = 1; i <= n; i++) cout << tdist[i] << ' ';
//	cout << endl;
} 
int main() {
	memset(head, -1, sizeof head);
	memset(_head, -1, sizeof _head);
	memset(dist, 0x3f, sizeof dist);
	memset(_dist, 0x3f, sizeof _dist);
	scanf("%d%d%d", &n, &m, &x);
	int ut, vt, wt;
	// �����+����ͼ 
	for (int i = 1; i <= m; i++) scanf("%d%d%d", &ut, &vt, &wt), add(ut, vt, wt), _add(vt, ut, wt);
	// ���յ���һ�����·�����ɵõ�����ţ��ȥ�����· 
	dijkstra(x, dist, head, e, w, ex);
	// ��������㽨һ������Դ�㣬Ȼ������Դ�������·����õ������е㵽x�����·...���ַ����ϴ�һ���Ĵ���
	// ֻ�����е㵽x�Ĺ������·�������⣬Ӧ���������е㵽x�����·..����ʵʵ����ͼ... 
	dijkstra(x, _dist, _head, _e, _w, _ex);
	int res = 0;
	for (int i = 1; i <= n; i++) res = max(res, dist[i] + _dist[i]);
	cout << res;
	return 0;
}
