#include <iostream>
using namespace std;

// 看了题解发现就是个普通爆搜，看到题目想到之间好像看到过类似的题，想到了全排列之类的，不过一看题面说
// 会有一百位二进制数局的不太可行...结果看了题解后只用写十九位，因为unsigned long long最多就十九位w，然后本体
// 就是个普通爆搜了，思考下一位二进制的情况，无非就是0,1，然而题面要求倍数非0，那么一位的情况就只有1了
// 再想下两位的情况，因为一位只能是1，因此两位也只能是10，或者11了，这么一看规律就出来了，就是个爆搜w 
// 前面说的有些太简单了，实际上可以画个递归树，可以发现左节点就是10，右节点就是11，依次类推，跑个前序
// 遍历顺便构造节点就行了... 

int x;
bool flag;
// 开unsigned long long防止溢出... 
void dfs(unsigned long long val, int deepth) {
	if (deepth > 19 || flag) return;
	if (!(val % x)) {
		cout << val << endl;
		flag = true; // 用来阻断后续的递归 
		return;
	}
	dfs(val * 10, deepth + 1);
	dfs(val * 10 + 1, deepth + 1);
}
int main() {
	while (true) {
		flag = false;
		cin >> x;
		if (!x) break;
		dfs(1, 0);	
	}
	return 0;
}
