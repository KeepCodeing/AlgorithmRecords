#include <iostream>
#include <vector>
using namespace std;

// 爆搜，把苹果数看成可以用的数，碟子数看成一次能用多少个数，总之就是个简单凑数问题 

// 再抽象下题目：有m个碟子，每个碟子可以放1~n个苹果..，其中，数字可以重复使用，也就是1..1..1..
// 1..1..2..之类的组合 

// 最普通的凑数问题w，只不过题目描述比较奇妙罢了 

// 居然该死的简单，本来还在想空碟子的情况是不是要特殊判断的，现在看起来是之前的思路有问题
// 之前想的是默认每个盘子都放至少一个苹果，所以就不能考虑到空碟子的情况

// 真实情况：想凑7，可以用3个数，考虑如7 0 0，1 6 0， 2 5 0等组合这里看似有个0，其实意思就是
// 选两个数或者更少的数就能够凑出目标数了...，所以只要保证：还有数可选，且当前没能选出来，
// 以及还有数可选，但是当前已经选出来了的情况就行.. 

typedef long long LL;
LL ans = 0;
vector<int > path;
void dfs(int level, int deepth, int sn, int target, int used) {
	// 选完了就不能选了，这里甚至没有一个剪枝... 
	if (used < 0) return;
	if (sn == target) {
//		for (int i = 0; i < path.size(); i++) cout << path[i] << ' ';
//		cout << endl;
		ans ++;
		return;
	}
	// 多选... 
	for (int i = level; i < deepth; i++) {
		path.push_back(i); 
		dfs(i, deepth, sn + i, target, used - 1);
		path.pop_back();
	}
}
int main() {
	int T;
	cin >> T;
	int m, n;
	while (T--) {
		cin >> m >> n;
		ans = 0;
		dfs(1, m + 1, 0, m, n);
		cout << ans << endl;
	} 
	return 0;
}
