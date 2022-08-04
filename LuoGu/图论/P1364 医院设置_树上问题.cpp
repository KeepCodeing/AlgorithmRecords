#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

// 发现数据范围很小，那么建树+暴力就完事了，不过要注意这个题和普通题的建图方式
// 不太一样，首先它是点权，其次它的建图过程不能直接用邻接表，因为点权的原因得用
// 结构体数组模拟...

// 那么从当前点跑个BFS，然后深度（步数）就是路径长度了.. 

// 一开始以为是树的重心，然后发现是点权作为答案.. 

typedef long long LL;
typedef pair<int, int > PII;
const int N = 100 + 10; 
bool vis[N];
struct Node {
	int l, r, w, fat;
} root[N];
// 用来测试树建的对不对的前序遍历 
void in_order(int now) {
	cout << root[now].w << endl;
	if (root[now].l) in_order(root[now].l);
	if (root[now].r) in_order(root[now].r);
}
LL bfs(int st) {
	memset(vis, 0, sizeof vis);
	queue<PII > que;
	que.push(PII(st, 0));
	LL res = 0;
	while (que.size()) {
		PII now = que.front(); que.pop();
		// 这里改成最短路的思路了，因为深度不知道怎么算w，所以干脆用个step变量存到这一步的距离 
		int ut = now.first, step = now.second;
		if (vis[ut]) continue;
		// 因为搞成双向边了所有会有重复访问的问题 
		vis[ut] = true;
		// 算答案 
		res += root[ut].w * step;
		if (root[ut].l) que.push(PII(root[ut].l, step + 1));
		if (root[ut].r) que.push(PII(root[ut].r, step + 1)); 
		// 注意把父节点（回去的路）也加进来 
		if (root[ut].fat) que.push(PII(root[ut].fat, step + 1));  
	} 
	return res;
}
int main() {
	int n, ut, vt, wt;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &wt, &ut, &vt);
		// 二叉树，用l，r记录子节点的位置，然后把点权存起来，总之就是
		// 用数组模拟建图... 
		root[i].l = ut;
		root[i].r = vt;
		// 注意建个双向边，不然没办法往回走（这里不用特判0，因为0在BFS里就不可能被入队）... 
		root[ut].fat = i;
		root[vt].fat = i;
		root[i].w = wt;
	}
	// 怕爆炸搞了个long long... 
	LL ans = 0x3fffffff;
	for (int i = 1; i <= n; i++) ans = min(ans, bfs(i));
	printf("%lld", ans);
	return 0;
}
