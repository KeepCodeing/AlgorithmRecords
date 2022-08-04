#include <iostream>
#include <cstdio>
using namespace std;

// һ�����鼯�󷴼�����Ŀ������������vjudge����һ����һ�������������Ҫ���ж��ٸ��Ż��ͨ���鼯ͳ����ͨ���
// ���������ж��ж��ٸ�Ԫ�صĸ������Լ��������Ҳ��������������Ȼ���Ǻ�����Ϊʲô...����������⻹���˸�ֱ��
// �ϲ���Ҳ���ǲ��󷴼�.. 

const int N = 1000 * 2 + 10;
char op[5];
struct unionFind {
	int bin[N];
	unionFind () {
		for (int i = 0; i < N; i++) bin[i] = i;
	}
	int anc(int x) {
		if (x != bin[x]) bin[x] = anc(bin[x]);
		return bin[x];
	}
	void uni(int x, int y) {
		// �����������д������ᱬջ 
		if (anc(x) != anc(y)) bin[anc(x)] = y;
	}
	bool ask(int x, int y) {
		return anc(x) == anc(y);
	}
	int getAns(int n) {
		int cnt = 0;
		for (int i = 1; i <= n; i++) cnt += bin[i] == i;
		return cnt;
	}
};
unionFind u;
int main() {
	int n, m, x, y;
	scanf("%d%d", &n, &m);
	while (m--) {
		scanf("%s%d%d", &op, &x, &y);
		// �󷴼���ע�������vjudge�ϵ�д����ͬ���ǽ����ܵļ�����Ԫ��ͳһ���ߵ������⣬��vjudge�������෴��
		// �������������д�ͻ�WA�����������vjudge��д��Ҳ�ܹ�������ͳһ�����д������... 
		if (*op == 'E') u.uni(y + n, x), u.uni(x + n, y); 
		// �ϲ�����
		else u.uni(x, y); 
	}
	printf("%d", u.getAns(n));
	return 0;
}
