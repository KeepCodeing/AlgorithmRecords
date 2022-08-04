#include <iostream>
using namespace std;
const int N = 10010;
int n, m, w;
int wei[N], val[N];
int bin[N];
int f[N];
struct unionFind {
	unionFind () {for (int i = 1; i <= N; i++) bin[i] = i;}
	int anc(int x) {
		// �о�����д���ǲ�̫���� 
		if (x != bin[x]) bin[x] = anc(bin[x]);
		return bin[x];
	}
	void uni(int x, int y) {
		if (!ask(x, y)) {
			int ax = anc(x), ay = anc(y);
			bin[ax] = ay;
			val[ay] += val[ax];
			wei[ay] += wei[ax];
		}
	}
	bool ask(int x, int y) {return anc(x) == anc(y);}
};
unionFind u;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> w;
	// ��������Ǽ�Ǯ�������Ǽ�ֵ�����Կ��ɴ��ۺͻ��� 
	for (int i = 1; i <= n; i++) cin >> wei[i] >> val[i];
	while (m--) {
		int x, y;
		cin >> x >> y;
		u.uni(x, y); 
	}
	// 01����ģ���е�����...
	// ��һ��ѭ��Ϊ�ж��ٸ���Ʒ���ڶ���ѭ��Ϊ
	// �����ж���Ǯ�Լ��ܻ�����Ǯ�����ۣ������յĽ��Ϊ
	// �ǵ�ǰ����Ż��ǻ�Ǯ����һ���������� 
	for (int i = 1; i <= n; i++) {
		if (i == bin[i]) {
			for (int j = w; j >= wei[i]; j--) {
				f[j] = max(f[j], f[j - wei[i]] + val[i]);
			}
		}
	}
	cout << f[w];
	return 0;
}
