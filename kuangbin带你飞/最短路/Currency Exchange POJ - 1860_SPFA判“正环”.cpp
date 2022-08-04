#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

// 这个题学了SPFA才知道是干嘛的，之前完全看不懂w...那么这个题要求的就是有没有一条路径从1出发又能回到1且使得1到1的
// “最短路”比一开始1到1的最短路更长....看起来很绕，但是总结就是找一个能使1点权值更大的环路。如果我们用Dijkstra的
// 思路来的话，可以很明显的发现Dijkstra的最短路不可能形成回路，而要想形成回路，也就意味着一个点可以多次经过，所以
// 这个题用SPFA可以做，那么怎么做呢？首先考虑如何使权值更大，我们思考SPFA跑一般最短路的松弛条件，其实和Dijkstra一样
// 就是当边的长度可以通过连接的点来缩短，那么就进行松弛。这里同样可以利用类似的思路，当当前边的边权更大的时候，我们
// 才进行“松弛”。那么再想下怎么判断是否有环路以及能否保证1的权值变大，这个其实也很简单，我们只需要判断下当前队头 
// 的点是不是1点就行了，如果是1点，就说明存在一条路径可以使得从1出发再回到1，在题目中的描述就是利用汇率不断交换货币
// 然后使得最后获得的货币值更大，那么回路也有了，就只用判断下1点的值是不是比一开始的值大就行了...
// 上面说了很多，在代码其实就是建图多加了几个类似边权的东西，以及“松弛”的条件变成了能使边权更大还有判断下当前队头点
// 是不是起点... 

// 这个题犯了想都没想过的错误：建图错误w，好了由此染费的时候比写程序还长，总之该搞作业了，线代、英语、数字逻辑报告...
// 最近也要考试了，不解决的话事情会越堆越多呢... 

const int N = 100 + 10, M = N * 2;
int head[N], e[M], ex[M], idx = 0;
// 汇率与佣金属性，不会英语的末路w 
double hl[M], yj[M];
double dist[N];
bool visited[N];
void add(int ut, int vt, double hlt, double yjt) {
	// 这里建图居然写错了，这里就写了个head[ut] = idx，然后图大概就是很多个自环，结果就一直死循环... 
	e[idx] = vt, hl[idx] = hlt, yj[idx] = yjt, ex[idx] = head[ut], head[ut] = idx++;
}
int n, m, st;
double sval;
bool spfa() {
	// 距离数组得循环初始化，因为他是double类型，这里应该不用初始化，因为其它地方的钱还没换到，即为0... 
	// for (int i = 0; i < N; i++) dist[i] = 1e9, visited[i] = false;
	// for (int i = 0; i < N; i++) dist[i] = .0;
	// 起点一开始有sval元 
	memset(visited, 0, sizeof visited);
	dist[st] = sval;
	queue<int > que;
	que.push(st);
	while (que.size()) {
		int ut = que.front();que.pop();
		visited[ut] = false;
		// 如果能换回手上的钱的类型，判断下是不是比一开始赚了，这里类型就是节点编号... 
		if (ut == st && dist[st] > sval) return true;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			// 题目的计算公式：(手上的钱-佣金)*汇率，这里ut就是手上的钱的编号，vt就是要换的钱的编号，也可以说是类型... 
			double wt = (dist[ut] - yj[i]) * hl[i];
			// 修改后的松弛条件，可以使得边权增加.. 
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
	// 忘了初始化头结点... 
	memset(head, -1, sizeof head);
	// 点数，边数，起点，起点初始值，这里对货币的描述就是对顶点的描述货币类型其实就是顶点编号... 
	scanf("%d%d%d%lf", &n, &m, &st, &sval); 
	int ut, vt;
	double hl1, yj1, hl2, yj2;
	while (m--) {
		// 建边，这里应该是双向边，因为a可以到b，同理b也可以到a，那么这里就没有所谓边权了，只有汇率和佣金这两个属性 
		scanf("%d%d%lf%lf%lf%lf", &ut, &vt, &hl1, &yj1, &hl2, &yj2);
		 // 建图，注意到这里来回边权不一样，因此这是一个强连通图... 
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
	double rt, cm; //rt费率 cm佣金 
} e[M];
int n, m, u, v, s, h[N], len = 1;  
bool vis[N]; 
double d[N], urt, ucm, vrt, vcm, it; //it是初始的 
void add(int u, int v, double rt, double cm) {
	e[len].v = v;
	e[len].next = h[u];
	e[len].rt = rt;
	e[len].cm = cm;
	h[u] = len++;
}
int spfa() {
	d[s] = it; //初始化这个位置的钱  其他位置的钱为0 
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = false;
		if (u == s && d[u] > it) return 1; //代表起点的钱大于初始的钱  
		for (int j = h[u]; j; j = e[j].next) {
			int v = e[j].v;
			cout << v << endl;
			double w = (d[u] - e[j].cm) * e[j].rt;
			if (d[v] < w) { //代表这次交换比上一次赚 
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
