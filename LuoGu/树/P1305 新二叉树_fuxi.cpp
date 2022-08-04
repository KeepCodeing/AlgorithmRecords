#include <iostream>
using namespace std;

// 刚刚做了个要建树的题，用的线段树的建树方法，这个题大概行不通了，不过应该可以用结构体做.. 
// 应该是没有子树相同的情况，那么可以用个结构体存节点值，左右子树的位置，然后从第一个节点开始遍历..
// 看了下以前抄题解的代码，很naive而且难以理解... 
// 感觉还是得有些想象力，以前因为不会建树浪费了好多时间，不过现在看来只是其没迈出那一步而已.. 

// val就是当前节点的字符形式，left，right是Tree中对应子树的下标 
struct Tree {
	char val;
	int left, right;
	// 空节点的特殊标记 
	Tree(char v = '@') {
		val = v;
	}
} tree[30];
// 模拟前序遍历的过程，注意这里传递的是下标 
void in_order(int now) {
	if (tree[now].val == '@') return;
	cout << tree[now].val;
	in_order(tree[now].left);
	in_order(tree[now].right); 
}
int main() {
	int n;
	cin >> n;
	string node;
	char root;
	for (int i = 0; i < n; i++) {
		cin >> node;
		// 记录整棵树的根节点 
		if (i == 0) root = node[0];
		// 根节点赋值 
		tree[node[0]].val = node[0];
		// 如果左右子树存在，这里就把当前节点的下标指过去，依次类推 
		if (node[1] != '*') tree[node[0]].left = node[1];
		if (node[2] != '*') tree[node[0]].right = node[2];
	}
	in_order(root);
	return 0;
} 
