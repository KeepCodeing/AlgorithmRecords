#include <iostream>
#include <cstdio>
using namespace std;

// ����������⣬˼·���Ǽ�¼������ֵ������... 

typedef pair<int, int > PII;
const int N = 50000 + 10, M = N * 4;
struct Node {
	// ���ÿ�long long 
	int l, r, hei, low;
} root[M];
void pushup(int now) {
	// ��¼��ߵĺ����ţ�ĸ߶� 
	root[now].hei = max(root[now << 1].hei, root[now << 1 | 1].hei);
	root[now].low = min(root[now << 1].low, root[now << 1 | 1].low);
}
void build(int now, int left, int right) {
	root[now].l = left, root[now].r = right;
	if (left == right) {
		// ֱ������Ҷ�ӽڵ��ֵ���ܷ��㣬����ʡ�ռ� 
		scanf("%d", &root[now].hei);
		// Ĭ��Ҷ�ӽڵ��ţ������ߵģ�Ҳ����� 
		root[now].low = root[now].hei;
		// ����return ww
		return; 
	}
	int mid = (left + right) >> 1;
	int ln = now << 1, rn = now << 1 | 1;
	build(ln, left, mid);
	build(rn, mid + 1, right);
	pushup(now);
}
// ��������дupdate��pushdown...
PII query(int now, int L, int R) {
	// �ҵ���Ҫ�����䷵�������������ֵ����Сֵ�������ͺ����������жԱ� 
	if (L <= root[now].l && root[now].r <= R) return PII(root[now].hei, root[now].low);
	// �涨firstΪ���ֵ��secondΪ��Сֵ����ôû�ҵ��ͷ���һ������ֵ������ 
	if (L > root[now].r || R < root[now].l) return PII(-1e9, 1e9);
	// ����pushdown
	// �ҵ��������������ֵ����Сֵ�ԣ�Ȼ��Ա� 
	PII nhei = query(now << 1, L, R);
	PII nlow = query(now << 1 | 1, L ,R); 
	// �Ա�����������ֵ������������ֵ�����������Сֵ�����������Сֵ... 
	return PII(max(nhei.first, nlow.first), min(nhei.second, nlow.second));
}
int main() {
	int n, m, l ,r;
	scanf("%d%d", &n, &m);
	build(1, 1, n);
	while (m--) {
		scanf("%d%d", &l, &r);
		PII res = query(1, l, r);
		printf("%d\n", res.first - res.second);
	}
	return 0;
}
