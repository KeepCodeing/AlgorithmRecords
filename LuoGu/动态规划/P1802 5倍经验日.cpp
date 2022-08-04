#include <iostream>
#define endl '\n'
using namespace std;
typedef long long LL;
const int N = 1000 + 10;
struct Node {
	int l, w, c;
} node[N];
LL f[N][N];

// 之前的写法是类似普通回溯的，把sum这个结果作为参数传进去了...这样做导致后面统计答案是没办法分清这个答案是
// 输的情况得到的还是赢的情况得到的，因为不论输赢我们使用的都是sum作为答案...然后要注意的是边界的判断，注意
// 这个题判断level >= deepth的位置，它是在所有判断之后的，经过测试发现如果放在最前面会导致答案少选了一个，要
// 改成deepth + 1才行（如果level从1开始就是+2），关于为什么还不明白...
// 然后要注意，这里求x - node[level].c的目的是为了知道f[x]的值，而不是x - node[level].c的值，这句话的意思是说
// 不管这里体力值x减去多少，它都是在当前这个x的基础上进行选择的，所以它返回的结果也自然是当前这个x的，而不是上
// 面说的那样...
// 总结：记忆化搜索和回溯的关系并不大，在回溯上我们的目的一般是“有若干个选择，可以从中选出任意个选择，然后
// 看组成的结果是否是我们想要的”，这里虽然也有“选和不选”的概念，但它是针对整个序列而言的，我们不选这个选择
// 就一定会有另一个选择代替，这导致记忆化的过程不是那么简单（也可能是自己无法理解w），而记忆化搜索就正好与其相反
// 虽然目的都是把所有可能试一遍，但是它的“选和不选”这个过程是针对单个选项而言的，我们可以从题目中看出来，不选
// 这个选项和选这个选项不会导致答案序列的不同...总之说了这么多只想告诉以前的自己，回溯写记忆化没有那么简单，还是
// 尽量把无法理解的循环拆开成容易理解的dfs函数...当然，这个题明天还会用回溯试试的，虽然时间不多了，但是也要加把劲呢... 

LL dfs(int level, int deepth, int x) {
	
	if (f[level][x]) return f[level][x];
	
	if (x < 0) return -99999999;
	
	if (level >= deepth) return 0;
	
	f[level][x] = max(
		dfs(level + 1, deepth, x - node[level].c) + node[level].w, 
		dfs(level + 1, deepth, x) + node[level].l
	); 
	return f[level][x];
}

// 干脆今天就把回溯版的写了...上厕所的时候想了下，感觉和普通记忆化写法的区别只在层次变化上不同，然后
// 就按照普通回溯写了个for循环什么的，结果是可以拿80分的，还是有两个点tle了，这实在奇妙... 
/*
LL dfs(int level, int deepth, int x) {
	
	if (f[level][x]) return f[level][x];
	
	if (x < 0) return -99999999;
	
	if (level >= deepth) return 0;
	
	for (int i = level; i < deepth; i++) {
			f[i][x] = max(
			dfs(i + 1, deepth, x - node[i].c) + node[i].w, 
			dfs(i + 1, deepth, x) + node[i].l
		);
	}
	return f[level][x];
}

*/

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, x;
	cin >> n >> x;
	for (int i = 0; i < n; i++) cin >> node[i].l >> node[i].w >> node[i].c;
	cout << dfs(0, n, x) * 5 << endl;
	return 0;
}
