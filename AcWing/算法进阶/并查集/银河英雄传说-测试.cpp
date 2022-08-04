#include <iostream>
#include <cmath>
using namespace std;
const int N = 30010;
struct unionFind {
	int dist[N], bin[N], sz[N];
	// ����dist��Ȼ����Ϊ1�ˣ��Լ����Լ��ľ���Ϊ0... 
	unionFind () {for (int i = 1; i <= N; i++) dist[i] = 0, bin[i] = i, sz[i] = 1;}
	int anc(int x) {
		// ��������ǰ׺�͵Ĳ������Ǽӱ�Ȩ��ÿ����ı�Ȩ���ǵ����ڵ�ľ��� 
		if (x != bin[x]) {
			// ע�������˳���ܴ�������ǰ׺����·��ѹ�� 
			dist[x] += dist[bin[x]];
			bin[x] = anc(bin[x]);
		}
		return bin[x];
	}
	void uni(int x, int y) {
		// �ϲ��ӱ�Ȩ���ǰѱ��ϲ����ϵĸ��ڵ������ںϲ����ϵĴ�С 
		int ax = anc(x), ay = anc(y);
		// ͬһ���ڵ㲻�ܷ������� 
		//if (ax != ay) {
		dist[ax] = sz[ay];
		// ���¼��ϴ�С 
		sz[ay] += sz[ax];
		bin[ax] = ay;
		//}
	}
	int getDist(int x, int y) {
		int ax = anc(x), ay = anc(y);
		if (ax != ay) return -1;
		// �����̣�����д����ax��ay����ͱ���˸��ڵ���������... 
		return max(0, abs(dist[x] - dist[y]) - 1);
	}
};
unionFind u;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		char op;
		int x, y;
		cin >> op >> x >> y;
		if (op == 'M') u.uni(x, y); 
		else cout << u.getDist(x, y) << endl; 
	}
	return 0;
} 
