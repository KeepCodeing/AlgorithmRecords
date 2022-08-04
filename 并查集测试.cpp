#include <iostream>
#include <cstdio>
using namespace std;

// �����������ڲ����ڵĹ���������·���ϵĽڵ�ģ���������Լ�д��·��ѹ����
// Ҫ��������д�Ͳ���д·��ѹ����Ҳ����ÿ�ζ���n�ĸ��Ӷȣ����������Ǳ�����..
// Ҳ�벻���Ǹ����������ʲô����֮�������İ����ⶼ����ôһ��... 

const int N = 5000 + 10;
struct unionFind {
	int bin[N];
	unionFind() {
		for (int i = 0; i < N; i++) bin[i] = i;
	}
	int anc(int x, bool f) {
		if (x != bin[x]) bin[x] = anc(bin[x], f);
		if (f) printf("%d\n", bin[x]);
		return bin[x];
	}
	void uni(int x, int y) {
		int a = anc(x, false), b = anc(y, false);
		if (a != b) bin[a] = b;
	}
	bool ask(int x, int y) {
		return anc(x, true) == anc(y, true);
	}
};
int main() {
	int n, m, p, ut, vt;
	scanf("%d%d%d", &n, &m, &p);
	unionFind uf;
	while (m--) {
		scanf("%d%d", &ut, &vt);
		uf.uni(ut, vt); 
	}
	while (p--) {
		scanf("%d%d", &ut, &vt);
		if (uf.ask(ut, vt)) puts("Yes");
		else puts("No");
		break;
	}
	return 0;
}
