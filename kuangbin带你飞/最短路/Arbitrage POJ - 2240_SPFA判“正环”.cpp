#include <iostream>
#include <map>
#include <queue>
#include <cstring>
using namespace std;

// 这个题似乎和上一个判正环的题有些区别， 上一个题指定了起点和起点的权值，这个题没有指定起点，那也就是说可以用
// 所有类型的货币进行兑换，只要有一个能套利就行...看了下题似乎指定了每个点的初始边权都为1，那么假设只有当前点
// 的“距离”为1，其它点的“距离”为0，就可以考虑松弛条件了，可以指定松弛条件为当“距离”增加才进行松弛，看起来
// 似乎和上一个题类似。
// 这里其一开始疑惑的松弛条件是“如果每个点的初始值都比当前点的1乘上汇率还大，那松弛不就无法进行了”，不过这里明显 
// 没考虑其他点的初始值设定，题目说1美元买0.5英镑，意思就是一开始手上只有1美元，要进行“松弛”才能拿到0.5英镑... 
// 然后考虑下怎么把字符串转为点，题目给的比较良心，先直接给了所有顶点字符串，那么用一个map映射下就行了... 

map<string, int > gp;
// 题目给的单向图，但是为了保险无脑开的很大了w 
const int N = 3000 + 10, M = N * 2;
int head[N], e[M], ex[M], idx = 0;
bool visited[N];
double dist[N];
double w[M];
void add(int ut, int vt, double wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
bool spfa(int st) {
	// 多个数据，因此要多次初始化，不然就第一个数据点是正常的 
	memset(dist, 0, sizeof dist);
	memset(visited, 0, sizeof visited);
	// 手上一开始有1单位st类型的钱 
	dist[st] = 1.0;
	queue<int > que;
	que.push(st);
	while (que.size()) {
		int ut = que.front();que.pop();
		visited[ut] = false;
		// 如果通过回路回到了当前点并且手上的钱能变多就说明答案存在 
		if (ut == st && dist[st] > 1.0) return true;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			// 这里一开始写的时候有些疑惑，想着“买”到底是个什么意思，是指起点的钱变少还是说当前边的值直接就是
			// 起点第一次经过的值（这里的意思是当前点一开始为0，没有值，那这个值由什么确定），然后想了下既然起点
			// 值是1，那它的所有邻接边的值其实就是1*自己的值...那么就套用那个换算公式就行了...其甚至打算写些判断
			// 什么的，不过感觉这样绝对会坠毁呢w，因为起点又不是只会经过一次w... 
			double wt = dist[ut] * w[i];
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
	int n, m;
	string ut, vt;
	double wt;
	for (int T = 1;; T++) {
		cin >> n;
		if (!n) break;
		// 喜闻乐见的初始化
		memset(head, -1, sizeof head);
		idx = 0; 
		// 将点映射成整形 
		for (int i = 1; i <= n; i++) cin >> ut, gp[ut] = i;
		cin >> m;
		// 建图
		while (m--) {
			cin >> ut >> wt >> vt;
			// 单向边... 
			add(gp[ut], gp[vt], wt);
		} 
		bool flag = false;
		for (int i = 1; i <= n; i++) {
			// 如果有任意一种货币可以套利，就说明可以套利 
			if (spfa(i)) {
				cout << "Case " << T << ": Yes";
				flag = true;
				break;
			}
		}
		// 所有货币均不能套利 
		if (!flag) cout << "Case " << T << ": No";
		cout << endl;
	}
	return 0;
}
