#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// ���ȿ�������������Ҫ��1. �����ڻ�  2. �ܻ�����С
// ����1.���ԣ���������һ�������ڻ��ģ�Ҳ����˵���ǽ�������
// ���Ĺ��̾��ǰ�����ͼ�ع���һ�飬ͬʱɾȥ��һЩ�ߣ�����Щ
// �߾���Ȩֵ�ϴ�ıߣ�Ҳ����˵����������Ҳһ������2. 

// Ȼ�����沢û�п������Ŀ����Ŀ��Ҫ����ȥ���ı�Ȩ�������ô������һ�£�����������ı�Ȩ����С��
// ���ܱ�Ȩ��ȥ�������ı�Ȩ�ͣ����ɱ�֤ȥ���ı�Ȩ�����

// �ܵ���˵����⿼������С���������޻�����Ȩ����С�����ʣ�����ԭ���Ļ����ϻ��˸�˵������������ȥ����
// �ı�Ȩ���...

// ����Ҫע���ȨΪ0�����������ζ���������㲻���������ж��±�Ȩ�Ƿ�Ϊ0���������Ƿ�ӱ߾��� 

// ���Ա������·����С�����������·Ҫ�����һ�����߶����㵽ĳ���յ㣨���ܻ��ж���յ㣬����Ҫ����Դ��������
// ����̾��룬����С������һ����Ҫ����ȥ��ĳЩ�ߣ�ʹ������ͼ�޻�ȫ��ͨ�ұ�Ȩ����С 

const int N = 100 * 10 + 10;
struct net {
	int u, v, w;
	bool operator<(const net& n) {
		return w < n.w;
	}
} nt[N];
struct unionFind {
	int bin[N];
	unionFind() {
		for (int i = 0; i < N; i++) bin[i] = i;
	};
	int anc(int x) {
		if (x != bin[x]) bin[x] = anc(bin[x]);
		return bin[x];
	}
	void uni(int x, int y) {
		bin[anc(x)] = anc(y);
	}
	bool ask(int x, int y) {
		return anc(x) == anc(y);
	}
};
unionFind u;
int main() {
	int n, k, ut, vt, wt, cnt = 0, tot = 0;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < k; i++) {
		scanf("%d%d%d", &ut, &vt, &wt);
		// ��ȨΪ0�����ڱߣ������ӱ� 
		if (!wt) continue;
		nt[cnt].u = ut, nt[cnt].v = vt, nt[cnt].w = wt, tot += wt, cnt++;
	}
	sort(nt, nt + k);
	int res = 0;
	// ������С�������㷨�õ��ļ�С��ͨ����һ�����޻���ȫ��ͨ���ұ�Ȩ����С�� 
	for (int i = 0; i < k; i++) {
		if (!u.ask(nt[i].u, nt[i].v)) {
			u.uni(nt[i].u, nt[i].v);
			res += nt[i].w;
		}
	}
	// ����ܱ�Ȩ��ȥʣ�µ���С��Ȩ�;�������ȥ���ı�Ȩ�� 
	printf("%d", tot - res);
	return 0;
}
