#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 2* 1e5 + 10;
int nums[N], root[N];
int cnt = 0;
struct Node {
	int l, r, sum;
} T[N * 40];
vector<int > vec;
int getid(int x) {
	return lower_bound(vec.begin(), vec.end(), x) - vec.begin() + 1;
}
void update(int l, int r, int &x, int y, int pos) {
	// ����һ������Ӧ��д��T[cnt].sum++;������û�����õݹ���ֹ������... 
	T[++cnt] = T[y], T[x].sum++, x = cnt;
	int mid = (l + r) >> 1;
	// �������ͨ�߶�������һ�£���x����y����������... 
	if (pos <= mid) update(l, mid, T[x].l, T[y].l, pos);
	else update(mid + 1, r, T[x].r, T[y].r, pos);
}
int query(int l, int r, int x, int y, int k) {
	int mid = (l + r) >> 1;
	// �����������Ӧ��д��T[T[y].l].sum - T[T[x].l].sum������ͨ���������Ľڵ��ϵ�Ԫ�ظ��������жϸ����Ǳ��ߣ�
	// ���������������������ж�...��������Ҳ���˵ݹ���ֹ����w.. 
	int sum = T[T[x].l].sum - T[T[y].r].sum;
	if (sum <= mid) return query(l, mid, T[x].l, T[y].r, k);
	else return query(mid + 1, r, T[x].r, T[y].r, k - sum);
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &nums[i]), vec.push_back(nums[i]);
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	for (int i = 1; i <= n; i++) update(1, n, root[i], root[i - 1], getid(nums[i]));
	return 0;
}
