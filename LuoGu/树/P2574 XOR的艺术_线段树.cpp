#include <iostream>
using namespace std;

// �߶����������������է������������ģ���⣬��Ϊ��˵Ҫͳ�Ƶ���һ���������ַ�1�ĸ�������ô����˼������ô
// �����߶���ͳ������ַ���������������ַ���ֻ����0��1��˼�����߶��ǵ���������ô�õ��ľͿ��Է��֣�����ַ���
// һ���Ǳ�ӳ�䵽���߶�����Ҷ�ӽڵ��ϣ���Ҷ�ӽڵ��ֵֻ��0��1����ô������ǽ����0,1���������֣����ѷ��֣�Ҷ��
// �ڵ�ĸ��ڵ������ֵ�����������ӽڵ�ĺͣ�Ȼ����������..����ӲҪ˵������ģ������ʲô��ͬ�Ļ�����ž���ԭ
// ����ֻ��0��1������������ν���ַ�����ʽ������... 

// д���˷��ֲ��ǵ����޸�...����ǰ�query�����ˣ��͵���ϰ����... 

const int N = 2 * 1e5, M = N * 4;
int arr[N], root[M];
void build(int now, int left, int right) {
	if (left == right) {
		root[now] = arr[left];
		return;
	}
	int mid = (left + right) / 2;
	int l_node = now * 2 + 1, r_node = now * 2 + 2;
	build(l_node, left, mid);
	build(r_node, mid + 1, right);
	root[now] = root[l_node] + root[r_node];
}
void update(int now, int left, int right, int idx) {
	if (left == right) {
		// �����ֻ��0��1��1��0�Ĳ���������ֻ��ҪҪ�޸ĵ�Ҷ�ӽڵ���±꣬���ڱ�ֵ���Կ��������Ǹ�ȡ������.. 
		root[now] = !root[now];
		return;
	}
	int mid = (left + right) / 2;
	int l_node = now * 2 + 1, r_node = now * 2 + 2;
	// ���ﻹ�ǵ�ǿ���£��ж�����������ͨ��mid����.. 
	if (idx <= mid) update(l_node, left, mid, idx);
	else update(r_node, mid + 1, right, idx);
	root[now] = root[l_node] + root[r_node];
}
int query(int now, int left, int right, int L, int R) {
	if (L <= left && right <= R) return root[now];
	if (L > right || R < left) return 0;
	int mid = (left + right) / 2;
	int l_node = now * 2 + 1, r_node = now * 2 + 2;
	return query(l_node, left, mid, L, R) + query(r_node, mid + 1, right, L, R);
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	char c;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> c, arr[i] = c - '0';
	int op, x, y;
	build(0, 0, n - 1);
	while (m--) {
		cin >> op >> x >> y;
		x--, y--; // ϲ���ּ����±�����..
		// ���ǵ����޸ģ������� 
//		if (!op) update(0, 0, n - 1, )
	}
	return 0;
}
