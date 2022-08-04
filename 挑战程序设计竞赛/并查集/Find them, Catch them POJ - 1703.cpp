#include <iostream>
#include <cstdio>
using namespace std;

// һ����������⣬����ⲻ�Ǻ���ͨ���鼯һ����������Ȼ��������������ߣ� ����˵�������㣬��������û�й�ϵ����������
// �㲻�����ߣ�����ô�ܹ��뵽��˼·�����������鼯��������������������ͬ���ڵ����ߵ����������������ͼ������ȫ�����С�
// �ڶ���˼·�ǽ���Щ�㶼����һ����������ȫû�й�ϵ�ĵ��ϣ���Ӧ�������ߡ�Ȼ������뷨����̫naive�Ҳ����ƣ���ȷ��˼·
// ����һ�����鼯ά���������ϣ���uni(a, b + n)��ʾa��b����һ�����ϣ���Ϊb+n�Ǹ������ڵĵ㣬Ȼ����(a + n, b)��ʾb��a
// ����һ�����ϣ�ԭ��ͬ�ϣ��������ܶ�Ӧǰ���Ǹ���ν�������鼯���뷨�ˣ�����������ۡ���ô������ô��ѯ�أ����ǿ�����
// ask(a, b)ѯ��a��b�Ƿ���һ�������Ȼ����ask(a, b + n)ѯ��a, b�ǲ��ǲ���һ���������ô����������������������
// ��������Ϊa��b�������㻹û�б��ӵ���ͨ�����a��b�ļ��ϲ�ȷ����
// �����������cin��TLE�����Ե���scanf.. 

// ע������ĳ˶�����Ϊ��Ҫ��ʾ�㲻���ڵ���� 
const int N = (100000 + 10) * 2;
char op[5];
int bin[N];
struct unionFind {
	int anc(int x) {
		if (x != bin[x]) bin[x] = anc(bin[x]);
		return bin[x];
	}
	void uni(int x, int y) {
		// ע����������ж����������ڲ���һ����ͨ�飬��Ȼ�ᱬջMLE 
		int a = anc(x);
		int b = anc(y);
		if (a != b) bin[a] = b;
		
	}
	bool ask(int x, int y) {
		return anc(x) == anc(y);
	}
};
void init_bin () {
	for (int i = 0; i < N; i++) bin[i] = i;
}
int main() {
	int T;
	scanf("%d", &T);
	unionFind u;
	while (T--) {
		int n, m, x, y;
		scanf("%d%d", &n, &m);
		init_bin();
		for(int i = 0; i < m; i++) {
			scanf("%s%d%d", op, &x, &y);
			if (*op == 'A') {
				// ���x��y��һ�������� 
				if (u.ask(x, y)) printf("In the same gang.\n");
				// ���x��y����һ�������� 
				else if (u.ask(x, y + n) || u.ask(x + n, y)) printf("In different gangs.\n");
				// x����y��û�г��ֹ������ǽ����ȷ�� 
				else printf("Not sure yet.\n");
			} else {
				// ��x��y���벻ͬ����
				u.uni(y + n, x);
				// ��y��x���벻ͬ����
				u.uni(x  + n, y);  
			}
		}
	}
	return 0;
}
