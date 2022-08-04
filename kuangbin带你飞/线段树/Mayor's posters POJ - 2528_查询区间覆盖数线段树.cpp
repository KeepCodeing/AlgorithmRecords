#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;

// 参考博客：https://blog.csdn.net/weixin_44077863/article/details/98037868 
// 在颓废的边缘挣扎...这个题是新的题型了，主要用到的是离散化的技巧。首先这个题肯定不能用普通线段树来做的，因为
// 普通线段树无法查询区间，只能查询区间属性。那么这里就引入离散化的概念了，如果我们将一段区间看成一个点，然后将
// 这个点的左右子树设置为其自己，那么最后得到的树就是一颗包括了若干个区间的树。最后判断下存在多少个区间即可得到
// 答案。那么考虑下如何将一段区间映射成点，如果将区间标记成像 x[1]=1 x[2]=4 x[3]=6 x[4]=10这样的形式的话，看起来
// 像是意味着[1,4], [6, 10]变成了两个点，但是这里并没有给出5，也就是这两段区间是断开的。而如果化成[1, 2], [3, 4]
// [5, 6]...就不会出现间断，也就是说我们干脆将左右区间差值大于1的点单独提取出来作为一个新的点，这样每段区间就都是
// 连续的了... 

const int N = 1e5 + 10;
int lf[N], rg[N];
int nums[N * 4];
int main() {
	int T, n, cnt, res, temp;
	scanf("%d", &T);
	while (T--) {
		cnt = res = 0;
		scanf("%d", &n);
		// 将左右区间存起来，然后进行离散化 
		for (int i = 1; i <= n; i++) scanf("%d%d", &lf[i], &rg[i]), nums[cnt++] = lf[i], nums[cnt++] = rg[i];
		sort(nums, nums + cnt);
		temp = cnt = unique(nums, nums + cnt) - nums;
		// 填补缺口 
		for (int i = 1; i < temp; i++) {
			if (nums[i] - nums[i - 1] > 1) nums[cnt++] = nums[i - 1] + 1;
		} 
		sort(nums, nums + cnt);
//		for (int i = 1; i <= n; i++)
	}
	return 0;
}
