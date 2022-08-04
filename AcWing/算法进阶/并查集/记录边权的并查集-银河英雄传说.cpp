#include <iostream>
#include <cmath>
using namespace std;
const int N = 30010;
struct unionFind {
	// sz��ʾ��ǰ��ͨ���С��dist��ʾ������ÿ���ڵ㵽���ľ��� 
	int bin[N], sz[N], dist[N];
	unionFind () {
		for (int i = 1; i <= N; i++) {
			bin[i] = i, sz[i] = 1, dist[i] = 0;
		}
	}
	int anc(int x) {
		if (bin[x] != x) {
			// �ڽ���·��ѹ����ͬʱ����ǰ�ڵ㵽���ڵ�ľ����Ϊ��ǰ�ڵ㵽���ڵ�ľ��룬��������
			// ��һ��ǰ׺�ͺ���Ϳ�����������������ս��֮�������ս�� 
			dist[x] += dist[bin[x]];
			bin[x] = anc(bin[x]);
		}
		return bin[x];
	}
	// �ϲ����� 
	void uniDist(int x, int y) {
		int ax = anc(x), ay = anc(y);
		// ��Ϊ�ڲ�ѯʱ������������ǰ׺�͵�˼�룬���Ժϲ�ʱҪ������x�����е�
		// ���¼���y���ڵ�ľ������ֻ��Ҫ��x���ϴ��ǰ׺�͸�Ϊy���ϵ�sz���Լ��� ����������Ŷ��
		
		// ��Ϊ�����õ���ǰ׺�ͣ����Ժϲ�����ֻ��Ҫ�ĸ��ڵ�ľ�����С���ô�ɸ��ڵ�x���¸��ڵ�y�ľ���
		// ����y��size���ԣ�����ֻ��Ҫ��x��y�ľ������y��size���Լ��ɡ���Ϊx�����Ǹ����ڵ㣬����������
		// ��ֱ�Ӽ�y��size���Ի��ǵ���y��size���Զ���һ���� 
		dist[ax] = sz[ay];
		// ��Ϊ������һ�����ϣ�����Ҫ����y���ϵĴ�С 
		sz[ay] += sz[ax];
		// ��x�ĸ��ڵ�ָ��y 
		bin[ax] = ay;
	}
	int getDist(int x, int y) {
		int ax = anc(x), ay = anc(y);
		if (ax != ay) return -1;
		// �����ڵ�ľ����������ǰ׺�͹�ʽ�����������Ϊ��֪���Ⱥ�˳������Ҫ���¾���ֵ
		// ������Ϊ��ĿҪ������м��ж���ս�������Ի�Ҫ-1���������x==y����ô���ǵó�������
		// -1��ʵ�ʴ���0�����Ի�Ҫ�Ӹ�max������ 
		return max(0, abs(dist[x] - dist[y]) - 1);
	}
};
unionFind u;
int main() {
	int T;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		char op;
		int x, y;
		cin >> op >> x >> y;
		if (op == 'M') u.uniDist(x, y);
		else cout << u.getDist(x, y) << endl;
	} 
	return 0;
} 

/*
����������
4
M 2 3
C 1 2
M 2 4
C 4 2
���������
-1
1
*/
