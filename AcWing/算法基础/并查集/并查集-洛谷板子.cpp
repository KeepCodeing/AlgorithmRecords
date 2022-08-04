#include <iostream>
using namespace std;

// fuxi�´���Ƚ̳���ѧ���Ĳ��鼯

// ��ʵ���鼯�����ڲ��������������ĸ��ڵ����������ϵı�ţ��ϲ�����
// ���ǽ�һ�����ĸ��ڵ�ָ����һ����������ڵ㡣 

// �ոնԱ�����new�����ڴ��ֱ�ӷ����ڴ��Ч�ʣ��ƺ��ǲ��ģ�������main��new�����
// ���鲻�ᱬջ���ϻ���new���䵽�Ŀռ��Ƕѿռ䣩�������ƺ�û����������new����̬�����
// һ�㻹��ֱ�ӿ��������飬������;... 

struct unionFind {
	int *bin;
	unionFind(int n) {
		bin = new int[n + 5];
		for (int i = 1; i <= n; i++) bin[i] = i;
	}
	int anc(int x) {
		if (x == bin[x]) return x;
		// ������ν��·��ѹ�������ڱ����Ĺ����а����б������Ľڵ�
		// ֱ��ָ����ڵ� 
		bin[x] = anc(bin[x]);
		return bin[x];
	}
	void uni(int x, int y) {
		// �ϲ�����y���ϵĸ��ڵ�ָ��x���ϵĸ��ڵ� 
		bin[anc(x)] = anc(y);
	}
	bool ask(int x, int y) {
		// ��ѯ���ж�x���ϵĸ��ڵ��Ƿ��y���ϵĸ��ڵ���ͬ 
		return anc(x) == anc(y);
	}
	~ unionFind() {
		delete[] bin;
	}
}; 
int main() {
	int n, m;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	unionFind u(n);
	char code;
	int a, b;
	while (m--) {
		cin >> code >> a >> b;
		if (code == 'M') u.uni(a, b);
		else cout << (u.ask(a, b) ? "Yes" : "No") << endl; 
	} 	
	return 0;
}
/*
����������
4 5
M 1 2
M 3 4
Q 1 2
Q 1 3
Q 3 4
���������
Yes
No
Yes
*/
