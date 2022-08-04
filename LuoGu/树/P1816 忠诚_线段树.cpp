#include <iostream>
using namespace std;

// �߶�����������׼ȷ��˵�ǵڶ����������������û�и��²�������˽���+��ѯ��������... 
// ����˵�����������nth_element�����������������������w�������й���Ц����...
// ����о������µ������.. 
// ����о������·֮������࣬��Ҫ�Ƕ����ũ��... 

const int N = 100000 + 10, M = N * 4 + 10;
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
	root[now] = min(root[l_node], root[r_node]);
}
int query(int now, int left, int right, int L, int R) {
	// ����ط�֮ǰ�����ǵ�ǰ�ڵ����������˲�ѯ�����ֱ�ӷ��أ�����ʵ�����������˼�����
	// ��ǰ�ڵ�����䱻��ѯ�����������ֱ�ӷ���.. 
	if (L <= left && right <= R) return root[now];
	if (L > right || R < left) return 1e9;
	int mid = (left + right) / 2;
	int l_node = now * 2 + 1, r_node = now * 2 + 2;
	return min(query(l_node, left, mid, L, R), query(r_node, mid + 1, right, L, R));
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	int x, y;
	build(0, 0, n - 1);
	while (m--) {
		cin >> x >> y;
		x--, y--;
		cout << query(0, 0, n - 1, x, y) << ' ';
	}
	return 0;
}
