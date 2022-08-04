#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

// 题目里说可能有重边和自环，但是题解里的链表存图似乎没有考虑这个（邻接矩阵要考虑重边）。
// 那么这个题就是把字母映射成数字（因为范围小，所以直接把字母当成整形也没有问题），然后
// 建图跑从终点跑最短路就行了...（无向图，不用反向建边） 

// 太奇妙了...最好还是不要瞎搞输入，因为输入的类型是字符串，但是存储的元素是整形，出现了奇妙的错误
// 导致其RE爆零三次w（未定值出界）。值得一提的是这种情况在本地是可以过的，但是评测机就不一定了。由此
// 可见像这种复杂的输入还是用cin来搞，而且数据类型也要对应（已经吃了很多次输入的亏了却不长记性的屑w） 

typedef pair<int, int > PII;
const int N = 1e5 * 2 + 10, INF = 0x3fffffff;
int head[N], e[N], ex[N], w[N], idx = 0;
int dist[N];
bool visited[N];
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
void dijkstra() {
	priority_queue<PII, vector<PII >, greater<PII > > que;
	que.push(PII(0, 'Z'));
	fill(dist, dist + N, INF);
	dist['Z'] = 0;
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
	int res = INF;
	char c;
	for (int i = 'A'; i <= 'Y'; i++) 
		if (res > dist[i]) res = dist[i], c = i;
	printf("%c %d", c, res);
}
int main() {
	int n, wt;
	char ut, vt;
	scanf("%d", &n);
	getchar();
	fill(head, head + N, -1);
	for (int i = 0; i < n; i++) {
		// 这里瞎搞写成了scanf("%c %c %d", &ut, &vt, &wt);此时ut，vt，wt都是整形，在加了getchar()之后本机运行
		// 没有问题，评测就全RE（绝望） 
		cin >> ut >> vt >> wt;
		getchar();
		// printf("%d %d %d\n", ut, vt, wt);
		add(ut, vt, wt), add(vt, ut, wt);
	}
	//getchar();
	dijkstra();
	return 0;
}
