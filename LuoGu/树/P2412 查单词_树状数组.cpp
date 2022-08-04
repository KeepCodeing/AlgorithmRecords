#include <iostream>
#include <cstdio>
using namespace std;

// ~~线段树第八弹~~树状数组第二弹，典型的求区间最大值，似乎没有修改操作，如果有单点修改，用树状数组较好，
// 如果有区间修改用线段树比较好，这个题没有修改操作，为了简单那还是用树状数组算了..（好像树状数组也能做
// 区间修改和查询，不过要用到差分） 
// 坠毁ww，写着写着发现树状数组查到的是字符串，不满足区间加减法... 

const int N = 500000 + 100;
string words[N];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%s", &words[i]);
	while (m--) {
		
	}
	return 0;
}
