#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

// 一些规定：首先规定公共祖先是什么，公共祖先就是当前点的所有父节点，并且包括当前节点，那么两个点的最近公共祖先就是
// 它们向上走第一个相同的父节点。 

// Tarjan算法是对“线性找根”算法的改进，首先提下前者，这个算法思路很简单，每次要找两个点的功能祖先，那就从这个点
// 开始往上查找，两个点的第一个共同父节点就是它们的LCA，这个算法复杂度为O(n)，m个询问就是O(mn)，较为低效。另外再说
// 下倍增算法，思路比较玄学（还是二进制什么的），可以在线，预处理倍增数组O(nlogn)，m次询问O(mlogn)。回到Tarjan，该
// 算法可以在O(n+m)的复杂度内解决LCA问题，缺点是代码麻烦而且只能离线。它将一棵树分为了三种点，第一种点：遍历过且回溯
// 过的点，第二种点：正着遍历还没有回溯的点，第三种点：没有开始遍历的点。因为花不了图，所以直接给结论算了：当前正在
// 遍历的点的公共祖先就是回溯过后的那个点...然后要注意一开始的距离也是要算出来，这里设置的是每个点到父节点的距离，
// 然后任意两点的距离其实就是他们到公共祖先的距离减去2倍的重复距离（到祖先的距离）... 

typedef pair<int, int > PII;
const int N = 500000 + 10, M = N * 2;
int sat[N];
int head[N], e[M], ex[M], idx = 0;
int res[N];
int bin[N];
struct unionFind {
	unionFind () {
		for (int i = 0; i < N; i++) bin[i] = i;
	}
	int anc(int x) {
		if (x != bin[x]) bin[x] = anc(bin[x]);
		return bin[x];
	}
	void uni(int x, int y) {
		int xt = anc(x), yt = anc(y);
		if (xt != yt) bin[xt] = y;
	}
};
unionFind uf;
vector<PII > ques[N];
void add(int ut, int vt) {
	e[idx] = vt, ex[idx] = head[ut], head[ut] = idx++;
}
void tarjan(int ut) {
	sat[ut] = 1;
	for (int i = head[ut]; i != -1; i = ex[i]) {
		int vt = e[i];
		// 注意只对第三类点，也就是没有遍历过的点进行连边 
		if (sat[vt]) continue;
		tarjan(vt);
		// 如果当前点没有遍历过，那么它的公共祖先就是回溯中那条路径上的点 
		bin[vt] = ut;
	}
	// 执行所有对ut的询问，用来查找ut的LCA 
	for (int i = 0; i < ques[ut].size(); i++) {
		int y = ques[ut][i].first, id = ques[ut][i].second;
		// ut的LCA就是经过tarjan之后并查集中和询问点y的祖先 
		res[id] = uf.anc(y); 
	}
	sat[ut] = 2;
}
int main() {
	// 忘了初始化头结点 
	memset(head, -1, sizeof head);
	int n, m, s, ut, vt, a, b;
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 0; i < n - 1; i ++) {
		scanf("%d%d", &ut, &vt);
		add(ut, vt), add(vt, ut);
	}
	// 将所有询问存起来离线处理 
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		ques[a].push_back(PII(b, i));
		ques[b].push_back(PII(a, i));   
	}
	// 不知道为什么所有测试点跑完加起来花了快4sww... 
	tarjan(s);
	for (int i = 0; i < m; i++) printf("%d\n", res[i]);
	return 0;
}
