#include <iostream>
#include <cstdio>
using namespace std;

// 一开始没什么思路的样子，因为这个题分了所谓的团体，想了下可以设置每个团体的祖宗为其第一个人（之前想的是对团体
// 进行排序，然后用最小的编号的人做为祖宗，这样就能保证0一定是某个团体的祖宗，但是测试数据太多TLE不可避），那么
// 想下对于0这个点如果它处于一颗树里会有几种情况。首先是一种情况，其作为整棵树的祖先，另外一种情况就是其是树里的
// 一个节点。对于这个题目而言， 它要求的其实就是0这个点所在的树上面有多少个节点。而在并查集里统计树里的节点树只用
// 判断每个节点的祖先是谁就行了。于是上面两种情况其实都可以算一种情况，那就是统计有多少个节点的祖先和0的祖先相同，
// 此即为需要隔离的人的数量... 

// 好不容易AC了，虽然想法和做法都是对的，不过还是出现了意料之外的错误...记得判断连通块就是判断bin[i] == i，即i是不是
// 祖先就行了...但是可能POJ比较奇妙，要用anc(i)来，其打印出的数据也证明了上面那个说法没问题... 

const int N = 3e4 + 10;
int bin[N];
struct unionFind {
	void _init() {
		for (int i = 0; i < N; i++) bin[i] = i;
	}
	int anc(int x) {
		if (x != bin[x]) bin[x] = anc(bin[x]);
		return bin[x];
	}
	void uni(int x, int y) {
		if (ask(x, y)) return;
		bin[anc(x)] = y;
	}
	bool ask(int x, int y) {
		return anc(x) == anc(y);
	}
	int getcnt(int x, int n) {
//		for (int i = 1; i <= n; i++) {
//			cout << bin[i] << ' ' << anc(i) << ' ' << i << endl;
//		} 
		int cnt = 0;
		// 这里很迷，这里写成bin[i] == x错了，本来其想的是如果做了路径压缩按理来说bin[i]就应该等于anc(i)了，事实上
		// 用例也确实如此，而且啊哈算法里给的统计连通块数量也是bin[i]==i，种种迹象都表明bin[i] == anc(i)，即bin[i]
		// 就是i的祖宗节点的编号...这太坑了w，不过可以统一下，如果求连通块就这样写好了... 
		for (int i = 1; i <= n; i++) cnt += anc(i) == x;
		return cnt;
	}
}; 
unionFind uf;
int main() {
	int n, m, team, v, isfirst;
	while (true) {
		scanf("%d%d", &n, &m);
		if (!n && !m) break;
		uf._init();
		while (m--) {
			isfirst = -1;
			scanf("%d", &team);
			while (team--) {
				scanf("%d", &v);
				if (isfirst == -1) isfirst = v;
				else uf.uni(isfirst, v);
			}
		}
		// cout << bin[0] << ' ' << uf.anc(0) << endl; 
		// 注意这里的+1，因为我们统计的时候是从1开始的,而0也是自己就是感染者.. 
		printf("%d\n", uf.getcnt(uf.anc(0), n) + 1);
	}
	return 0;
}
