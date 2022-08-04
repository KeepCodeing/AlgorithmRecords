#include <iostream>
using namespace std;

// �߶�����һ��-�£���һ�����뱬�������㣬��Ϊ�̵̳Ĵ�����Щ����...���Ŵ𰸵Ĵ������3��Сʱ��������Ȼ����˵
// ���µ���⣬���Ǹо�Ҳûʲô�߼��ϵĴ�����.. 

const int N = 200000 + 10, M = N * 4 + 10; // ע���߶���������ռ䣬�������Կ�������ˣ�����Ҫ�����ж��ٸ���������һ�㿪4���ռ�.. 
// arr������ڸ���Ҷ�ӽڵ��ʱ���õ��ˣ������ܿ�ϧҶ�ӽڵ�ı����Ȼ�Ǵ�0�����ģ�����������ı�Ų��ǣ�������ʡ�������.. 
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
	// ����ͽ̳���ʵûʲô���𣬲������ȡmax�Ĳ������ܻ����õ�����˿���д��һ������ 
	root[now] = max(root[l_node], root[r_node]);
}
void update(int now, int left, int right, int idx, int val) {
	if (left == right) {
		// ��Ŀ˵ԭ�������߾Ͳ����ģ���������û����̳��и���ԭ���飬�ƺ�����Ϊ�ò���... 
		root[now] = max(root[now], val);
		return;
	}
	int mid = (left + right) / 2;
	int l_node = now * 2 + 1, r_node = now * 2 + 2;
	// ����Ҳ�ͽ̳����left <= idx <= mid��ͬ�������ж���������ֻ��Ҫ����mid�������ˣ������о�д�ɽ̳������ȽϺ� 
	if (left <= idx && idx <= mid) update(l_node, left, mid, idx, val);
	else update(r_node, mid + 1, right, idx, val);
	// ��������·���������� 
	root[now] = max(root[l_node], root[r_node]);
}
int query(int now, int left, int right, int L, int R) {
	// ����ͽ̳���ȫ��һ�����̳���Ҳ�����������д�������ֻҪ�ж��µ�ǰ�����Ƿ񱻰������ɣ�����Ҫ��֦
	// ����left == right����Ϊ���߱������ˣ�����ͨ���жϱ�Ž��� 
	if (L <= left && right <= R) return root[now];
	// ��֦�������ǰ������ȫ�ò���ֱ�Ӽ��� 
	if (left > R || right < L) return -1e9;
	int mid = (left + right) / 2;
	int l_node = now * 2 + 1, r_node = now * 2 + 2;
//	int ans = -1e9;
	// ����ͽ̳̲�ͬ���̳���Ӧ�ö�Ӧ��������������ȫ���ཻ�ļ�֦����ô�����Ӧ�ľ��������䱻����
	// �������䱻�������о�����д̫�鷳���Ի��ɽ̵̳ļ�֦�� 
//	if (L <= mid) ans = max(ans, query(l_node, left, mid, L, R));
//	if (R > mid) ans = max(ans, query(r_node, mid + 1, right, L, R));
	// �Ա��������������ֵ 
	return max(query(l_node, left, mid, L, R), query(r_node, mid + 1, right, L, R));;
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i]; // ע�������������0��ʼ����Ŀ�����1��ʼ��������滹Ҫ��ȥ1 
	build(0, 0, n - 1);
	char op;
	int x, y;
	while (m--) {
		cin >> op >> x >> y;
		if (op == 'Q') cout << query(0, 0, n - 1, x - 1, y - 1) << endl;
		else update(0, 0, n - 1, x - 1, y);
	}
	return 0;
}
