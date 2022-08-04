#include <iostream>
#include <cstdio>
using namespace std;

// �����鷢���Լ������������ᣨ��ָ���飩���о�������...BFSʲôҲû�鵽������ѧ��
// �Ĵ���о��е�˼·�ˡ�ֻ������ʱ������ȫȫ��С���أ��ռ����붼û�����w.. 

const int N = 1e6 + 10;
struct Node {
	Node *l, *r;	
} tree[N];
int dep(Node *root) {
	if (root == NULL) return 0;
	// ���ζ��棬��ǰ�ڵ�������Ⱦ���ǰһ���ڵ����ȼ�һ 
	return max(dep(root->l), dep(root->r)) + 1;
}
int main() { 
	int n, a, b;
	scanf("%d", &n);
	// �ڵ��±��1��ʼ�� 
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &a, &b);
		// ����Ƚ�������µ���˼���ǵ�ǰ�ڵ������Ӧ��ָ����ǽڵ���Ϊa�ĸ��ڵ㣬
		// ͬ���Һ���ָ��ľ��ǽڵ���Ϊb�ĸ��ڵ㣬��Ϊ��Ŀ���ľ��ǽڵ��ţ������������
		// �����������Ƚ����... 
		tree[i].l = tree + a, tree[i].r = tree + b;
		if (a == 0) tree[i].l = NULL;
		if (b == 0) tree[i].r = NULL;
	}
	printf("%d", dep(tree + 1));
	return 0;
}
