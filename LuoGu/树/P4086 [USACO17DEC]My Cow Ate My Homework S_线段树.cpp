#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

// 线段树第八弹，这个题用树状数组做坠毁了ww，总之就是维护区间最值，然后
// 前缀和维护区间和，这个题不用提供修改和懒标记，算是简单的单点线段树...，写完了感觉和区间线段树在代码上就是修改哪里
// 有些变化，区间线段树修改需要调用pushdown，而且也要判断下是否走到了修改区间... 

// 写完了感觉犯了很hape的错误，而且WA了五次，主要有精度（temp赋值那里），数据类型（maxScore），出现答案却先清空了
// 答案（temp == maxScore那里）... 

typedef long long LL;
const int N = 100000 + 100, M = N * 4;
int arr[N], root[M];
LL s[N];
vector<int > res;
void build(int now, int left, int right) {
	if (left == right) {
		root[now] = arr[left];
		return;
	}
	int mid = (left + right) >> 1;
	int l_node = now << 1, r_node = now << 1 | 1;
	build(l_node, left, mid);
	build(r_node, mid + 1, right);
	root[now] = min(root[l_node], root[r_node]);
}
int query(int now, int left, int right, int L, int R) {
	if (L <= left && right <= R) return root[now];
	if(L > right || R < left) return 1e9;
	int mid = (left + right) >> 1;
	int l_node = now << 1, r_node = now << 1 | 1;
	return min(query(l_node, left, mid, L, R), query(r_node, mid + 1, right, L, R));
}
int main() {
	int n;
	scanf("%d", &n);
	s[0] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		s[i] = s[i - 1] + arr[i];
	}
	build(1, 1, n);
	// 池沼错误，这里maxScore写成了int，然后下面的temp赋值居然是直接两个整形相除.. 
	double temp, maxScore = -1e9;
	for (int i = 1; i <= n - 2; i++) {
		// 注意这里的强转，这两个式子都是整形，相除也是整形，因此要强转其中任意一个式子.. 
		temp = (s[n] - s[i] - query(1, 1, n, i + 1, n) + .0) / (n - i - 1);
		// 这里hape的写成了当新答案出现时清空res，于是就导致答案永远只有一个（然而只有一个点答案有多个ww） 
		if (temp > maxScore) maxScore = temp, res.clear();
		if (temp == maxScore) res.push_back(i);
	}
	int rLen = res.size();
	for (int i = 0; i < rLen; i++) printf("%d\n", res[i]);
	return 0;
}
