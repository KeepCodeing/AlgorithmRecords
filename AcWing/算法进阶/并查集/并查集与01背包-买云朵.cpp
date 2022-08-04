#include <iostream>
using namespace std;

// ��Ŀ����˼��Ҫ��һ���ƶ䣬�͵ð����к�����ƶ�һ�����ϵ��ƶ䶼����
// ������ǰ��ƶ伯�Ͽ���һ���ƶ䣬��ô����Ǹ�01���������� 
// ����Ϊ�˼�¼ÿ�����ϵ��ܼ�ֵ������������Ҫ����Щ���ݰ󶨵����ڵ��� 

const int N = 10010;
int v[N], w[N];
int bin[N];
int f[N];
struct unionFind {
	unionFind() {for (int i = 1; i <= N; i++) bin[i] = i;}
	int anc(int x) {
		if (x != bin[x]) bin[x] = anc(bin[x]);
		return bin[x];
	}
	void uni(int x, int y) {bin[anc(x)] = anc(y);} 
	bool ask(int x, int y) {return anc(x) == anc(y);}
};
unionFind u; 
int main() {
	int n, m, money;
	cin >> n >> m >> money;
	// ��������Ǽ�ֵ��������������� 
	for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
	while (m--) {
		int x, y;
		cin >> x >> y;
		int ax = u.anc(x) , ay = u.anc(y);
		// ��Ϊ���ܴ���������ͬ������������Ǻϲ���ʱ�����м�ֵ�󶨵Ȳ�����������ж�������
		// �Ƿ���ͬ�ͻ����ͬһ�����ڵļ�ֵ�������ε���� 
		if (ax != ay) {
			// ��x�ļ۸������󶨵���ay�� 
			w[ay] += w[ax];
			v[ay] += v[ax];
			// ��x������ָ��y 
			u.uni(x, y);  
		} 
	}
	// ��ʼ01����
	for (int i = 1; i <= n; i++) {
		// ֻ��ÿ�����弯�ϵļ�ֵ 
		if (bin[i] == i) {
			for (int j = money; j >= v[i]; j--) {
				f[j] = max(f[j], f[j - v[i]] + w[i]);
			}
		}
	} 
	cout << f[money];
	return 0;
}

/*
����������
5 3 10
3 10
3 10
3 10
5 100
10 1
1 3
3 2
4 2

���������
1
*/
