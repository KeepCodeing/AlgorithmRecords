#include <iostream>
#include <cstdio>
using namespace std;

// ��״�����һ������ʵ֮ǰ�Ѿ�д���ˣ�������дһ��fuxi��˳��Ա��º��߶�����Ч�ʲ��... 
// �ƺ�û�п���٣�����������ڴ�ȷʵ���߶����ٺܶ�... 

const int N = 5 * 1e5 + 100;
int n, m;
int root[N];
int lowbit(int x) {
	return x & (-x);
}
void add(int idx, int val) {
	for (int i = idx; i <= n; i += lowbit(i)) root[i] += val;
}
int query(int end) {
	int ans = 0;
	for (int i = end; i; i -= lowbit(i)) ans += root[i];
	return ans;
}
int main() {
	scanf("%d%d", &n, &m);
	int val;
	for (int i = 1; i <= n; i++) cin >> val, add(i, val);
	int op, x, y;
	while (m--) {
		scanf("%d%d%d", &op, &x, &y);
		if (op == 1) add(x, y);
		// ע������������Ҫ-1... 
		else printf("%d\n", query(y) - query(x - 1));
	}
	return 0;
}
