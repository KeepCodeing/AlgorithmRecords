#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

// һ��ʼ����Ǳ�������Ԫ������Ȼ����뵽�����ȶ��У�����ʵ�����ƺ���̫��ʵ��Ȼ�����뵽����λ������������KС֮���ô��
// ���Ծ��뵽����ϯ��... 
// Ȩ����ϰ��ϯ����������֪��Ϊʲô����û�����Ҫ˼������w... 

const int N = 100000 + 10;
vector<int > vec;
int nums[N], root[N], cnt = 0;
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
	if (pos <= mid) update(l, mid, T[x].l, T[y].l,  pos);
	else update(mid + 1, r, T[x].r, T[y].r, pos);
}
int query(int l, int r, int x, int y, int k) {
	if (l == r) return l;
	int mid = (l + r) >> 1;
	int sum = T[T[y].l].sum - T[T[x].l].sum;
	if (k <= sum) return query(l, mid, T[x].l, T[y].l, k);
	else return query(mid + 1, r, T[x].r, T[y].r, k - sum);
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &nums[i]), vec.push_back(nums[i]);
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end()); 
	for (int i = 1; i <= n; i++) update(1, n, root[i], root[i - 1], getid(nums[i]));
	for (int i = 1; i <= n; i++) {
		if (i % 2) {
			// Ҫ��ѯ������Ӧ���Ǵ�1��i����ô��1����x��i����y������������ʽ�ˣ������kС��ʵ��������λ����Ҳ��������
			// ����/2�������kС���ߵ�k��Ӧ�ö�û����... 
			printf("%d\n", vec[query(1, n, root[1 - 1], root[i], (1 + i) / 2) - 1]);
		}
	}
	return 0;
}
