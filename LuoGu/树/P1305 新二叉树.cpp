#include <iostream>
using namespace std;

// 主要是利用输入的字符串建树 

struct tree {
	char left, right;
};
tree t[26];
// 先序遍历 
void dfs(char x) {
	if (x != '*') {
		cout << x;
		dfs(t[x - 'a'].left);
		dfs(t[x - 'a'].right);
	}
}
int main() {
	int n;
	char root, l, r, tempRoot;
	cin >> n;
	cin >> root >> l >> r;
	// 第一个字符作为主根，其后两个字符作为左右节点 
	t[root - 'a'].left = l, t[root - 'a'].right = r;
	for (int i = 0; i < n - 1; i++) {
		cin >> tempRoot >> l >> r;
		// 映射节点关系 
		t[tempRoot - 'a'].left = l, t[tempRoot - 'a'].right = r;
	}
	dfs(root);
	return 0;
}
