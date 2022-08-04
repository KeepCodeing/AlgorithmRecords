#include <iostream>
using namespace std;

// ���鼯��ģ���⣬�����ֻ��Ҫʵ���²��鼯�Ļ������ܼ���

struct unionFind {
	int *bin;
	unionFind(int len) {
		bin = new int[len + 1];
		// ��ʼ����ѯ���飬ÿ��Ԫ�ص���ɫĬ��Ⱦ���Լ� 
		for (int i = 1; i <= len; i++) bin[i] = i; 
	}
	// ��ѯĳ��Ԫ�ص����Ȳ��� 
	int anc(int x) {
		// ����ҵ��˸�Ԫ�ص����ȣ����ؼ��� 
		if (bin[x] == x) return x;
		// ����������ϲ������ȣ�����bin[1] = 1, bin[2] = 1, bin[3] = 2;��������Ҫ��ѯ����3�����ȣ� 
		// ��ô��δ���ͻ��ȱȽ�bin[3]����ɫ�ǲ������Լ���������ǣ���bin[2]���ҵ�bin[2]����Ҳ����
		// ����������bin[1]����ʱ�����ҵ������Ƚڵ��� 
		anc(bin[x]);
	}
	// �ϲ�������ע�������������ͣ���Ȼ���ܱ��벻�� 
	void uni(int x, int y) {
		//��x��Ⱥ�˵���ɫȾ��y��Ⱥ�˵���ɫ 
		bin[anc(x)] = anc(y);
	} 
	// ���Ҳ���
	void ask(int x, int y) {
		// ��ѯx�������ǲ��Ǻ�y��������ͬ�������ͬ��˵������������ 
		if (anc(x) == anc(y)) cout << "Yes" << endl;
		else cout << "No" << endl;
	} 
	~ unionFind() {
		delete[] bin;
	}
}; 

int main() {
	int n, m, p;
	int x, y;
	cin >> n >> m >> p;
	// ����ռ��Լ���ʼ��Ⱦɫ 
	unionFind u(n);
	// �������ݹ�ϵ 
	while (m--) {
		cin >> x >> y;
		u.uni(x, y);
	}
	// ִ�в��Ҳ���
	while (p--) {
		cin >> x >> y;
		u.ask(x, y);
	} 
	return 0;
}
