#include <iostream>
using namespace std;

// 具体思路是先根据先序遍历得到根节点，再根据中序遍历
// 得到左右节点，然后再根据先序遍历分析左右节点 

void dfs(string a, string b) {
	if (!b.size()) return;
	int pos = a.find(b[0]);
	// 先从先序序列找到当前主根，然后通过主根获取其左右子树
	// 遍历左子树 
	dfs(a.substr(0, pos), b.substr(1, pos));
	// 遍历右子树 
	dfs(a.substr(pos + 1), b.substr(pos + 1));
	cout << b[0]; 
}

int main() {
	string mid, fir;
	cin >> mid >> fir;
	dfs(mid, fir);
	return 0;
}
