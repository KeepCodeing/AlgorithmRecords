#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

// 可持久化线段树可以用来查询区间第k小，注意它和权值线段树的区别，权值线段树只能查询整个
// 序列的第k小...
// 其实主席树也是在普通线段树的基础上进行改进的，首先可以想下怎么实现可持久化这个功能，
// 也就是记录“历史版本”，这个功能可以通过对每个点都开一个线段树解决，每次更新就重新
// 建立整个线段树..然而这样时间和空间上都是无法接受的，因此需要对这个过程进行优化..首先
// 考虑下懒标记的思想，它就是把“不需要更新的点”通过回溯的过程更新..同理，我们修改一个
// 点也不需要也不需要对整棵树进行修改，我们可以利用一个类似指针的操作，将被修改的点指向
// 另一个版本，这样一来，只需要对被修改的点记录历史版本，这样的话时间和空间就都能接受了..

// 它在实现上是和普通线段树类似的，只不过它记录的不是最值，和之类的东西，而是记录的每个
// 区间有多少个树，因此它的叶子节点必定全为1，然后以此类推，根节点就是整个区间包含的数的
// 数量..而记录区间节点数的作用就是为了确定这个区间内有多少个范围内的点，可以发现，查询
// 操作首先做的就是用左子树的节点数量减去右节点的节点数量，然后就能得到当前区间里有多少个
// 数了，依次类推，最后就能找到第k个数..另外因为只用查询区间的第k个数，故而可以对原来的序列
// 想进行一次离散化，用来节约空间...还有就是主席树一般开40倍空间w.. 
// 看了下代码似乎除了update第一行和普通线段树不一样其它似乎都是一样的w... 

const int N = 2 * 1e5 + 10;
vector<int > vec;
int nums[N];
int root[N];
// 用来标记节点 
int cnt = 0;
// 节点信息数组，注意节点信息数组要开四十倍空间.. 
struct Node {
	int l, r, sum;
} T[N * 40];
// 用来获取离散化后的数字编号 
int getid(int num) {
	return lower_bound(vec.begin(), vec.end(), num) - vec.begin() + 1; 
} 
// 用来建树，这里的left，right的意思是区间范围，x和y的意思是更新的子树的范围，注意
// x要加上&，不然递归里它不会改变值，pos就是离散化后的数字下标了.. 
void update(int left, int right, int &x, int y, int pos) {
	// 
	T[++cnt] = T[y], T[cnt].sum++, x = cnt;
	if (left == right) return;
	int mid = (left + right) >> 1;
	// 向左走，这里和普通线段树不一样，  
	if (pos <= mid) update(left, mid, T[x].l, T[y].l, pos);
	else update(mid + 1, right, T[x].r, T[y].r, pos);
}
int query(int left, int right, int x, int y, int k) {
	if (left == right) return left;
	int mid = (left + right) >> 1;
	int sum = T[T[y].l].sum - T[T[x].l].sum;
	// 如果当前数处于左边，就往左走，否则就往右走，这部分和查询一样.. 
	if (k <= sum) return query(left, mid, T[x].l, T[y].l, k);
	// 注意如果是右区间查询第k小应该用k-sum，因为此时k>sum，就说明这个数位置还没找到 
	else return query(mid + 1, right, T[x].r, T[y].r, k - sum);
}
int main() {
	int n, m, num, x, y, k;
	scanf("%d%d", &n, &m);
	// 注意因为区间从1开始，而且这里要离散化所以不能建树时输入，故而排序之类的
	// 时候也要改变下标（改成vector好了w..） 
	for (int i = 1; i <= n; i++) scanf("%d", &nums[i]), vec.push_back(nums[i]);
	// 离散化..注意这里还要用到原数组来更新编号 
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end()); 
	// 建树 
	for (int i = 1; i <= n; i++) update(1, n, root[i], root[i - 1], getid(nums[i]));
	while (m--) {
		scanf("%d%d%d", &x, &y, &k);
		printf("%d\n", vec[query(1, n, root[x - 1], root[y], k) - 1]);
	}
	return 0;
}

