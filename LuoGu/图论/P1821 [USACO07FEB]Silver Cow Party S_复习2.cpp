#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

// 又来fuxi最短路了，这个题比较有意思，整合了一个普通最短路和全源最短路，有必要多做几遍 

// 又是温故而知新w，这次的解是其所有解中最优的，首先是代码量，因为少了一个Dijkstra所以这个题的码量基本和模板题差不多
// 然后就是内存了，之前建图比较无脑，不管有向无向边都开的非常大，这次因为给了边数所有没有开很大，值得一提的是大部分题目
// 不一定给边数，给了的话无向图就是数据范围，有向图要乘2。另外类似Trie之类的题，数组都要开的足够大才行，没给边数的题也一样。
// 最后是运行时间，这次只跑了40m，快乐60m左右... 

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
// 这次用方便点的办法做，既然反向建图只是距离数组不同，那也没必要再写一个Dijkstra了，直接传参数组就行了... 
// 其实图也不同了，所以还要把图当成参数传进去
// 注意这样搞的初始化问题，传进去的就是一个指针，因为sizeof得到的是这个指针的数据类型的占字节数，也就是数组
// 中一个元素的占字节数，要填充整个数组就要乘上这个数组的元素个数 
// 上面说的那个方法坠毁了ww，还是得在外面直接初始化，然后作为参数传递，另外初始化的值居然被其搞成-1了... 
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
	// 单向边+反向建图 
	for (int i = 1; i <= m; i++) scanf("%d%d%d", &ut, &vt, &wt), add(ut, vt, wt), _add(vt, ut, wt);
	// 从终点跑一次最短路，即可得到所有牛回去的最短路 
	dijkstra(x, dist, head, e, w, ex);
	// 对所有起点建一个虚拟源点，然后从这个源点跑最短路，获得的是所有点到x的最短路...，又犯了上次一样的错误，
	// 只求到所有点到x的公共最短路不和题意，应该是求所有点到x的最短路..老老实实反向建图... 
	dijkstra(x, _dist, _head, _e, _w, _ex);
	int res = 0;
	for (int i = 1; i <= n; i++) res = max(res, dist[i] + _dist[i]);
	cout << res;
	return 0;
}
