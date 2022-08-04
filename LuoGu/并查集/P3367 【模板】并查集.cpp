#include <iostream>
using namespace std;

// ���������д���鼯...����������ϰ������ӡ�������Ͳ�����һ�����ˣ��������Ҫ·��ѹ��
// ��Ȼ���д���鼯��ʱ��ͼ���·��ѹ������ΪҲ��һ�д��� 

struct unionFind {
	int *bin;
	unionFind(int len) {
		bin = new int[len + 1];
		for (int i = 1; i <= len; i++) bin[i] = i;
	}
	int anc(int x) {
		if (bin[x] == x) return x;
		bin[x] = anc(bin[x]);
		return bin[x];
	}
	void uni(int x, int y) {
		bin[anc(x)] = anc(y);
	}
	void ask(int x, int y) {
		if (anc(x) == anc(y)) cout << "Y" << endl;
		else cout << "N" << endl;
	} 
	~ unionFind() {
		delete[] bin;
	}
};

int main() {
	int n, m;
	int x, y, z;
	cin >> n >> m;
	unionFind u(n);
	while(m--) {
		cin >> z >> x >> y;
		if (z == 1) u.uni(x, y);
		else u.ask(x, y);  
	}
	
	return 0;
}
