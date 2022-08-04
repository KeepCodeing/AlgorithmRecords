#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

// 感觉写了两个小时的原因是自己思路根本不清晰，一开始还是个错的w... 

// 因为这个图边权全为1，故而容易想到BFS，而BFS存在“层次”性质，于是手玩发现可以把整个图看成一个树，然后找出一个点作为根节点使得整棵树的深度
// 最小，那么这个点就是答案点，最小边权和就是当前层次*这一层有多少个点。
// 其想法是暴力BFS，直接对每个点进行一次BFS，然后统计出最小深度的那个点是哪个...但是这样超时可能性巨存，由此其又手玩了下，发现当图是一条链
// 的时候，深度越中间的点作为根节点越能使得树的深度更小（或许是直接小一半左右），由此应该能一次BFS统计出所有点的层次，然后每一层有多少个点..
// 暂且没有办法验证正确性，但是先写写好了（因为不写和没想一样的w）.. 

// 写了大概两个小时罢w，现在停电了...思路就是BFS，然后暴力枚举每一层作为根节点（或者说作为中间点）到1 ~ i - 1与i + 1到dep的距离（i是当前层的编号，
// dep是最大深度），而距离和就是这一层有多少个点*深度...不过要特判当前层次有其它点的情况，手玩可以发现同层次的点经过翻转后不管是在上面还是下面，它
// 都是距离当前点最远的点，也就是它的距离和是同层次点翻到上面i - 1层还是翻到下面dep - i层时乘积最小... 

// 不过其一开始的思路是个错的，那时候想的是只要找到中间层次的点，就一定能保证从这个层次的某个点出发整个距离和最小。然而这应该是特殊情况，当这个点
// 被作为根结点（也就是画在最上面）时，它可能导致这棵树的层次增加，就类似1->2, 1->3, 1->4这种情况，如果将2作为根节点，会发现树变成了2->1, 1->3, 1->4
// 然后其发现既然枚举中间点不可行，干脆把所有点都枚举... 

// 上面说的都是错的，当然这次说的也不一定正确w，思路就是既然自己记录层次，然后根据层次直接算上下的距离不行，那么就按照一开始的想法，把这个点当成根，
// 注意，这里说的这个点是指某一层中最小编号的那个点。这样乍一看还是个暴力，但实际上应该能将效率提升很多。如果给的树不是一个链的话，或许能行.. 

// 自己乱搞的BFS得了30，题解是找树的重心或者树上Dp... 

const int N = 50000 + 10, M = N * 2, INF = 0x3fffffff;
typedef pair<int, int > PII;
int head[N], e[M], ex[M], idx = 0;
bool vis[N];
vector<int > graph[N];
void add(int ut, int vt) {
	e[idx] = vt, ex[idx] = head[ut], head[ut] = idx++;
}
PII que[N];
int mxdep = 0;
int bfs(int st) {
	memset(vis, 0, sizeof vis);
	int res = 0, qtop = 0, qback = 0;
	que[qtop] = PII(st, 0);
	while (qtop <= qback) {
		PII now = que[qtop++];
		int ut = now.first, dep = now.second;
		// 注意这是个无向无环图，所以任意两个节点都能互相到达，故而要标记访问否防止重复访问 
		if (vis[ut]) continue;
		vis[ut] = true;
		mxdep = dep, res += dep;
		graph[dep].push_back(ut);
		for (int i = head[ut]; i != -1; i = ex[i]) que[++qback] = PII(e[i], dep + 1); 
	} 
	return res;
}
int main() {
	memset(head, -1, sizeof head);
	int n, ut, vt, tmpoi, tres, res, mpoi = INF;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) scanf("%d%d", &ut, &vt), add(ut, vt), add(vt, ut);
	// 先算出1号点的最小和，顺便算出层数 
	res = bfs(1);
	// 层数从0开始，去掉1号点从1开始... 
	for (int i = 1; i <= mxdep; i++) {
		tmpoi = INF, tres = 0;
		for (int j = 0; j < graph[i].size(); j++) tmpoi = min(tmpoi, graph[i][j]);
		tres = bfs(tmpoi);
		if (tres < res) res = tres, mpoi = tmpoi;
	}
	printf("%d %d", mpoi, res);
//	for (int i = 1; i <= dep; i++) {
//		tmpoi = 0x3fffffff, tres = 0;
//		// 遍历出当前层次最小的那个点 
//		for (int j = 0; j < graph[i].size(); j++) tmpoi = min(tmpoi, graph[i][j]);
//		// 同层次的点放到当前点的上面，那么的距离就和是去掉当前点当前层次有多少个点，然后所有和除了当前点的当前层次点连接的点都会再往上
//		// 移动一层，也就是距离k = 2，所以下面那个循环做了判断（发现这样是有问题的）
//		
//		// 其实这个题做到现在大概已经知道怎么做了，先BFS一遍，这样就求出了每个层次有多少个点，然后暴力对每一层进行枚举，求出这一层的最小
//		// 点到1 ~ 这一层 - 1的所有点的距离，然后求出这一层 + 1 ~ 最大深度的所有点的距离...但是有个特判的点，那就是同层次的点怎么处理，
//		// 可以发现，同层次的点不管是翻上去还是翻下去都是到当前点最远的点，而我们不可能再将同层次的点添加到graph里，所以就最好的办法就是
//		// 直接算出当前点到上面的距离最短还是到下面的距离最短，那么上面会有i - 1层， 下面会有dep - i层，直接算出来就行（发现又错了w） 
//		
//		// 最后方案w，发现同层次的点翻转不是变成了最底层的点，而是变成了要通过根节点才能访问到的点，那么当前点到同层次的点的距离就一定是
//		// 2，如果不考虑（可能有问题w），之前手玩考虑如果同层次的点下面还有点怎么办，然后不断手玩发现这种情况似乎不是其能处理的，但
//		// 其也发现如果某个点它的
//		// 这一层有多个元素，那么新构成的树的高度就一定会变大，也就是结果也会变大，那么似乎可以剪掉...（似乎这样也有问题，反而是前面说的
//		// 直接*2能得出正解，那么还是等来电直接交了看看题解算了... 
////		if (graph[i].size() != 1) continue; 
//		int gLen = graph[i].size() - 1; 
////		tres += gLen * 2;
//		// cout << i - 1 << ' ' << dep - i << endl;
//		// 算出当前点上面，下面距离和为多少 
//		for (int j = i + 1, k = 1; j <= dep; j++, k++) {
//			tres += graph[j].size() * k;
//			if (i == 2) cout << graph[j].size() << endl;
//		}
//		if (i == 2) cout << tres << endl;
//		for (int j = i - 1, k = 1; j >= 1; j--, k++) tres += graph[j].size() *  k;
//		
//		// 如果和更小，直接将结果更新，注意这里为什么可以直接更新点，因为首先我们得使和最小，其次tmpoi就是这一层编号最小的那个点 
//		if (tres < res) res = tres, mpoi = tmpoi;
//		// cout << mpoi << ' ' << res << endl;
//	} 
//	for (int i = 1; i <= dep; i++) {
//		for (int j = 0; j < graph[i].size(); j++) cout << graph[i][j] << ' ';
//		cout << endl;
//	}
//	printf("%d %d", mpoi, res);
	return 0;
}
/*
7
1 2
2 4
4 6
3 1
5 2
3 7 
*/
