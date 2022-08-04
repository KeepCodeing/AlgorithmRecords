#include <iostream>
using namespace std;

// �߶������ĵ�������������ģ����... 
// ���Ƿ���ЩС����...�������о��߶��������ظ�����Ҳͦ���...��Ų������ĺ����أ��Ͼ�ÿ�������������м�λ��
// �������±꣬�������±�Ĳ����� �����½̳̺�ͼƬӦ���ܹ�����д��ȥ��... 

const int N = 100000 + 10, M = N * 4;
// ��ʼȫΪ0����Ϊȫ�ֱ����Ͳ��ó�ʼ����... 
int root[M];
void build(int now, int left, int right) {
	if (left == right) {
		root[now] = 0;
		return;
	}
	int mid = (left + right) / 2;
	int l_node = now * 2 + 1, r_node = now * 2 + 2;
	build(l_node, left, mid);
	build(r_node, mid + 1, right);
	root[now] = root[l_node] + root[r_node];
}
void update(int now, int left, int right, int idx, int val) {
	if (left == right) {
		root[now] += val;
		return;
	}
	int mid = (left + right) / 2;
	int l_node = now * 2 + 1, r_node = now * 2 + 2;
	// ע�������ж�Ҫ�޸ĵ�Ҷ�ӽڵ����������仹���������Ǹ����м���±����ģ�������idx <= left��������Ļ�
	// ���ڵ��leftһ����0����ôidx������ô�������ȴ���������ʼ... 
	if (idx <= mid) update(l_node, left, mid, idx, val);
	else update(r_node, mid + 1, right, idx, val);
	root[now] = root[l_node] + root[r_node];
}
int query(int now, int left, int right, int L, int R) {
	if (L <= left && right <= R) return root[now];
	if (L > right || R < left) return 0;
	int mid = (left + right) / 2;
	// �����ҽڵ���޸�д����now * 2 + 1... 
	int l_node = now * 2 + 1, r_node = now * 2 + 2;
	return query(l_node, left, mid, L, R) + query(r_node, mid + 1, right, L, R);
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	char c;
	int x, y;
	// �о����ﲻ�ý�������Ϊ���������������ͣ�������Ĭ��ȫΪ0�����
	// Ӧ��ֻ���ṩ��ѯ���޸ľ�����... 
	// build(0, 0, n - 1);
	while (m--) {
		cin >> c >> x >> y;
		// ע����������Ҫ�ӵ�ֵ����������Ǹ��£�x��ʾλ�ã�y��ʾҪ�ӵ�ֵ 
		// ����x��y����ʾ�������䷶Χ... 
		if (c == 'x') update(0, 0, n - 1, x - 1, y);
		else cout << query(0, 0, n - 1, x - 1, y - 1) << endl;
	}
	return 0;
}
