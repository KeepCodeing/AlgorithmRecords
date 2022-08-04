#include <iostream>
using namespace std;

// ������Ծ�����trie�������

// ������xor����򣩵ĸ��10010 xor 10000 = 00010����������λ�ļӷ����㡱���ɴ˿��Կ���
// �����Ҫ��һ��������ԣ���������ĳ��������λ�ϵ�1 xor 0��ĳ��������λ�ϵ�0 xor 1 

const int N = 100010;
int son[N * 32][2], idx = 0;
int num[N];
void add(int x) {
	int p = 0;
	// �����ڵ� 
	for (int i = 30; ~i; i--) {
		// ȡ��x��ÿһλ�������� 
		int cur = x >> i & 1;
		if (!son[p][cur]) son[p][cur] = ++idx;
		p = son[p][cur];
	}
}
int query(int x) {
	int p = 0, res = 0;
	for (int i = 30; ~i; i--) {
		int cur = x >> i & 1;
		// �����һ���ڵ�͵�ǰ�ڵ�Ķ������෴����ѡ�񣬷���ֻ��ѡ����ͬ���� 
		if (son[p][!cur]) {
			// ��ԭ��һλ�ϵ����֣�����i = 3, 1����iλ�ͱ����1000��Ҳ����8
			res += 1 << i;
			p = son[p][!cur]; 
		} else {
			p = son[p][cur];
		}
	}
	return res;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> num[i], add(num[i]);
	int res = -1;
	for (int i = 0; i < n; i++) res = max(res, query(num[i]));
	cout << res;
	return 0;
}
