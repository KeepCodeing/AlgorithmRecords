#include <iostream>
#include <cstdio>
using namespace std;

// 看紫书发现自己连建树都不会（特指数组），感觉很无语...BFS什么也没查到，看了学长
// 的代码感觉有点思路了。只不过那时候完完全全的小鬼呢，普及题想都没敢想的w.. 

const int N = 1e6 + 10;
struct Node {
	Node *l, *r;	
} tree[N];
int dep(Node *root) {
	if (root == NULL) return 0;
	// 树形动规，当前节点的最大深度就是前一个节点的深度加一 
	return max(dep(root->l), dep(root->r)) + 1;
}
int main() { 
	int n, a, b;
	scanf("%d", &n);
	// 节点下标从1开始的 
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &a, &b);
		// 这里比较奇妙，大致的意思就是当前节点的左孩子应该指向的是节点编号为a的根节点，
		// 同理右孩子指向的就是节点编号为b的根节点，因为题目给的就是节点编号，所以这里如果
		// 按常理来看比较奇怪... 
		tree[i].l = tree + a, tree[i].r = tree + b;
		if (a == 0) tree[i].l = NULL;
		if (b == 0) tree[i].r = NULL;
	}
	printf("%d", dep(tree + 1));
	return 0;
}
