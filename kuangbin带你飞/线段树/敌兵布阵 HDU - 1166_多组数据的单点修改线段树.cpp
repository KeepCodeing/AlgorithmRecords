#include <iostream>
#include <cstdio>
using namespace std;

// ��ͨ�����߶����������ж������ݣ������߶���Ҳ���������߶��������ʴ�������������߶�����д����... 
// ��������״��������򵥺ܶ࣬�������������w 

// ����AC����İ��ӣ�����WA�ˣ����Կ϶�����û����...�Ա�˯���ˣ�һ����������߶���������̫�Ա���... 

typedef long long LL;
const int N = 1e5 + 10, M = N * 4;
// int nums[N];
struct Node {
	// ���ÿ�long long�� 40000 * 30 = 1200000
	int l, r;
	LL lz, sum;
} root[M]; 
char op[10];
// �涨д��build��дpushup/down 
void pushup(int now) {
	root[now].sum = root[now << 1].sum + root[now << 1 | 1].sum;
}
void pushdown(int now) {
	if (root[now].lz) {
		int ln = now << 1, rn = now << 1 | 1;
		// ����ոյ����֪���Լ�����̱...����Ӳ��ת��int�ټӣ�WA��ʮ�������Ŵ�Ҳ���ֲ���Ϊʲô�����ǻ����... 
		LL lz = root[now].lz;
		root[ln].lz += lz, root[rn].lz += lz;
		root[ln].sum += (root[ln].r - root[ln].l + 1) * lz;
		root[rn].sum += (root[rn].r - root[rn].l + 1) * lz;
		root[now].lz = 0;
	} 
}
void build(int now, int left, int right) {
	// ���е�ʱ�����˳�ʼ�������Ҷ�ڵ����... 
	root[now].l = left, root[now].r = right;
	if (left == right) {
		// ���˼�&... 
		scanf("%lld", &root[now].sum);
		// root[now].sum = nums[left];
		root[now].lz = 0; 
		return;
	}
	int mid = (left + right) >> 1;
	int ln = now << 1, rn = now << 1 | 1;
	build(ln, left, mid);
	build(rn, mid + 1, right);
	pushup(now);
}
void update(int now, int L, int R, int val) {
	// ����д�ߵ���������ô��.. 
	if (L <= root[now].l && root[now].r <= R) {
		root[now].lz += val;
		root[now].sum += (root[now].r - root[now].l + 1) * val;
		return;
	}
	int mid = (root[now].l + root[now].r) >> 1;
	int ln = now << 1, rn = now << 1 | 1;
	pushdown(now);
	if (L <= mid) update(ln, L, R, val);
	if (mid < R) update(rn, L, R, val);
	pushup(now);
}
LL query(int now, int L, int R) {
	if (L <= root[now].l && root[now].r <= R) return root[now].sum;
	if (L > root[now].r || R < root[now].l) return 0;
	// ��Ҫ����pushdown 
	pushdown(now);
	// ���򻯺��query������ʡȥln��rn��ǰ��Ҳ��һ���������Ǹ�����ϰ�ߣ����Ըɴౣ������... 
	// Ȼ��<<д����>>... 
	return query(now << 1, L, R) + query(now << 1 | 1, L, R);
}
// ���޽�w�������ǶԵ�...���Ǿ���WA... 
// YATTZE!�����������ŷ���Ҫ��ʼ��... 
void _init() {
	for (int i = 0; i < M; i++) root[i].l = root[i].r = root[i].lz = root[i].sum = 0;
}
int main() {
	int T, n, x, y;
	scanf("%d", &T);
	// ������� 
	for (int t = 1; t <= T; t++) {
		_init();
		scanf("%d", &n);
		// for (int i = 1; i <= n; i++) scanf("%d", &nums[i]);
		// ��ν���������һ����O(n)�ĸ��Ӷȣ�˳���ڽ���������Ҷ�ӽڵ��ֵ������ʡ�ܶ�ռ� 
		build(1, 1, n);
		printf("Case %d:\n", t);
		while (true) {
			scanf("%s", &op);
			// ��Ȼ������ַ���������������C�ַ������ܷ���Ľ��жԱȣ���ÿ���ַ�����ͷ����һ�������жϿ�ͷ����.. 
			if (*op == 'E') break;
			// printf("%c\n", op[0]);
			// printf("%s\n", op);
			// �޸Ĳ�������ֵ���ǼӸ���... 
			// ע��Endû��x��y�����Բ������԰�x��yдǰ��... 
			scanf("%d%d", &x, &y);
			if (*op == 'A' || *op == 'S') {
				// ������̱�Ĵ�������д����op[0] = 'S'�����¼��ϵ�ֵ�ƺ�����ɸ����ˣ������˰����Ҳ���������... 
				if (*op == 'S') y = - y;
				update(1, x, x, y);
			} else {
				printf("%lld\n", query(1, x, y));
			}
		}
	}
	return 0;
}
