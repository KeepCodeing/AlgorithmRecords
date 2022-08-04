#include <iostream>
#include <cstdio>
using namespace std;

// �߶����ڢᵯ���⼸���ǿ��ˢ�߶�������֪���ռ���ˢ���˻᲻��������ף�����ʲ���w����ˢ����ƻ�ȥLeetCodeˢ
// ����...���о�����ɢ��ѧ��ҵ..�üӰѾ�����.. 
// ˵���������Ҳ�Ǿ�̬���䣬������ST�������״�����Щ��.. 

// ��Ȼ������֭����.. 

const int N = 50000 + 10, M = N * 4;
int arr[N];
// �����һ��Ҫά��������ֵ 
struct Node {
	int maxNum, minNum;
	Node (int maxNum, int minNum) : maxNum(maxNum), minNum(minNum) {};
	Node () {};
} root[M];
void build(int now, int left, int right) {
	if (left == right) {
		root[now].maxNum = root[now].minNum = arr[left];
		return;
	}
	int mid = (left + right) >> 1;
	int l_node = now << 1, r_node = now << 1 | 1;
	build(l_node, left, mid);
	build(r_node, mid + 1, right);
	root[now].maxNum = max(root[l_node].maxNum, root[r_node].maxNum);
	root[now].minNum = min(root[l_node].minNum, root[r_node].minNum);
}
Node query(int now, int left, int right, int L, int R) {
	if (L <= left && right <= R) return root[now];
	if (L > right || R < left) return Node(-1e9, 1e9);
	int mid = (left + right) >> 1;
	int l_node = now << 1, r_node = now << 1 | 1;
	// ������ͼֱ�ӷ��ظ�Node���󣬽��ȴ���˵���query...
	// ����Ҫע�����ֶ���ֵ��ѯ���߶����ǲ���ֱ�ӷ��ؽ���ģ���������ṹ����ܷ��أ���ô���صĽṹ��
	// ����������������������ֵ... 
	Node lres = query(l_node, left, mid , L, R), rres = query(r_node, mid + 1, right, L, R);
	return Node(max(lres.maxNum, rres.maxNum), min(lres.minNum, rres.minNum));
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	int x, y;
	build(1, 1, n);
	while (m--) {
		scanf("%d%d", &x, &y);
		Node res = query(1, 1, n, x, y);
		printf("%d\n", res.maxNum - res.minNum);
	}
	return 0;
} 
