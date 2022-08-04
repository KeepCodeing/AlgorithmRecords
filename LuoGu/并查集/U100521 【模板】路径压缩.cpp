#include <iostream>
using namespace std;

// ���ų��˲��鼯dfsӦ��Ҳ��������ʵ������������Ҫ��ÿ����
// ������һ��dfs��������׹����... 

struct unionFind {
	int *bin;
	// ��Ŀ������˼����˵��m���㣬ÿ����Ĭ��ָ���Լ�
	// ���ǲ�һ���������е㶼�����ȣ���ô���������Ⱦ���
	// �Լ�����Ȼ������ô������������У���������ǵ�һ������ 
	unionFind(int m) {
		bin = new int[m + 10];
		for (int i = 1; i <= m; i++) {
			bin[i] = i;
		}
	}
	int anc(int x) {
		if (x == bin[x]) return x;
		bin[x] = anc(bin[x]);
		return bin[x];
	}
	void uni(int x, int y) {
		bin[anc(x)] = anc(y);
	}
	bool ask(int x, int y) {
		return anc(x) == anc(y);
	}
	~ unionFind() {
		delete[] bin;
	}
};

int n, m;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	unionFind u(m);
	while (n--) {
		int x, y;
		cin >> x >> y;
		u.uni(x, y); 
	} 
	int q;
	cin >> q;
	while (q--) {
		int op, x, y;
		cin >> op >> x;
		if (!op) {
			cin >> y;
			if (u.ask(x, y)) cout << "Yes";
			else cout << "No";
		} else {
			// ��һ�����������ȵ��⣬����ģ���ȫ������������ 
			cout << u.anc(x);
		}
		cout << endl;
	}
	return 0;
}
