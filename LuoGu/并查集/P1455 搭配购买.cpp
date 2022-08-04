#include <iostream>
using namespace std;
const int N = 10010;
int n, m, w;
int val[N], wei[N];	
int  bin[N];
struct unionFind {
	unionFind() {
		for (int i = 1; i <= N; i++) bin[i] = i;
	}
	int anc(int x) {
		// ���鼯�����Ȼд����.. 
		if (x != bin[x]) bin[x] = anc(bin[x]);
		return bin[x];
	}
	void uni(int x, int y) {
		int ax = anc(x), ay = anc(y);
		bin[ax] = ay;
		val[ay] += val[ax];
		wei[ay] += wei[ax];
	}
	bool ask(int x, int y) {
		return anc(x) == anc(y);
	}
	
};
unionFind u;
int f[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> w;
	for (int i = 1; i <= n; i++) cin >> val[i] >> wei[i];
	while (m--) {
		int x, y;
		cin >> x >> y;
		if (!u.ask(x, y)) u.uni(x, y); 
	}
	for (int i = 1; i <= n; i++) {
		if (i == bin[i]) {
			for (int j = w; j >= val[i]; j--) {
				f[j] = max(f[j], f[j - val[i]] + wei[i]);
			}
		}
	}
	// ��ʲô��Ц��UDK���ɣ�������֮ǰд����f[n]����Ȼ��ֻWA��������... 
	cout << f[w];
	return 0;
}
