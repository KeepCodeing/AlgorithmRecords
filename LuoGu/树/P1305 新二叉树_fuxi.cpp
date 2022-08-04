#include <iostream>
using namespace std;

// �ո����˸�Ҫ�������⣬�õ��߶����Ľ�����������������в�ͨ�ˣ�����Ӧ�ÿ����ýṹ����.. 
// Ӧ����û��������ͬ���������ô�����ø��ṹ���ڵ�ֵ������������λ�ã�Ȼ��ӵ�һ���ڵ㿪ʼ����..
// ��������ǰ�����Ĵ��룬��naive�����������... 
// �о����ǵ���Щ����������ǰ��Ϊ���Ὠ���˷��˺ö�ʱ�䣬�������ڿ���ֻ����û������һ������.. 

// val���ǵ�ǰ�ڵ���ַ���ʽ��left��right��Tree�ж�Ӧ�������±� 
struct Tree {
	char val;
	int left, right;
	// �սڵ�������� 
	Tree(char v = '@') {
		val = v;
	}
} tree[30];
// ģ��ǰ������Ĺ��̣�ע�����ﴫ�ݵ����±� 
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
		// ��¼�������ĸ��ڵ� 
		if (i == 0) root = node[0];
		// ���ڵ㸳ֵ 
		tree[node[0]].val = node[0];
		// ��������������ڣ�����Ͱѵ�ǰ�ڵ���±�ָ��ȥ���������� 
		if (node[1] != '*') tree[node[0]].left = node[1];
		if (node[2] != '*') tree[node[0]].right = node[2];
	}
	in_order(root);
	return 0;
} 
