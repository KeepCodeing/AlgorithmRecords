#include <iostream>
#include <cstdio>
using namespace std;

// ���鼯�ж���ͨ��������һ�����ͨ��bin[i] == i�ķ�ʽ���ж��ж��ٸ����ڵ㣬�ж��ٸ����ڵ����ζ���ж��ٿ�
// ���������ٸ���ͨ��...��������Ҳ��������������ͼ�ķ�ʽ��ͳ�ƣ�����һ��ʼ����N���㣬�Ǿ�����N����ͨ�飬ÿ
// ��ͨ����δ��ͨ�ĵ���ͨ��������-1�����ʣ�µ�ֵ������������������ˣ�������Ҳ��̫ȷ�����������������⣬
// ������ͨ��������...���������DFSȾɫҲ���ԣ����Ҹ���... 

const int N = 1000 + 10;
struct unionFind {
	int bin[N];
	void _init() {
		for (int i = 0; i < N; i++) bin[i] = i;
	}
	int anc(int x) {
		if (x != bin[x]) bin[x] = anc(bin[x]);
		return bin[x];
	}
	void uni(int x, int y) {
		if (ask(x, y)) return;
		bin[anc(x)] = y;
	}
	bool ask(int x, int y) {
		return anc(x) == anc(y);
	}
	int getcnt(int n) {
		int cnt = 0;
		// ����д��bin[i] == i��������ʽ��AC�ˣ�ʵ��̫�����ˣ���һ��������ˣ������ַ����ƺ�û�������Ǿ�ͳһ����������... 
		for (int i = 1; i <= n; i++) cnt += anc(i) == i;
		return cnt;
	}
};
unionFind uf;
int main() {
	int T, n, m, ut, vt;
	scanf("%d", &T);
	while (T--) {
		uf._init();
		scanf("%d%d", &n, &m);
		while (m--) {
			scanf("%d%d", &ut, &vt);
			uf.uni(ut, vt); 
		}
		printf("%d\n", uf.getcnt(n));
	}
	return 0;
}
