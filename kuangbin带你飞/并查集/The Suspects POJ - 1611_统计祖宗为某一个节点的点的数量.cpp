#include <iostream>
#include <cstdio>
using namespace std;

// һ��ʼûʲô˼·�����ӣ���Ϊ����������ν�����壬�����¿�������ÿ�����������Ϊ���һ���ˣ�֮ǰ����Ƕ�����
// ��������Ȼ������С�ı�ŵ�����Ϊ���ڣ��������ܱ�֤0һ����ĳ����������ڣ����ǲ�������̫��TLE���ɱܣ�����ô
// ���¶���0��������������һ��������м��������������һ�����������Ϊ�����������ȣ�����һ������������������
// һ���ڵ㡣���������Ŀ���ԣ� ��Ҫ�����ʵ����0��������ڵ��������ж��ٸ��ڵ㡣���ڲ��鼯��ͳ������Ľڵ���ֻ��
// �ж�ÿ���ڵ��������˭�����ˡ������������������ʵ��������һ��������Ǿ���ͳ���ж��ٸ��ڵ�����Ⱥ�0��������ͬ��
// �˼�Ϊ��Ҫ������˵�����... 

// �ò�����AC�ˣ���Ȼ�뷨���������ǶԵģ��������ǳ���������֮��Ĵ���...�ǵ��ж���ͨ������ж�bin[i] == i����i�ǲ���
// ���Ⱦ�����...���ǿ���POJ�Ƚ����Ҫ��anc(i)�������ӡ��������Ҳ֤���������Ǹ�˵��û����... 

const int N = 3e4 + 10;
int bin[N];
struct unionFind {
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
	int getcnt(int x, int n) {
//		for (int i = 1; i <= n; i++) {
//			cout << bin[i] << ' ' << anc(i) << ' ' << i << endl;
//		} 
		int cnt = 0;
		// ������ԣ�����д��bin[i] == x���ˣ�������������������·��ѹ��������˵bin[i]��Ӧ�õ���anc(i)�ˣ���ʵ��
		// ����Ҳȷʵ��ˣ����Ұ����㷨�����ͳ����ͨ������Ҳ��bin[i]==i�����ּ��󶼱���bin[i] == anc(i)����bin[i]
		// ����i�����ڽڵ�ı��...��̫����w����������ͳһ�£��������ͨ�������д����... 
		for (int i = 1; i <= n; i++) cnt += anc(i) == x;
		return cnt;
	}
}; 
unionFind uf;
int main() {
	int n, m, team, v, isfirst;
	while (true) {
		scanf("%d%d", &n, &m);
		if (!n && !m) break;
		uf._init();
		while (m--) {
			isfirst = -1;
			scanf("%d", &team);
			while (team--) {
				scanf("%d", &v);
				if (isfirst == -1) isfirst = v;
				else uf.uni(isfirst, v);
			}
		}
		// cout << bin[0] << ' ' << uf.anc(0) << endl; 
		// ע�������+1����Ϊ����ͳ�Ƶ�ʱ���Ǵ�1��ʼ��,��0Ҳ���Լ����Ǹ�Ⱦ��.. 
		printf("%d\n", uf.getcnt(uf.anc(0), n) + 1);
	}
	return 0;
}
