#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

// ��������ڶ�������һ�ε��Ѿ�׹����w�����о�����������ǰ׺�ͣ�Ȼ��ö��[i,n]�������Сֵ
// �ٴ�ǰ׺�������ȥ����ƽ��ֵ�����ģ�..
// ��׹����w�����ֵ��Сֵ������������Ӽ�������ô����״������Ȼ�����ٲ���
// ֻ�������ڵ����޸ģ�������͵�����... 

typedef long long LL;
const int N = 100000 + 10;
LL s[N];
int root[N], scores[N];
int n, temp;
int lowbit(int x) {
	return x & (-x);
}
// ��������ֵ��״���飬��֪��Ϊʲô׹����... 
void update(int idx) {
	while (idx <= n) {
		root[idx] = scores[idx];
		for (int i = 1; i < lowbit(idx); i <<= 1) root[idx] = min(root[idx], scores[idx - i]);
		idx += lowbit(idx);
	}
}
int query(int x, int y) {
	int ans = 1e9;
	while (y >= x) {
		ans = min(scores[y], ans), y--;
		for (; y - lowbit(y) >= x; y -= lowbit(y)) ans = min(root[y], ans);
	}
	return ans;
}
int main() {
	memset(root, 0x3f, sizeof root);
	scanf("%d", &n);
	s[0] = 0;
	for (int i = 1; i <= n; i++)  {
		scanf("%d", &scores[i]);
		s[i] = s[i - 1] + scores[i];
		update(i);
	}
	for (int i = 1; i <= n - 2; i++) cout << (1, i) << endl;
	return 0;
}
