#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 2e5 + 10;
int nums[N];
vector<int > vec;
int root[N];
int cnt = 0;
struct Node {
	int l, r, sum;
} T[N * 40];
int getid(int x) {
	return lower_bound(vec.begin(), vec.end(), x) - vec.begin() + 1;
}
void update(int l, int r, int& x, int y, int pos) {
	T[++cnt] = T[y], T[cnt].sum++, x = cnt;
	if (l == r) return;
	int mid = (l + r) >> 1;
	if (pos <= mid) update(l, mid, T[x].l, T[y].l, pos);
	else update(mid + 1, r, T[x].r, T[y].r, pos);
}
int query(int l, int r, int x, int y, int k) {
	if (l == r) return l;
	int mid = (l + r) >> 1;
	// ����ע�͵����ǲ�ѯ����kС�Ĵ��룬���Կ�������ѯ����k���ڴ�����
	// ��kС�Ƿ������ģ�����ѯ���������䣬����sumС����������.. 
//	int sum = T[T[y].l].sum - T[T[x].l].sum;
//	if (k <= sum) return query(l, mid, T[x].l, T[y].l, k);
//  else return query(mid + 1, r, T[x].r, T[y].r, k - sum);
	int sum = T[T[y].r].sum - T[T[x].r].sum;
	// ����д���ˣ�д����k >= sum������û����ȫ������...����ϰʱ�� 
	if (k > sum) return query(l, mid, T[x].l, T[y].l, k - sum);
	else return query(mid + 1, r, T[x].r, T[y].r, k);
}
int main() {
	int n, m, x, y, k;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &nums[i]), vec.push_back(nums[i]);
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	for (int i = 1; i <= n; i++) update(1, n, root[i], root[i - 1], getid(nums[i]));
	scanf("%d", &m);
	while (m--) {
		scanf("%d%d%d", &x, &y, &k);
		printf("%d\n", vec[query(1, n, root[x - 1], root[y], k) - 1]);
	} 
	return 0;
}
