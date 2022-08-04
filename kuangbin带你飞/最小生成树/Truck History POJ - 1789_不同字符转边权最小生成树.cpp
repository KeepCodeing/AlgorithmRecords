#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <vector>
using namespace std;

// 今天其实刷了不少题，这个题是最小生成树的第6题了，事实证明最小生成树比最短路简单很多...估计明天其就要开始正式复习了，
// 不然考试坠毁太划不来了w，那么这可能是近期？（估计明天还会做个一两题玩玩）做的最后一道题了...虽然刷题很枯燥，但是AC
// 的喜悦却是难以代替的呢... 

// 那么这个题不看专题大概很难想到最小生成树吧，事实上本five也没有做过字符串的最小生成树...看了题目每个字符串只有7位，那么
// 应该可以暴力枚举每个字符串对比不同，然后加边，再跑最小生成树...一开始以为每个字符串最长有2k位，直接觉得不可做ww，那么
// 枚举部分的暴力算法应该在O(7*N^2)左右，然后加个排序之类的..不过其也确实想不到好的对比方法了...可能双指针可以，不过如果
// 暴力都过了那就没必要写了ww 

// 这个题卡了Kruskal，至少本five的做法是会RE的，空间开的太小了，开大了的话本地都运行不了...，偷了别人的代码交了，失败w.. 
 
const int N = 2000 + 10, M = 1e6 * 5 + 10;
char str[N][10];
struct G {
	int u, v, w;
	G () {};
	G (int u, int v, int w) : u(u), v(v), w(w) {};
	bool operator<(const G& g) const {
		return w < g.w;
	}
} graph[M]; // 无脑开了大空间w，RE的话划不来呢... 
// vector<G > graph;
struct unionFind {
	int bin[N];
	unionFind () {
		for (int i = 0; i < M; i++) bin[i] = i;
	}
	int anc(int x) {
		if (x != bin[x]) bin[x] = anc(bin[x]);
		return bin[x];
	}
	void uni(int x, int y) {
		if (ask(x, y)) return;
		bin[anc(x)] = y;
	}
	bool ask(int x, int y){
		return anc(x) == anc(y);
	}
};
int main() {
	int n, diff, cnt;
	while (true) {
		scanf("%d", &n);
		if (!n) break;
		cnt = 0;
		for (int i = 1; i <= n; i++) scanf("%s", &str[i]);
		// 喜闻乐见的下标坑，被坑惨了w，另外这里为什么j从i+1开始是因为这个图是无向图，j从1开始就会重复算边... 
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				// 注意diff更新的位置，应该是两个字符串的不同一对比完就重置，而不是之前的一个样例重置一次... 
				diff = 0;
				// 计算两个字符串有多少个字符不同，不同的个数即为边权... 
				for (int c = 0; c < 7; c++) if (str[i][c] != str[j][c]) diff++;
				// 字符串i到字符串j的边权即为他们的不同字符的个数.. 
				graph[cnt++] = G(i, j, diff);
				// graph.push_back(G(i, j, diff));
			}
		}
		// 加完边跑最小生成树
		sort(graph, graph + cnt);
		// sort(graph.begin(), graph.end());
		unionFind uf;
		int res = 0;
		for (int i = 0; i < cnt; i++) {
			if (!uf.ask(graph[i].u, graph[i].v)) {
				uf.uni(graph[i].u, graph[i].v);
				res += graph[i].w; 
			}
		}
		// 蜜汁输出，一开始还没注意.. 
		printf("The highest possible quality is 1/%d.\n", res);
	}
	return 0;
}
