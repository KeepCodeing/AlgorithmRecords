#include <iostream>
#include <cstdio>
using namespace std;

// ����Ҫ˵�±�Ȩ���鼯��ôд��֮ǰ���̳�д��һ������Ȩ���鼯���⣬���ñ�Ȩ�ܼ򵥣����ǽ�dist[x] += dist[bin[x]]����ǰ�ڵ�
// �ı�Ȩ�����䵽���ڵ�ı�Ȩ�� ������������ǰ׺�ͣ����������������һ���ڵ㵽���ڵ�ľ��롣��ô��μӱ�Ȩ�أ��������Ǹ�
// �������ø�sz�����¼��ǰ���Ĵ�С������Ӧ��ֻ���ñ�Ȩȫ��1���������ģ������������ķ�ʽ��dist[root] = -dist[x] + dist[y] + s
// ����root����x�ĸ��ڵ㣬y����Ҫ�ϲ����Ľڵ㣬s�����±�Ȩ����ôΪʲô��������д�أ��������½�x�ϲ���y�����ȵü�һ����ȨΪs
// �ıߣ�Ȼ�����y�ı�Ȩ����dist[y] + s������������x�ĸ��ڵ�ı�Ȩû�б仯����Ϊͼ����x->root�����ϲ������root->x������root��
// x�ı�Ȩ����-dist[x]������Щ���������������Ǹ�ʽ����... 

// �����Ӵ������������Ǹ���Ĵ�Ȩ���鼯�����ǻ�����Щ˼���Ѷȵġ����ȿ�����ô�ò��鼯��ʾһ�����䣬���ﲢ�鼯��ʾ������߶���
// ��ȫ��ͬ���Ͼ����鼯�ñ�Ȩ���߶����ýڵ�...�������һ������[a, b]���Ϊv�����ǲ����涨a->b��һ������Ϊv�ıߣ����߳����������
// �����ڵ���������С����ôѯ�ʲ�����Ӧ�ľ��ǲ�ѯһ�����䣬������������Ѿ����ڵģ���ôa��bһ���и���ͬ���ȣ����ǲ�ѯ[a,b]������
// �;�����dist[roota] - dist[rootb]..���ɹţ� 

const int N = 200000 + 10;
int bin[N], dist[N];
struct unionFind {
	void _init(int n) {
		for (int i = 1; i <= n; i++) bin[i] = i, dist[i] = 0;
	}
	int anc(int x) {
		if (x != bin[x]) {
			int pre = dist[x];
			bin[x] = anc(bin[x]), dist[x] += dist[pre];
		}
		return bin[x];
	}
	void uni(int x, int y, int s) {
		int ax = anc(x), by = anc(y);
		if (ax == by) return;
		dist[ax] = -dist[x] + dist[y] + s;
		bin[ax] = y;
	}
	bool ask(int x, int y) {
		return anc(x) == anc(y);
	}
	bool check(int l, int r, int v) {
		return dist[l] - dist[r] == v;
	}
};
unionFind uf;
int main() {
	int n, m, l, r, v;
	while (~scanf("%d%d", &n, &m)) {
		uf._init(n);
		int ans = 0;
		while (m--) {
			scanf("%d%d%d", &l, &r, &v);
			l--;
			// int ra = uf.anc(l), rb = uf.anc(r);
			if (uf.ask(l, r)) {
				if (!uf.check(l, r, v)) ans++;
			} else {
				uf.uni(l, r, v);
			}
		}
		printf("%d\n", ans);
		
	}
	return 0;
}
