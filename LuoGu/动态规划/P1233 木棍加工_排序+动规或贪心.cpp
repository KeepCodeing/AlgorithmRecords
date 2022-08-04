#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

// 这个题很类似紫书上的矩形嵌套那个题，感觉其可以贪心或者DP来做，先排个序什么的 

const int N = 5000 + 10;
struct Node {
	int l, w;
	bool operator<(const Node& n) const {
		if (l > n.l) return w > n.w;
	}
} s[N];
int main() {
	int n;
	scanf("%d", &n);
	// 输入，为了方便排序下标从0开始，太错乱了，输入写错了，最巩怖的是好像还没什么问题w 
	for (int i = 0; i < n; i++) scanf("%d%d", &s[i].l, &s[i].w);
	sort(s, s + n);
	for (int i = 0; i < n; i++) printf("%d %d\n", s[i].l, s[i].w);
	return 0;
}
