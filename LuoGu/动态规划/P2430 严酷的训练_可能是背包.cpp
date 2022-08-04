#include <iostream>
#include <cstdio>
using namespace std;

// 题目描述很奇妙w，看起来有点类似背包 
// 注意题目要求的是男主做题的花费时间，而不是老王做题花费的时间，又因为
// 老王做题的速度是男主的整数倍，而水平和所花时间成反比，故而可知(老王做题的水平/男主做题的水平)*老王做题的时间
// 即是男主做题的时间，而知识点花的时间可以用一个桶存起来，然后时间上限就是背包容积，故而这个题目就能转换为背包
// 问题了，其中背包容积是时间限制，花费是男主做题的时间，收益是每个题目的奖励点...，这里没明说知识点是不是小于N
// 的，但可以通过有N个题目，就有N个知识点的条件推断出来... 

typedef long long LL;
const int N  = 5000 + 10;
int knowledge[N]; 
// 做第i个题的时间 
int tm[N];
// 做第i个题的奖励 
int val[N];
LL f[N];
int main() {
	int a, b, m, n, limit, bei, kn, vl;
	// 输入男主做题的时间和老王做题的时间 
	scanf("%d%d", &a, &b);
	// 男主做题的时间是老王的bei数倍 
	bei = b / a;
	// 输入有多少题和这些题有多少个知识点 
	scanf("%d%d", &m, &n);
	// 输入每个知识点要花的时间 
	for (int i = 1; i <= n; i++) scanf("%d", &knowledge[i]);
	for (int i = 0; i < m; i++) {
		// 输入知识点和奖励 
		scanf("%d%d", &kn, &vl);
		// 男主做第i个题的时间是老王做这个题的bei倍 
		tm[i] = knowledge[kn] * bei;
		// 奖励是不变的 
		val[i] = vl;
	}
	// 输入时间上限，即背包容积 
	scanf("%d", &limit);
	// 应该是个01背包，没有说一个题可以重复做，而一个知识点的题可能有多个，不确定是不是分组背包 
	for (int i = 0; i < m; i++) {
		for (int j = limit; j >= tm[i]; j--) {
			// 减去做题花费的时间，加上做这个题能带来的收益 
			f[j] = max(f[j], f[j - tm[i]] + val[i]); 
		}
	}
	// 忘了最后转移到的答案是背包容积那个位置...总之得花点时间复习背包了w 
	cout << f[limit];
	return 0; 
}
