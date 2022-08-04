#include <iostream>
using namespace std;

// 最大异或对就是用trie树来解的

// 分析下xor（异或）的概念：10010 xor 10000 = 00010，即“不进位的加法运算”，由此可以看出
// 如果想要有一个最大异或对，必须满足某个二进制位上的1 xor 0，某个二进制位上的0 xor 1 

const int N = 100010;
int son[N * 32][2], idx = 0;
int num[N];
void add(int x) {
	int p = 0;
	// 创建节点 
	for (int i = 30; ~i; i--) {
		// 取出x的每一位二级制数 
		int cur = x >> i & 1;
		if (!son[p][cur]) son[p][cur] = ++idx;
		p = son[p][cur];
	}
}
int query(int x) {
	int p = 0, res = 0;
	for (int i = 30; ~i; i--) {
		int cur = x >> i & 1;
		// 如果下一个节点和当前节点的二进制相反，则选择，否则只能选择相同的了 
		if (son[p][!cur]) {
			// 还原这一位上的数字，比如i = 3, 1左移i位就变成了1000，也就是8
			res += 1 << i;
			p = son[p][!cur]; 
		} else {
			p = son[p][cur];
		}
	}
	return res;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> num[i], add(num[i]);
	int res = -1;
	for (int i = 0; i < n; i++) res = max(res, query(num[i]));
	cout << res;
	return 0;
}
