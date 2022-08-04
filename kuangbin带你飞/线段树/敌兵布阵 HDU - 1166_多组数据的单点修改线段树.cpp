#include <iostream>
#include <cstdio>
using namespace std;

// 普通单点线段树，不过有多组数据，单点线段树也能用区间线段树来，故此这里就用区间线段树来写好了... 
// 估计用树状数组做会简单很多，不过其基本忘了w 

// 加了AC的题的板子，还是WA了，可以肯定板子没问题...自闭睡觉了，一天肝了三道线段树，调试太自闭了... 

typedef long long LL;
const int N = 1e5 + 10, M = N * 4;
// int nums[N];
struct Node {
	// 不用开long long， 40000 * 30 = 1200000
	int l, r;
	LL lz, sum;
} root[M]; 
char op[10];
// 规定写完build就写pushup/down 
void pushup(int now) {
	root[now].sum = root[now << 1].sum + root[now << 1 | 1].sum;
}
void pushdown(int now) {
	if (root[now].lz) {
		int ln = now << 1, rn = now << 1 | 1;
		// 做完刚刚的题才知道自己多脑瘫...这里硬是转成int再加，WA了十次甚至九次也发现不了为什么，真是活该呢... 
		LL lz = root[now].lz;
		root[ln].lz += lz, root[rn].lz += lz;
		root[ln].sum += (root[ln].r - root[ln].l + 1) * lz;
		root[rn].sum += (root[rn].r - root[rn].l + 1) * lz;
		root[now].lz = 0;
	} 
}
void build(int now, int left, int right) {
	// 运行的时候忘了初始化区间和叶节点情况... 
	root[now].l = left, root[now].r = right;
	if (left == right) {
		// 忘了加&... 
		scanf("%lld", &root[now].sum);
		// root[now].sum = nums[left];
		root[now].lz = 0; 
		return;
	}
	int mid = (left + right) >> 1;
	int ln = now << 1, rn = now << 1 | 1;
	build(ln, left, mid);
	build(rn, mid + 1, right);
	pushup(now);
}
void update(int now, int L, int R, int val) {
	// 忘了写走到了区间怎么办.. 
	if (L <= root[now].l && root[now].r <= R) {
		root[now].lz += val;
		root[now].sum += (root[now].r - root[now].l + 1) * val;
		return;
	}
	int mid = (root[now].l + root[now].r) >> 1;
	int ln = now << 1, rn = now << 1 | 1;
	pushdown(now);
	if (L <= mid) update(ln, L, R, val);
	if (mid < R) update(rn, L, R, val);
	pushup(now);
}
LL query(int now, int L, int R) {
	if (L <= root[now].l && root[now].r <= R) return root[now].sum;
	if (L > root[now].r || R < root[now].l) return 0;
	// 不要忘记pushdown 
	pushdown(now);
	// 精简化后的query，可以省去ln和rn，前面也是一样，不过那更类似习惯，所以干脆保留好了... 
	// 然而<<写成了>>... 
	return query(now << 1, L, R) + query(now << 1 | 1, L, R);
}
// 很无解w，板子是对的...但是就是WA... 
// YATTZE!做到后面的题才发现要初始化... 
void _init() {
	for (int i = 0; i < M; i++) root[i].l = root[i].r = root[i].lz = root[i].sum = 0;
}
int main() {
	int T, n, x, y;
	scanf("%d", &T);
	// 毒瘤输出 
	for (int t = 1; t <= T; t++) {
		_init();
		scanf("%d", &n);
		// for (int i = 1; i <= n; i++) scanf("%d", &nums[i]);
		// 多次建树，建树一般是O(n)的复杂度，顺带在建树里输入叶子节点的值，可以省很多空间 
		build(1, 1, n);
		printf("Case %d:\n", t);
		while (true) {
			scanf("%s", &op);
			// 虽然输入的字符串，不过很明显C字符串不能方便的进行对比，而每个字符串开头都不一样，故判断开头就行.. 
			if (*op == 'E') break;
			// printf("%c\n", op[0]);
			// printf("%s\n", op);
			// 修改操作，减值就是加负数... 
			// 注意End没有x，y，所以不能无脑把x，y写前面... 
			scanf("%d%d", &x, &y);
			if (*op == 'A' || *op == 'S') {
				// 极度脑瘫的错误，这里写成了op[0] = 'S'，导致加上的值似乎都变成负数了，还查了半天找不出来错误... 
				if (*op == 'S') y = - y;
				update(1, x, x, y);
			} else {
				printf("%lld\n", query(1, x, y));
			}
		}
	}
	return 0;
}
