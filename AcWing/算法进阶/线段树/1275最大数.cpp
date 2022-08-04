#include <iostream>
#include <cstdio>
using namespace std;

// �����޸��߶��������Ĳ�����pushup���ò������Դ������������ø������ֵ
// ʵ��
// 0. �洢
// �ýṹ����L,R,�Լ�[l, R]�����ֵ 
// 1. ���� 
// �õݹ鷽ʽ���������ø��ڵ�u�ٷֱ�ݹ������ӽڵ㡣 
// ��ڵ㣺u << 1 == 2 * u���ҽڵ� u << 1 | 1 == 2 * u + 1 
// 2. ��ѯ
// �赱ǰ����СΪn�������������ݹ��ѯ���������ڣ����������������� 
// ��ǰ���ѱ������ڲ�ѯ���䣬�ͷ��ص�ǰ�������ֵ�������
// ��ѯ���ҽڵ� 
// 3. ���
// �����ǰ�ڵ���Ҫ��ӵ�λ�ã��͸�ֵ��ǰ�㣬����͵ݹ����ҽڵ㣬����
// ���µ�ǰ�ڵ�����ֵ

const int N = 2e5 + 10;
// �߶���һ��Ҫ���ı���С�������ֹԽ�� 
struct Node {
	int l, r, v;
	Node(int l, int r) : l(l), r(r) {};
	Node () {};
} tr[N * 4];

// �����������ֵ
void pushup(int root) {
	// �������ӽڵ��ֵ�Ƴ����ڵ��ֵ 
	tr[root].v = max(tr[root << 1].v, tr[root << 1 | 1].v);
} 

// �������Ȱ������Ҫ�õ�����������׼���� 
void build(int root, int l, int r) {
	tr[root] = Node(l, r);
	// ����Ѿ�����Ҷ�ӽڵ㣬��û��Ҫ������չ�� 
	if (l == r) return;
	int mid = l + r << 1;
	// root << 1�����������ĸ��ڵ㣬root << 1 | 1�����������ĸ��ڵ㣬�����ڵ�û�н��� 
	build(root << 1, l, mid), build(root << 1 | 1, mid + 1, r);
}

// ��ѯ�������ֵ���ֶ������ 
int query(int root, int l, int r) {
	// ���һ�������ѯ�����ڵ�ǰ����[l, r]�ڣ���ѯ��������ֵ���ǵ�ǰ��������ֵ��ֱ�ӷ��ؼ��� 
	if (tr[root].l <= l && tr[root].r >= r) return tr[root].v;
	int v = 0;
	int mid = tr[root].l + tr[root].r >> 1;
	// ���������ѯ���������뵱ǰ������ұ��н�����ȥ�������� 
	if (l <= mid) v = max(query(root << 1, l, r), v);
	// ���������ѯ������ұ��뵱ǰ���������н�����ȥ�������� 
	if (mid < r) v = max(query(root << 1 | 1, l, r), v); 
	return v;
}

// �޸Ĳ�������x����ڵ��ϵ�ֵ�޸�Ϊv
void modify(int root, int x, int v) {
	// ����ҵ���������㣨���ҵ�����������ڵ�Ҷ�ӽڵ㣩������ֵ�޸� 
	if (tr[root].l == x && tr[root].r == x) {
		tr[root].v = v;
	} else {
		// ���û�ҵ����Ҷ�ӽڵ㣬�ж�����ȥ������������ڵ㻹����������
		int mid = tr[root].l + tr[root].r >> 1;
		// ȥ�������� 
		if (x <= mid) modify(root << 1, x, v);  
		else modify(root << 1 | 1, x, v); // ȥ��������
		// ����ڻ��ݵĹ����и��¸��ڵ���������ֵ����Ϊ�ӽڵ㷢���˱仯
		// ���ڵ�ҲҪ��Ӧ�仯
		pushup(root); 
	}
	
} 
int main() {
	int m, p;
	scanf("%d%d", &m, &p);
	build(1, 1, m);
	char op[2];
	int last = 0, n = 0;
	int x;
	while (m--) {
		scanf("%s%d", &op, &x);
		if (*op == 'Q') {
			last = query(1, n - x + 1, n);
			printf("%d\n", last);
		} else {
			modify(1, n + 1, (last + x) % p);
			n++;
		} 
	}
	return 0; 
}
