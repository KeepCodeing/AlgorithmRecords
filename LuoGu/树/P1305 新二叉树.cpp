#include <iostream>
using namespace std;

// ��Ҫ������������ַ������� 

struct tree {
	char left, right;
};
tree t[26];
// ������� 
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
	// ��һ���ַ���Ϊ��������������ַ���Ϊ���ҽڵ� 
	t[root - 'a'].left = l, t[root - 'a'].right = r;
	for (int i = 0; i < n - 1; i++) {
		cin >> tempRoot >> l >> r;
		// ӳ��ڵ��ϵ 
		t[tempRoot - 'a'].left = l, t[tempRoot - 'a'].right = r;
	}
	dfs(root);
	return 0;
}
